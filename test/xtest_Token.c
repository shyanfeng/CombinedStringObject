#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"
#include "CException.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"

void setUp(void) {}

void tearDown(void) {}
/*
void test_getToken(void) {
  String str;
	TEST_ASSERT_NOT_NULL(getToken(&str));
}
*/
void test_numberNew(void){
	Number *numbers;
	numbers = numberNew(20);
	
	TEST_ASSERT_EQUAL(20,numbers->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,numbers->type);
	
}

void test_identifierNew(void){
	Text *new = textNew("haha");
	Identifier *identifiers= identifierNew(new);
	
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifiers->type);
	TEST_ASSERT_EQUAL(NULL,identifiers->number);
	TEST_ASSERT_EQUAL_STRING("haha",identifiers->name->string);
}

void test_operatorNewBySymbol(void){
	int a;
	Operator *operators= operatorNewBySymbol("!");
	a = strcmp("!",operators->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operators->type);
	TEST_ASSERT_EQUAL(0,a);
	
}

void test_operatorNewByID(void){

	Operator *operatorss= operatorNewByID(ADD_OP);
	TEST_ASSERT_EQUAL(ADD_OP,operatorss->info->id);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operatorss->type);
}

void test_getToken_if_is_number(void){
 
	Text *newText = textNew("           123");
	String *str = stringNew(newText);
	Token *token = getToken(str);
	


	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(123,((Number*)token)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,token->type);

}

void test_getToken_if_is_number1(void){
 
	Text *newText = textNew(" 123");
	String *str = stringNew(newText);
	Token *token = getToken(str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(123,((Number*)token)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,token->type);

}

void test_getToken_if_is_abc(void){

	Text *text = textNew("abc");
	String *str = stringNew(text);
	Token *token ;

	token = getToken(str);

	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,(Identifier *)token->type);
	TEST_ASSERT_EQUAL_STRING("abc",((Identifier *)token)->name->string);
}

void test_getToken_identifier_is_space(void){

	Text *text = textNew(" abc");
	String *str = stringNew(text);
	Token *token ;

	token = getToken(str);

	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,(Identifier *)token->type);
	TEST_ASSERT_EQUAL_STRING("abc",((Identifier *)token)->name->string);
}

void test_getToken_if_is_operator(void){
	int symbol;
	
	Text *text = textNew("&");
	String *str = stringNew(text);
	Token *token = getToken(str);

	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,(Operator*)token->type);
	TEST_ASSERT_EQUAL_STRING("&",((Operator *)token)->info->symbol);
}


void test_getToken_if_is_operator2(void){
	int symbol;
	
	Text *text = textNew("||");
	String *str = stringNew(text);
	Token *token = getToken(str);

	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,(Operator*)token->type);
	TEST_ASSERT_EQUAL_STRING("||",((Operator *)token)->info->symbol);
}

void test_getToken_number_with_alphabet_is_throw_error(void){
	int e;
	Text *text = textNew("  12a");
	String *string = stringNew(text);
	Token *token;



	Try{
		token = getToken(string);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
	}
}

void test_getToken_symbol_with_number_is_throw_error(void){
	int e;
	Text *text = textNew("  @12");
	String *string = stringNew(text);
	Token *token;



	Try{
		token = getToken(string);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
	}
}

void test_getToken_symbol_with_alphabet_is_throw_error(void){
	int e;
	Text *text = textNew("  @ab");
	String *string = stringNew(text);
	Token *token;

	Try{
		token = getToken(string);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_WELL_FORMED,e);
	}
}

void test_getToken_symbol_and_number_and_identifier_not_error(void){
	Text *text = textNew("  && 123 aaa");
	String *string = stringNew(text);
	Token *token;
	
	token = getToken(string);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,token->type);
	TEST_ASSERT_EQUAL_STRING("&&",((Operator *)token)->info->symbol);
	TEST_ASSERT_EQUAL(LOGICAL_AND_OP,((Operator *)token)->info->id);
	TEST_ASSERT_EQUAL_String(" 123 aaa",string);

	token = getToken(string);
	TEST_ASSERT_EQUAL(123,((Number*)token)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,token->type);
	TEST_ASSERT_EQUAL_String(" aaa",string);
	
	token = getToken(string);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,token->type);
	TEST_ASSERT_EQUAL_STRING("aaa",((Identifier *)token)->name->string);
	TEST_ASSERT_EQUAL_String("",string);
}

void test_getToken_symbol_and_number__not_error(void){
	Text *text = textNew("      321 123");
	String *string = stringNew(text);
	Token *token;
	
	

	token = getToken(string);
	TEST_ASSERT_EQUAL(321,((Number*)token)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,token->type);
	TEST_ASSERT_EQUAL_String(" 123",string);
	
	token = getToken(string);
	 TEST_ASSERT_EQUAL(123,((Number*)token)->value);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,token->type);
	TEST_ASSERT_EQUAL_String("",string);
}

void test_tokenDel(void){
	
	Text *text = textNew("abc");
	String *string = stringNew(text);
	Token *token = getToken(string);
	tokenDel(token);

}







