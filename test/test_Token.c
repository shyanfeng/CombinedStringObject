#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"

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
	TEST_ASSERT_EQUAL(0,identifiers->number->value);
	TEST_ASSERT_EQUAL_STRING("haha",identifiers->name->string);
}

void test_operatorNewBySymbol(void){
	int a;
	Operator *operators= operatorNewBySymbol("!");
	a = strcmp("!",operators->info->symbol);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operators->type);
	TEST_ASSERT_EQUAL(0,a);
	
}