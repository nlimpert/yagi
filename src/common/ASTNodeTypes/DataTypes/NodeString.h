/*
 * NodeString.h
 *
 *  Created on: May 22, 2014
 *      Author: cmaier
 */

#ifndef NODESTRING_H_
#define NODESTRING_H_

#include<string>

#include "../ASTNodeBase.h"

class NodeString: public ASTNodeBase
{
  private:
    std::string string_;

  public:
    NodeString();
    virtual ~NodeString();

    virtual void accept(ASTNodeVisitorBase* visitor) override
    {
      visitor->visit(this);
    }

    const std::string& getString() const
    {
      return string_;
    }

    void setString(const std::string& string)
    {
      string_ = string;
    }
};

#endif /* NODESTRING_H_ */