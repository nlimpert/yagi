/*
 * NodeFormulaConnective.cpp
 *
 *  Created on: May 30, 2014
 *      Author: cmaier
 */

#include "NodeFormulaConnective.h"

NodeFormulaConnective::NodeFormulaConnective() :
    formulaConnective_(FormulaConnective::Unknown)
{
}

NodeFormulaConnective::~NodeFormulaConnective()
{
}

void NodeFormulaConnective::fromString(const std::string& connString)
{
  if (connString == "&&")
    formulaConnective_ = FormulaConnective::And;
  else if (connString == "||")
    formulaConnective_ = FormulaConnective::Or;
  else if (connString == "->")
    formulaConnective_ = FormulaConnective::Implies;
  else
    throw std::runtime_error("Invalid formula connective string '" + connString + "'!");
}

std::string NodeFormulaConnective::toString()
{
  if (formulaConnective_ == FormulaConnective::And)
    return "&&";
  else if (formulaConnective_ == FormulaConnective::Or)
    return "||";
  else if (formulaConnective_ == FormulaConnective::Implies)
    return "->";
  else
    throw std::runtime_error("Unknown formula connective!");

}
