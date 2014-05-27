//******************************************************************************
//Grammar for the YAGI programming language
//Author: Christopher Maier
//Date: 2014-05-19
//Version: 0.1
//Changelog:
//  - 0.1: Initial version
//******************************************************************************
grammar YAGI;

options 
{
  language = C;
  output = AST;
  ASTLabelType=pANTLR3_BASE_TREE;
}

//******************************************************************************
//Imaginary tokens
//******************************************************************************
tokens  
{ 
  IT_FLUENT_DECL; 
  IT_STRING_SET;
  IT_TUPLE_SET;
  IT_FACT_DECL;
  IT_PROGRAM;
  IT_ASSIGN;
  IT_ADD_ASSIGN;
  IT_REMOVE_ASSIGN;
  IT_PLUS;
  IT_MINUS;
  IT_TUPLE;
  IT_VAR;
  IT_PASS_SENS;
  IT_VAR_LIST;
  IT_BLOCK;
  IT_ACTION_DECL;
  IT_SIGNAL;
  IT_SENSING;
  IT_ASSIGN_ALL;
  IT_IF_ASSIGN;
  IT_NOT;
  IT_AND;
  IT_OR;
  IT_IMPLIES;
  IT_ALL;
  IT_EXISTS;
  IT_IN;
  IT_EFFECT;
  IT_FORMULA;
  IT_PROC_DECL;
  IT_SEARCH;
  IT_PICK;
  IT_ACTION_EXEC;
  IT_VALUE_LIST;
  IT_CONDITIONAL;
  IT_FORALL;
  IT_WHILE;
  IT_CHOOSE;
  IT_TEST;
  IT_EQ;
  IT_NEQ;
  IT_GT;
  IT_LT;
  IT_GE;
  IT_LE;
  IT_ATOM_SETEXPR;
  IT_ATOM_VALEXPR;
} 

//Somehow ANTLR generates code with unknown symbol _empty
//Just null it out...
@header {
    #define _empty NULL
}

//******************************************************************************
//Basic program structure
//******************************************************************************
program	
	:	(declaration | statement)+ 

		-> ^(IT_PROGRAM declaration* statement*)
	;
	
block	
	:	statement+ 

		-> ^(IT_BLOCK statement+)
	;
	
//******************************************************************************
//Declarations
//******************************************************************************
declaration
	:	fluent_decl
	|	fact_decl
	|	action_decl
	| 	proc_decl
    	|   	passive_sensing_decl
	|	assignment
	;
	
fluent_decl
	:	TOKEN_FLUENT ID (TOKEN_DOMAIN_START domain TOKEN_DOMAIN_END)+ TOKEN_EOL 
	
		-> ^(IT_FLUENT_DECL ID domain+) 
	;	
	
fact_decl
	:	TOKEN_FACT ID (TOKEN_DOMAIN_START domain TOKEN_DOMAIN_END)+ TOKEN_EOL 
	
		-> ^(IT_FACT_DECL ID domain+) 
	;
	
domain	
	: 	TOKEN_DOMAIN_INT -> TOKEN_DOMAIN_INT
		  | TOKEN_DOMAIN_STR -> TOKEN_DOMAIN_STR
		  | TOKEN_SET_START STRING (TOKEN_COMMA STRING)* TOKEN_SET_END -> ^(IT_STRING_SET STRING+)
	;
	
action_decl
	:	TOKEN_ACTION ID (TOKEN_OPEN_PAREN (var_list | /*eps*/) TOKEN_CLOSE_PAREN)
		(TOKEN_PRECOND formula_outerMost)?
		(effect | active_sensing)
		(TOKEN_SIGNAL valexpr TOKEN_EOL)?
		TOKEN_END_ACTION
		
		-> ^(IT_ACTION_DECL ID ^(IT_VAR_LIST var_list) formula_outerMost? effect? active_sensing? (^(IT_SIGNAL valexpr))? )
	;
	
effect	
	:	TOKEN_EFFECT assignment* 

		-> ^(IT_EFFECT ^(IT_BLOCK assignment+))
	;
	
active_sensing	
	:	TOKEN_SENSING TOKEN_OPEN_PAREN var_list TOKEN_CLOSE_PAREN TOKEN_COLON assignment+
		
		-> ^(IT_SENSING ^(IT_VAR_LIST var_list) ^(IT_BLOCK assignment+))
	;
	
	
var_list
	:	var (TOKEN_COMMA var)* 

		-> var+
	;
	
	
proc_decl
	:	TOKEN_PROC ID (TOKEN_OPEN_PAREN var_list
		TOKEN_CLOSE_PAREN)? block TOKEN_END_PROC
		
		-> ^(IT_PROC_DECL ID (^(IT_VAR_LIST var_list))? block)
	;	
	
passive_sensing_decl
	:	TOKEN_PASSIVE_SENSING ID TOKEN_OPEN_PAREN var_list
		TOKEN_CLOSE_PAREN assignment+  TOKEN_END_PASSIVE_SENSING
                
                -> ^(IT_PASS_SENS ID ^(IT_VAR_LIST var_list) ^(IT_BLOCK assignment+))
                
	;	
	
