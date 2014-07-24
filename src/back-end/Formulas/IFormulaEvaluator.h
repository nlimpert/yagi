/*
 * IFormulaEvaluator.h
 *
 *  Created on: Jul 17, 2014
 *      Author: cmaier
 */

#ifndef IFORMULAEVALUATOR_H_
#define IFORMULAEVALUATOR_H_

#include "../../common/ASTNodeTypes/Formula/NodeConstant.h"
#include "../../common/ASTNodeTypes/Formula/NodeAtom.h"
#include "../../common/ASTNodeTypes/Formula/NodeNegation.h"
#include "../../common/ASTNodeTypes/Formula/NodeCompoundFormula.h"
#include "../../common/ASTNodeTypes/Formula/NodeQuantifiedFormula.h"
#include "../../common/ASTNodeTypes/Formula/NodeOperatorIn.h"
#include <memory>

namespace yagi {
namespace formula {

class IFormulaEvaluator
{
  protected:
    bool printFormulaEvaluationResults_;
    ASTNodeVisitorBase* ctx_;

  public:
    IFormulaEvaluator();
    IFormulaEvaluator(ASTNodeVisitorBase* ctx);
    virtual ~IFormulaEvaluator();

    void setContext(ASTNodeVisitorBase* ctx)
    {
      ctx_ = ctx;
    }

    virtual bool evaluateConstant(NodeConstant* constant) = 0;
    virtual bool evaluateAtom(NodeAtom* atom) = 0;
    virtual bool evaluateNegation(NodeNegation* negation) = 0;
    virtual bool evaluateCompoundFormula(NodeCompoundFormula* compoundFormula) = 0;
    virtual bool evaluateQuantifiedFormula(NodeQuantifiedFormula* quantifiedFormula) = 0;
    virtual bool evaluateInFormula(NodeOperatorIn* inFormula) = 0;
};

} /* namespace formula */
} /* namespace yagi */

#endif /* IFORMULAEVALUATOR_H_ */
