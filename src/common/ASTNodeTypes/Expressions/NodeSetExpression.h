/*
 * NodeSetExpression.h
 *
 *  Created on: May 27, 2014
 *      Author: cmaier
 */

#ifndef NODESETEXPRESSION_H_
#define NODESETEXPRESSION_H_

#include "../ASTNodeBase.h"
#include "NodeExpressionOperator.h"
#include "../../ASTNodeTypes/Identifier/NodeID.h"
#include "../../ASTNodeTypes/Set/NodeSet.h"

#include <memory>

class NodeSetExpression: public ASTNodeBase<>
{
  private:
    std::shared_ptr<NodeExpressionOperator> operator_;
    std::shared_ptr<ASTNodeBase<>> lhs_;
    std::shared_ptr<ASTNodeBase<>> rhs_;

  public:
    DEFINE_VISITABLE()
    NodeSetExpression();
    virtual ~NodeSetExpression();

    static bool isPassedTypeValid(const std::shared_ptr<ASTNodeBase<>>& valueToAssign);

    const std::shared_ptr<ASTNodeBase<>>& getLhs() const
    {
      return lhs_;
    }

    void setLhs(const std::shared_ptr<ASTNodeBase<>>& lhs)
    {
      if (isPassedTypeValid(lhs))
        this->lhs_ = lhs;
      else
        throw std::runtime_error("Invalid Type passed to SetExpression (lhs)!");
    }

    const std::shared_ptr<NodeExpressionOperator>& getOperator() const
    {
      return operator_;
    }

    void setOperator(const std::shared_ptr<NodeExpressionOperator>& _operator)
    {
      operator_ = _operator;
    }

    const std::shared_ptr<ASTNodeBase<>>& getRhs() const
    {
      return rhs_;
    }

    void setRhs(const std::shared_ptr<ASTNodeBase<>>& rhs)
    {
      if (isPassedTypeValid(rhs))
        this->rhs_ = rhs;
      else
        throw std::runtime_error("Invalid Type passed to SetExpression (rhs)!");
    }
};

#endif /* NODESETEXPRESSION_H_ */
