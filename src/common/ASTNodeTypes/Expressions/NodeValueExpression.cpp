/*
 * ValueExpression.cpp
 *
 *  Created on: May 26, 2014
 *      Author: cmaier
 */

#include "NodeValueExpression.h"

NodeValueExpression::NodeValueExpression() :
    operator_(nullptr), lhs_(nullptr), rhs_(nullptr)
{
}

NodeValueExpression::~NodeValueExpression()
{

}

bool NodeValueExpression::isPassedTypeValid(const std::shared_ptr<ASTNodeBase<>>& valueToAssign)
{
  //type must be either String, Variable or NodeValueExpression
  auto stringVal = std::dynamic_pointer_cast<NodeString>(valueToAssign);
  if (stringVal != nullptr)
    return true;

  auto var = std::dynamic_pointer_cast<NodeVariable>(valueToAssign);
  if (var != nullptr)
    return true;

  auto valExpr = std::dynamic_pointer_cast<NodeValueExpression>(valueToAssign);
  if (valExpr != nullptr)
    return true;

  return false;
}

