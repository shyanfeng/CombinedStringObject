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

void xtest_FDA_operand1_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndThrow(string,3);
	
	
	Try{
		value = FDA(string);
	}Catch(error){
		TEST_ASSERT_EQUAL(error,ERR_EMPTY_VALUE);
		return;
	}
	TEST_FAIL_MESSAGE("No exception thrown.");
}

void test_FDA_operand1_is_0(void){
	int value;
	Text *new = textNew("0x23");
	String *string = stringNew(new);
	
	extractValue_ExpectAndThrow(string,0);
	extractDestination_ExpectAndThrow(string,0);
	FDA(string);
	extractValue_ExpectAndReturn(string,0x23);
	extractDestination_IgnoreAndReturn(1);
	FDA(string);
	
	//FDA(string);
	




//	TEST_ASSERT_EQUAL(value,0x23);
}

void xtest_FDA_operand1_is_1(void){
	int value;
	Text *new = textNew("0x123");
	String *string = stringNew(new);

	
	extractValue_ExpectAndThrow(string,0);
	extractDestination_ExpectAndThrow(string,0);
	FDA(string);
	extractValue_ExpectAndReturn(string,0x123);
	extractDestination_IgnoreAndReturn(1);
	FDA(string);
	
	TEST_ASSERT_EQUAL(value,0);

}