assignment
	:	assign TOKEN_EOL -> assign
	|	for_loop_assign
	|	conditional_assign
	;
	
	
//******************************************************************************
//Statements
//******************************************************************************	
statement
	:	action_exec
	|	test
	|	choose
	| 	pick
	|	for_loop
	|	conditional
	|	while_loop
    	| 	search
	;
	
action_exec
	:	ID TOKEN_OPEN_PAREN (value_list)? TOKEN_CLOSE_PAREN TOKEN_EOL
		
		-> ^(IT_ACTION_EXEC ID ^(IT_VALUE_LIST value_list))
	;	
	
value_list	
	:	value (TOKEN_COMMA value)* 
	
		-> value+
	;
	
test	
	:	TOKEN_TEST formula TOKEN_EOL
	
		-> ^(IT_TEST formula)
	;	
	
choose	
	:	TOKEN_CHOOSE block ( TOKEN_OR block )+ TOKEN_END_CHOOSE

		-> ^(IT_CHOOSE block block+)
	;	
	
pick	
	:	TOKEN_PICK tuple TOKEN_FROM setexpr TOKEN_SUCH block TOKEN_END_PICK
		 
		-> ^(IT_PICK tuple setexpr block)
	;	
	
for_loop	
	:	TOKEN_FOR_ALL tuple TOKEN_IN setexpr TOKEN_DO block TOKEN_END_FOR
	
		-> ^(IT_FORALL tuple setexpr block)
	;

conditional
	:	TOKEN_IF TOKEN_OPEN_PAREN formula TOKEN_CLOSE_PAREN TOKEN_THEN block 
		(TOKEN_ELSE block)? TOKEN_END_IF
		
		-> ^(IT_CONDITIONAL formula ^(IT_BLOCK block) block?)
	;
	
while_loop
	:	TOKEN_WHILE formula TOKEN_DO block TOKEN_END_WHILE
	
		-> ^(IT_WHILE formula block)
	;	
	
search	
	:	TOKEN_SEARCH block TOKEN_END_SEARCH 

		-> ^(IT_SEARCH block)
	;
	
	
//******************************************************************************
//Assignments
//******************************************************************************
assign	
	:	var TOKEN_ASSIGN valexpr -> ^(IT_ASSIGN var valexpr)
	|	ID ass_op setexpr -> ^(ass_op ID setexpr)
	;
	
ass_op  
	:	(TOKEN_ASSIGN -> IT_ASSIGN 
                  | TOKEN_ADD_ASSIGN -> IT_ADD_ASSIGN 
                  | TOKEN_REMOVE_ASSIGN -> IT_REMOVE_ASSIGN
                )
        ;
        
for_loop_assign
	:	TOKEN_ASSIGN_ALL tuple TOKEN_IN setexpr assignment+ TOKEN_END_FOR
		
		-> ^(IT_ASSIGN_ALL tuple setexpr ^(IT_BLOCK assignment+))
	;
	
conditional_assign
	:	TOKEN_IF formula TOKEN_THEN (assignment)+ (TOKEN_ELSE assignment+)? TOKEN_END_IF
		
		-> ^(IT_IF_ASSIGN formula ^(IT_BLOCK assignment+) (^(IT_BLOCK assignment+))?)
	;


//******************************************************************************
//Formulas
//******************************************************************************
formula_outerMost
	:	formula TOKEN_EOL 
	
		-> ^(IT_FORMULA formula)
	;

formula	
	:	atom
	|	TOKEN_NOT TOKEN_OPEN_PAREN formula TOKEN_CLOSE_PAREN -> ^(IT_NOT formula)
	|	TOKEN_OPEN_PAREN atom formular_connective formula TOKEN_CLOSE_PAREN -> ^(formular_connective atom formula)
	|	TOKEN_EXISTS tuple TOKEN_IN setexpr (TOKEN_SUCH formula)? -> ^(IT_EXISTS tuple setexpr formula?)
	|	TOKEN_ALL tuple TOKEN_IN setexpr (TOKEN_SUCH formula)? -> ^(IT_ALL tuple setexpr formula?)
	|	tuple TOKEN_IN setexpr -> ^(IT_IN tuple setexpr)
	;
	
formular_connective
	:	TOKEN_AND -> IT_AND
	| 	TOKEN_OR  -> IT_OR
	|    	TOKEN_IMPLIES -> IT_IMPLIES
	;

atom
	:	v1=valexpr atom_connector v2=valexpr -> ^(IT_ATOM_VALEXPR ^(atom_connector $v1 $v2))
	|	s1=setexpr atom_connector s2=setexpr -> ^(IT_ATOM_SETEXPR ^(atom_connector $s1 $s2))
	|	(TOKEN_TRUE | TOKEN_FALSE)
	;
	
atom_connector
	:	TOKEN_EQUALS -> IT_EQ
	|  	TOKEN_NEQUALS -> IT_NEQ
	| 	TOKEN_LE -> IT_LE
	| 	TOKEN_GE -> IT_GE
	| 	TOKEN_LT -> IT_LT
	| 	TOKEN_GT -> IT_GT
	;
	
