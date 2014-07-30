/*
 * MainInterpretationVisitor.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: cmaier
 */

#include "MainInterpretationVisitor.h"

namespace yagi {
namespace execution {

MainInterpretationVisitor::MainInterpretationVisitor()
{

}

MainInterpretationVisitor::~MainInterpretationVisitor()
{

}

Any MainInterpretationVisitor::visit(NodeID& id)
{
  ActionProcedureInterpretationVisitor v;
  return v.visit(id);
}

Any MainInterpretationVisitor::visit(NodeProgram& program)
{
  std::for_each(program.getProgram().begin(), program.getProgram().end(),
      [this](std::shared_ptr<ASTNodeBase<>> stmt)
      {
        //safety net to check if only valid YAGI lines and not any
        //garbage resulting from a bug is considered a line...
        if (!TypeOk(stmt))
        {
          throw std::runtime_error("Invalid node type left on program-level of AST in InterpretationVisitor!");
        }

        stmt->accept(*this);
      });

  return Any { };
}

Any MainInterpretationVisitor::visit(NodeFluentDecl& fluentDecl)
{
  ActionProcedureInterpretationVisitor v(DatabaseManager::getInstance().getMainDB());
  return v.visit(fluentDecl);
}

Any MainInterpretationVisitor::visit(NodeFactDecl& factDecl)
{
  auto db = DatabaseManager::getInstance().getMainDB();
  auto tableName = factDecl.getFactName()->accept(*this).get<std::string>();

  db->executeNonQuery(
      SQLGenerator::getInstance().getSqlStringCreateTable(tableName, factDecl.getDomains().size()));

  //store in db that it is a fact
  if (!db->executeQuery(
      SQLGenerator::getInstance().getSqlStringExistsTable(
          SQLGenerator::getInstance().FACTS_TABLE_NAME_)).size())
  {
    db->executeNonQuery(SQLGenerator::getInstance().getSqlStringCreateFactsTable());
  }
  db->executeNonQuery(SQLGenerator::getInstance().getSqlStringAddFact(factDecl));

  return Any { };
}

Any MainInterpretationVisitor::visit(NodeFluentQuery& fluentQuery)
{
  auto db = DatabaseManager::getInstance().getMainDB();
  auto fluentName = fluentQuery.getFluentToQueryName()->accept(*this).get<std::string>();

  if (!db->executeQuery(SQLGenerator::getInstance().getSqlStringExistsTable(fluentName)).size())
  {
    std::cout << ">>>> Fluent/Fact '" + fluentName + "' does not exist!" << std::endl;
  }
  else
  {
    auto fluentState = db->executeQuery(
        SQLGenerator::getInstance().getSqlStringSelectAll(fluentName));
    auto str = yagi::fluentDBDataToString(fluentState);

    std::cout << ">>>> " << fluentName << " = " << str << std::endl;
  }

  return Any { };
}

Any MainInterpretationVisitor::visit(NodeIDAssignment& idAssign)
{
  ActionProcedureInterpretationVisitor v(DatabaseManager::getInstance().getMainDB());
  return v.visit(idAssign);
}

Any MainInterpretationVisitor::visit(NodeActionDecl& actionDecl)
{
  ExecutableElementsContainer::getInstance().addOrReplaceAction(actionDecl);
  return Any { };
}

Any MainInterpretationVisitor::visit(NodeProcDecl& procDecl)
{
  ExecutableElementsContainer::getInstance().addOrReplaceProcedure(procDecl);
  return Any { };
}

Any MainInterpretationVisitor::visit(NodeProcExecution& procExec)
{
  ActionProcedureInterpretationVisitor v(std::make_shared<yagi::formula::FormulaEvaluator>(),
      DatabaseManager::getInstance().getMainDB(), std::make_shared<CoutCinSignalHandler>());

  return Any { v.visit(procExec) };
}

Any MainInterpretationVisitor::visit(NodeSet& set)
{
  ActionProcedureInterpretationVisitor v;
  return v.visit(set);
}

Any MainInterpretationVisitor::visit(NodeTuple& tuple)
{
  ActionProcedureInterpretationVisitor v;
  return v.visit(tuple);
}

Any MainInterpretationVisitor::visit(NodeVariable& variable)
{
  ActionProcedureInterpretationVisitor apiv;
  return apiv.visit(variable);
}

Any MainInterpretationVisitor::visit(NodeVariableAssignment& varAss)
{
  ActionProcedureInterpretationVisitor apiv;
  return apiv.visit(varAss);
}

Any MainInterpretationVisitor::visit(NodeString& str)
{
  ActionProcedureInterpretationVisitor apiv;
  return apiv.visit(str);
}

Any MainInterpretationVisitor::visit(NodeSetExpression& setExpr)
{
  ActionProcedureInterpretationVisitor v;
  return v.visit(setExpr);
}

Any MainInterpretationVisitor::visit(NodeForLoop& forLoop)
{
  ActionProcedureInterpretationVisitor v(std::make_shared<yagi::formula::FormulaEvaluator>(),
      DatabaseManager::getInstance().getMainDB(), std::make_shared<CoutCinSignalHandler>());
  return v.visit(forLoop);
}

Any MainInterpretationVisitor::visit(NodeConditional& conditional)
{
  ActionProcedureInterpretationVisitor v(std::make_shared<yagi::formula::FormulaEvaluator>(),
      DatabaseManager::getInstance().getMainDB(), std::make_shared<CoutCinSignalHandler>());
  return v.visit(conditional);

}

}/* namespace execution */
} /* namespace yagi */
