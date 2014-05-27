/*
 * NodeIDSet.h
 *
 *  Created on: Apr 24, 2014
 *      Author: cmaier
 */

#ifndef NODEDOMAINSTRINGELEMENTS_H_
#define NODEDOMAINSTRINGELEMENTS_H_

#include<vector>
#include<algorithm>
#include <memory>

#include "../Identifier/NodeID.h"
#include "../DataTypes/NodeString.h"
#include "../Domains/NodeDomainBase.h"

class NodeDomainStringElements: public NodeDomainBase
{
  private:
    std::vector<std::shared_ptr<NodeString>> domainElements_;

  public:
    NodeDomainStringElements()
    {
    }
    virtual ~NodeDomainStringElements();

    void addStringToDomain(std::shared_ptr<NodeString> domainElement)
    {
      domainElements_.push_back(domainElement);
    }

    virtual void accept(ASTNodeVisitorBase* visitor) override
    {
      visitor->visit(this);

      std::for_each(std::begin(domainElements_), std::end(domainElements_),
          [&visitor](std::shared_ptr<NodeString> str)
          { str->accept(visitor);});
    }
};

#endif /* NODEDOMAINSTRINGELEMENTS_H_ */