//******************************************************************************
//Sets
//******************************************************************************
set	:	TOKEN_SET_START tuple (TOKEN_COMMA tuple)* TOKEN_SET_END -> ^(IT_TUPLE_SET tuple+)
	|	ID
	;
	
setexpr	:	set (expr_op^ set)* 
	;
	
	
//******************************************************************************
//Tuples
//******************************************************************************	
tuple	
	:	TOKEN_LT (
		  tuple_val (TOKEN_COMMA tuple_val)* -> ^(IT_TUPLE tuple_val+)
		) TOKEN_GT
	;
	
tuple_val 
	:	STRING
	|     TOKEN_PATTERN_MATCHING
	|     var
	;	
	
//******************************************************************************
//Variables
//******************************************************************************
var	
	:	TOKEN_VAR_DECL_START ID -> ^(IT_VAR ID)
	;
	
value	
	:	INT
	|	STRING
	|	var
	;
	
valexpr	
	:	value (expr_op^ value)* 
	;

//not sure which version is better, depends on how to transform it into a treegrammar
//valexpr	:	(a=value->$a) 
//		  (
//		    expr_op b=value
//		    -> ^(expr_op $valexpr $b) 
//		  )* 
//	;


		
expr_op
	:	TOKEN_PLUS -> IT_PLUS 
	      | TOKEN_MINUS -> IT_MINUS
	;
	
//******************************************************************************
//Tokens
//******************************************************************************
TOKEN_EOL : ';';
TOKEN_COLON : ':';

TOKEN_PICK : 'pick';
TOKEN_END_PICK
	:	'end pick'
	;

TOKEN_FROM : 'from';
TOKEN_SUCH : 'such';

TOKEN_TEST : 'test';
TOKEN_IN : 'in';
TOKEN_DO : 'do';

TOKEN_IF : 'if';
TOKEN_END_IF
	:	'end if'
	;

TOKEN_THEN : 'then';
TOKEN_ELSE : 'else';

TOKEN_CHOOSE : 'choose';
TOKEN_END_CHOOSE
	:	'end choose'
	;

TOKEN_WHILE
	:	'while'
	;
	
TOKEN_END_WHILE
	:	'end while'
	;

TOKEN_END_FOR
	:	'end for'
	;

TOKEN_DOMAIN_INT
	:	'Integer'
	;

TOKEN_DOMAIN_STR
	:	'String'
	;

TOKEN_ACTION : 'action';
TOKEN_END_ACTION
	:	'end action'
	;

TOKEN_PRECOND : 'precondition:';
TOKEN_EFFECT : 'effect:';
TOKEN_SIGNAL : 'signal:';
TOKEN_SENSING : 'sensing';

TOKEN_PASSIVE_SENSING : 'passive-sensing';
TOKEN_END_PASSIVE_SENSING
	:	'end passive-sensing'
	;

TOKEN_NOT: 'not';
TOKEN_EXISTS: 'exists';
TOKEN_ALL: 'all';
TOKEN_IMPLIES: 'implies';

TOKEN_ASSIGN : '=';
TOKEN_ADD_ASSIGN: '+=';
TOKEN_REMOVE_ASSIGN: '-=';

TOKEN_EQUALS: '==';
TOKEN_NEQUALS: '!=';
TOKEN_LE: '<=';
TOKEN_GE: '>=';
TOKEN_LT: '<';
TOKEN_GT: '>';
TOKEN_PLUS : '+';
TOKEN_MINUS : '-';

TOKEN_AND: 'and';
TOKEN_OR: 'or';
TOKEN_TRUE: 'true';
TOKEN_FALSE: 'false';

TOKEN_PATTERN_MATCHING 
	:	 '_';

TOKEN_SET_START: '{';
TOKEN_SET_END: '}';

TOKEN_DOMAIN_START: '[';
TOKEN_DOMAIN_END: ']';

TOKEN_VAR_DECL_START: '$';
TOKEN_FLUENT : 'fluent';


TOKEN_END_SEARCH
	:	'end search';

TOKEN_SEARCH
	:	'search'
	;

TOKEN_OPEN_PAREN
	:	'('
	;
	
TOKEN_CLOSE_PAREN
	:	')';
	
TOKEN_COMMA
	:	','
	;

TOKEN_END_PROC
	:	'end proc';

TOKEN_PROC : 	'proc'
	  ; 

TOKEN_FACT
	:	'fact'
	;
	
TOKEN_FOR_ALL
	:	'for all'
	;

TOKEN_ASSIGN_ALL
	:	'assign all'
	;
	
WHITESPACE : ( '\t' | ' ' | '\r' | '\n'| '\u000C' )+    {$channel=HIDDEN;} ;

ID  :	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
    ;

INT :	('0'..'9')+
    ;

STRING
    :  '"' ( ~('\\'|'"') )* '"'
    ;

COMMENT
    :	'//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    ;