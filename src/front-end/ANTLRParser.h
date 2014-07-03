/*
 * ANTLRParser.h
 *
 *  Created on: Jul 2, 2014
 *      Author: cmaier
 */

#ifndef ANTLRPARSER_H_
#define ANTLRPARSER_H_

#include <memory>
#include <string>

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <streambuf>

#include "../common/ASTNodeTypes/ASTNodeBase.h"
#include "autoGenerated/YAGILexer.h"
#include "autoGenerated/YAGIParser.h"
#include "autoGenerated/YAGITreeWalker.h"
#include "astClasses/ASTBuilder.h"

class ANTLRParser
{
  private:
    ANTLRParser();
    virtual ~ANTLRParser();
    static std::shared_ptr<ASTNodeBase<>> parse(const pANTLR3_INPUT_STREAM& input);

  public:
    static std::shared_ptr<ASTNodeBase<>> parseYAGICodeFromText(const std::string& yagiCode);
    static std::shared_ptr<ASTNodeBase<>> parseYAGICodeFromFile(const std::string& file);
};

#endif /* ANTLRPARSER_H_ */