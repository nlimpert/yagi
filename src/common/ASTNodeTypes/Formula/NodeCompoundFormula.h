/*
 * NodeCompoundFormula.h
 *
 *  Created on: May 30, 2014
 *      Author: cmaier
 */

#ifndef NODECOMPOUNDFORMULA_H_
#define NODECOMPOUNDFORMULA_H_

#include <memory>

#include "NodeFormulaBase.h"
#include "NodeAtom.h"
#include "NodeFormulaConnective.h"

class NodeCompoundFormula: public NodeFormulaBase
{
  private:
    std::shared_ptr<NodeAtom> leftOperand_;
    std::shared_ptr<NodeFormulaConnective> connective_;
    std::shared_ptr<NodeFormulaBase> rightOperand_;

  public:
    NodeCompoundFormula();
    virtual ~NodeCompoundFormula();

    const std::shared_ptr<NodeFormulaConnective>& getConnective() const
    {
      return connective_;
    }

    void setConnective(const std::shared_ptr<NodeFormulaConnective>& connective)
    {
      connective_ = connective;
    }

    const std::shared_ptr<NodeAtom>& getLeftOperand() const
    {
      return leftOperand_;
    }

    void setLeftOperand(const std::shared_ptr<NodeAtom>& leftOperand)
    {
      leftOperand_ = leftOperand;
    }

    const std::shared_ptr<NodeFormulaBase>& getRightOperand() const
    {
      return rightOperand_;
    }

    void setRightOperand(const std::shared_ptr<NodeFormulaBase>& rightOperand)
    {
      rightOperand_ = rightOperand;
    }

    virtual void accept(ASTNodeVisitorBase* visitor) override
    {
      //TODO: implement this
      //visitor->visit(this);
    }
};

#endif /* NODECOMPOUNDFORMULA_H_ */