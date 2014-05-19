/*
 * NodeIDSet.h
 *
 *  Created on: Apr 24, 2014
 *      Author: cmaier
 */

#ifndef NODEDOMAINSTRINGELEMENTS_H_
#define NODEDOMAINSTRINGELEMENTS_H_

#include<vector>
#include<numeric>

#include "ASTNodeBase.h"
#include "NodeID.h"

class NodeDomainStringElements: public ASTNodeBase
{
private:
    std::vector<std::string> domainElements_;

public:
    NodeDomainStringElements() {}

    void addStringToDomain(std::string domainElement)
    {
        domainElements_.push_back(domainElement);
    }

    virtual ~NodeDomainStringElements();

    virtual std::string toString()
    {

      auto ret = std::accumulate(std::begin(domainElements_), std::end(domainElements_),
        std::string{"{"}, [](std::string& foo, const std::string& bar) {return foo + bar + ",";});

      ret.pop_back();
      ret += "}";

      return ret;
//
//        bool first = true;
//        for (const auto& id : idNodes_)
//        {
//            if (!first) ret += "," + id->toString();
//            else
//            {
//                ret += id->toString();
//                first = false;
//            }
//        }
//
//        return ret += "}";
    }
};

#endif /* NODEDOMAINSTRINGELEMENTS_H_ */