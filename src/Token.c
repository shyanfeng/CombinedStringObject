#include <stdio.h>
#include <malloc.h>
#include "CException.h"
#include "Token.h"
#include "CharSet.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"


#define MAIN_OPERATOR_TABLE_SIZE	(sizeof(mainOperatorTable)/sizeof(OperatorInfo))
#define	ALTERNATIVE_OPERATOR_TABLE_SIZE	(sizeof(alternativeOperatorTable)/sizeof(OperatorInfo))

OperatorInfo mainOperatorTable[] = {
  {.symbol="~", .id=BITWISE_NOT_OP, .precedence=150, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="!", .id=LOGICAL_NOT_OP, .precedence=150, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="*", .id=MUL_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="/", .id=DIV_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="%", .id=MOD_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="+", .id=ADD_OP, .precedence=80, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="-", .id=SUB_OP, .precedence=80, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="&", .id=BITWISE_AND_OP, .precedence=60, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="^", .id=BITWISE_XOR_OP, .precedence=50, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="|", .id=BITWISE_OR_OP, .precedence=40, .affix=INFIX, .assoc=LEFT_TO_RIGHT},  
  {.symbol="&&", .id=LOGICAL_AND_OP, .precedence=30, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="||", .id=LOGICAL_OR_OP, .precedence=20, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  // All other symbols MUST have higher precedence than those below:
  {.symbol="(", .id=OPENING_BRACKET_OP, .precedence=10, .affix=PREFIX, .assoc=RIGHT_TO_LEFT},
  {.symbol=")", .id=CLOSING_BRACKET_OP, .precedence=9,  .affix=POSTFIX, .assoc=LEFT_TO_RIGHT}
};

OperatorInfo alternativeOperatorTable[] = {
  {.symbol="+", .id=PLUS_OP, .precedence=150, .affix=PREFIX, .assoc=RIGHT_TO_LEFT},
  {.symbol="-", .id=MINUS_OP, .precedence=150, .affix=PREFIX, .assoc=RIGHT_TO_LEFT}
};

/**
 * Create a Number token initialized to the value given.
 *
 * Input:
 *   value  is the value to initialized with
 */
Number *numberNew(int value){
	Number *numbers = malloc(sizeof(Number));

	numbers->value = value;
	numbers->type = NUMBER_TOKEN;
		
	return numbers;
}

/**
 * Create an Operator token identified by symbol.
 *
 * Input:
 *   symbol is symbol in string of characters, i.e., "*"
 *          and "&&".
 */
Operator *operatorNewBySymbol(char *symbol) {
	Operator *operators = malloc(sizeof(Operator));
	
	operators->type = OPERATOR_TOKEN;
	int i=0;
	while(mainOperatorTable[i].symbol != 0){
		if(strcmp(mainOperatorTable[i].symbol,symbol)==0){
			 operators->info =  &mainOperatorTable[i];
			return operators;
		}
		i++;
	}

	return operators;
}

/**
 * Create an Operator token identified by the ID.
 *
 * Input:
 *   symbol is symbol in string of characters, i.e., MUL_OP
 *          and CLOSING_BRACKET_OP.
 */
Operator *operatorNewByID(OperatorID id) {
	Operator *operators = malloc(sizeof(Operator));
	
	operators->type = OPERATOR_TOKEN;
	int i = 0;
	while(mainOperatorTable[i].id != 0){
		if(mainOperatorTable[i].id == id){
			operators->info = &mainOperatorTable[i];
			  return operators;
		}
		i++;
	}

  return operators;
}

/**
 * Create an Identifier token initialized with the name
 * given.
 *
 * Input:
 *   name is the name of the identifier.
 */
Identifier *identifierNew(Text *name) {
  Identifier *identifier = malloc(sizeof(Identifier));
  
  identifier->type = IDENTIFIER_TOKEN;
  identifier->number = NULL;
  identifier->name = name;
  
  return identifier;
}


Token *getNumber(String *str){
		String *strStore;
		strStore = stringRemoveWordContaining(str,numberSet);
		if(isSpace(stringCharAt(str,0)) || str->length==0){
			return (Token *) numberNew(stringToInteger(strStore));
		}else{
				free(strStore);
				Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
	return (Token *) numberNew(stringToInteger(strStore));
}

Token *getIdentifier(String *str){
		String *strStore;
		strStore = stringRemoveWordContaining(str,alphabetSet);
		if(isSpace(stringCharAt(str,0)) || str->length==0){
			return (Token *)identifierNew(stringSubstringInText(strStore,strStore->start,strStore->length));
		}else{
				free(strStore);
				Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
	return (Token *)identifierNew(stringSubstringInText(strStore,strStore->start,strStore->length));
}

Token *getOperator(String *str){
		char operators[3];
		operators[0] = (char)stringRemoveChar(str);
		operators[1] = 0;
	
			if(operators[0] == stringCharAt(str,0)){
				if(stringCharAt(str,0) == '&'){
					operators[1] = (char)stringRemoveChar(str);
					operators[2] = 0;
					goto here;
				}else if(stringCharAt(str,0) == '|'){
					operators[1] = (char)stringRemoveChar(str);
					operators[2] = 0;
					goto here;
				}else{
					Throw(ERR_NUMBER_NOT_WELL_FORMED);
				}
			}
			if(isSpace(stringCharAt(str,0)) || str->length==0){
				return (Token*)operatorNewBySymbol(operators);
			}else{
					Throw(ERR_NUMBER_NOT_WELL_FORMED);
			}
		here:
		return (Token*)operatorNewBySymbol(operators);
}


/**
 * Return the one token from the String. The String is updated.
 * If the string is empty, NULL is return.
 *
 * Input:
 *   str  is the String object
 *
 * Possible returned token:
 *    Number, Operator, and Identifier tokens
 */
 
Token *getToken(String *str) {
	
	Token *returnToken;
	stringTrimLeft(str);
	
	if(stringIsCharAtInSet(str,0,numberSet)){
		 getNumber(str);
		
	}

	else if(stringIsCharAtInSet(str,0,alphabetSet)){
		 getIdentifier(str);
	}
	
	else if(stringIsCharAtInSet(str,0,operatorSet)){
		 getOperator(str);
	}
		
	else{
		Throw(ERR_NUMBER_NOT_WELL_FORMED);
	}
}

void tokenDel(Token *token){
	
	if(token->type == IDENTIFIER_TOKEN){
		textDel(((Identifier*)token)->name);
		free(((Identifier*)token)->number);
	}else if(token->type == NUMBER_TOKEN){
		((Number*)token)->value = 0;
		free(token);
	}else if(token->type == OPERATOR_TOKEN){
		free(((Operator*)token)->info->symbol);
	}
	
}










	// if(token->type == IDENTIFIER_TOKEN){
		// 
		// free(((Identifier*)token)->type);
	// }


	
	

	
	
	

	





