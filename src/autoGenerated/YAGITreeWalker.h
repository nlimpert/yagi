/** \file
 *  This C header file was generated by $ANTLR version 3.5.2
 *
 *     -  From the grammar source file : ./src/grammar/YAGITreeWalker.g
 *     -                            On : 2014-05-19 16:17:49
 *     -           for the tree parser : YAGITreeWalkerTreeParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The tree parser 
YAGITreeWalker

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pYAGITreeWalker, which is returned from a call to YAGITreeWalkerNew().
 *
 * The methods in pYAGITreeWalker are  as follows:
 *
 *  - 
 void
      pYAGITreeWalker->program(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->block(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->declaration(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->fluent_decl(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->fact_decl(pYAGITreeWalker)
 *  - 
 YAGITreeWalker_domain_return
      pYAGITreeWalker->domain(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->action_decl(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->effect(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->active_sensing(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->var_list(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->proc_decl(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->passive_sensing_decl(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->assignment(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->statement(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->action_exec(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->value_list(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->test(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->choose(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->pick(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->for_loop(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->conditional(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->while_loop(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->search(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->assign(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->ass_op(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->for_loop_assign(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->conditional_assign(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->formula_outerMost(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->formula(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->formular_connective(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->atom(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->atom_connector(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->set(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->setexpr(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->tuple(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->tuple_val(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->var(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->value(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->valexpr(pYAGITreeWalker)
 *  - 
 void
      pYAGITreeWalker->expr_op(pYAGITreeWalker)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_YAGITreeWalker_H
#define _YAGITreeWalker_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct YAGITreeWalker_Ctx_struct YAGITreeWalker, * pYAGITreeWalker;



    #include "../cppInterfaceClasses/CToCppBridge.h"


#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif
typedef struct YAGITreeWalker_domain_return_struct
{
    pANTLR3_BASE_TREE       start;
    pANTLR3_BASE_TREE       stop;
}
    YAGITreeWalker_domain_return;





/** Context tracking structure for 
YAGITreeWalker

 */
struct YAGITreeWalker_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_TREE_PARSER	    pTreeParser;


     void
     (*program)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*block)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*declaration)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*fluent_decl)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*fact_decl)	(struct YAGITreeWalker_Ctx_struct * ctx);

     YAGITreeWalker_domain_return
     (*domain)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*action_decl)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*effect)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*active_sensing)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*var_list)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*proc_decl)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*passive_sensing_decl)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*assignment)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*statement)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*action_exec)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*value_list)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*test)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*choose)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*pick)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*for_loop)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*conditional)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*while_loop)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*search)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*assign)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*ass_op)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*for_loop_assign)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*conditional_assign)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*formula_outerMost)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*formula)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*formular_connective)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*atom)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*atom_connector)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*set)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*setexpr)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*tuple)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*tuple_val)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*var)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*value)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*valexpr)	(struct YAGITreeWalker_Ctx_struct * ctx);

     void
     (*expr_op)	(struct YAGITreeWalker_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct YAGITreeWalker_Ctx_struct * ctx);
    void	    (*free)   (struct YAGITreeWalker_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pYAGITreeWalker YAGITreeWalkerNew         (
pANTLR3_COMMON_TREE_NODE_STREAM
 instream);
ANTLR3_API pYAGITreeWalker YAGITreeWalkerNewSSD      (
pANTLR3_COMMON_TREE_NODE_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
tree parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define COMMENT      4
#define ID      5
#define INT      6
#define IT_ACTION_DECL      7
#define IT_ACTION_EXEC      8
#define IT_ADD_ASSIGN      9
#define IT_ALL      10
#define IT_AND      11
#define IT_ASSIGN      12
#define IT_ASSIGN_ALL      13
#define IT_BLOCK      14
#define IT_CHOOSE      15
#define IT_CONDITIONAL      16
#define IT_EFFECT      17
#define IT_EQ      18
#define IT_EXISTS      19
#define IT_FACT_DECL      20
#define IT_FLUENT_DECL      21
#define IT_FORALL      22
#define IT_FORMULA      23
#define IT_GE      24
#define IT_GT      25
#define IT_IF_ASSIGN      26
#define IT_IMPLIES      27
#define IT_IN      28
#define IT_LE      29
#define IT_LT      30
#define IT_MINUS      31
#define IT_NEQ      32
#define IT_NOT      33
#define IT_OR      34
#define IT_PASS_SENS      35
#define IT_PICK      36
#define IT_PLUS      37
#define IT_PROC_DECL      38
#define IT_PROGRAM      39
#define IT_REMOVE_ASSIGN      40
#define IT_SEARCH      41
#define IT_SENSING      42
#define IT_SIGNAL      43
#define IT_STRING_SET      44
#define IT_TEST      45
#define IT_TUPLE      46
#define IT_TUPLE_SET      47
#define IT_VALUE_LIST      48
#define IT_VAR      49
#define IT_VAR_LIST      50
#define IT_WHILE      51
#define STRING      52
#define TOKEN_ACTION      53
#define TOKEN_ADD_ASSIGN      54
#define TOKEN_ALL      55
#define TOKEN_AND      56
#define TOKEN_ASSIGN      57
#define TOKEN_ASSIGN_ALL      58
#define TOKEN_CHOOSE      59
#define TOKEN_CLOSE_PAREN      60
#define TOKEN_COLON      61
#define TOKEN_COMMA      62
#define TOKEN_DO      63
#define TOKEN_DOMAIN_END      64
#define TOKEN_DOMAIN_INT      65
#define TOKEN_DOMAIN_START      66
#define TOKEN_DOMAIN_STR      67
#define TOKEN_EFFECT      68
#define TOKEN_ELSE      69
#define TOKEN_END_ACTION      70
#define TOKEN_END_CHOOSE      71
#define TOKEN_END_FOR      72
#define TOKEN_END_IF      73
#define TOKEN_END_PASSIVE_SENSING      74
#define TOKEN_END_PICK      75
#define TOKEN_END_PROC      76
#define TOKEN_END_SEARCH      77
#define TOKEN_END_WHILE      78
#define TOKEN_EOL      79
#define TOKEN_EQUALS      80
#define TOKEN_EXISTS      81
#define TOKEN_FACT      82
#define TOKEN_FALSE      83
#define TOKEN_FLUENT      84
#define TOKEN_FOR_ALL      85
#define TOKEN_FROM      86
#define TOKEN_GE      87
#define TOKEN_GT      88
#define TOKEN_IF      89
#define TOKEN_IMPLIES      90
#define TOKEN_IN      91
#define TOKEN_LE      92
#define TOKEN_LT      93
#define TOKEN_MINUS      94
#define TOKEN_NEQUALS      95
#define TOKEN_NOT      96
#define TOKEN_OPEN_PAREN      97
#define TOKEN_OR      98
#define TOKEN_PASSIVE_SENSING      99
#define TOKEN_PATTERN_MATCHING      100
#define TOKEN_PICK      101
#define TOKEN_PLUS      102
#define TOKEN_PRECOND      103
#define TOKEN_PROC      104
#define TOKEN_REMOVE_ASSIGN      105
#define TOKEN_SEARCH      106
#define TOKEN_SENSING      107
#define TOKEN_SET_END      108
#define TOKEN_SET_START      109
#define TOKEN_SIGNAL      110
#define TOKEN_SUCH      111
#define TOKEN_TEST      112
#define TOKEN_THEN      113
#define TOKEN_TRUE      114
#define TOKEN_VAR_DECL_START      115
#define TOKEN_WHILE      116
#define WHITESPACE      117
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for YAGITreeWalker
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */