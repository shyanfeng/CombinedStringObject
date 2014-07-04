#include "unity.h"
#include "FDA.h"
#include "CException.h"
#include "mock_Evaluate.h"
#include "CustomTypeAssert.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"

void setUp(void){}
void tearDown(void){}

void test_FDA_operand1_is_1(void){
	int value;
	Text *new = textNew("0x123");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x123);
	value = FDA(string);
	
	
	TEST_ASSERT_EQUAL(value,1059);

}

void test_FDA_operand1_is_0(void){
	int value;
	Text *new = textNew("0x23");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x23);
	value = FDA(string);
	
	
	TEST_ASSERT_EQUAL(value,547);
}

