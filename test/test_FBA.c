#include "unity.h"
#include "FBA.h"
#include "CException.h"
#include "mock_Evaluate.h"
#include "CustomTypeAssert.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"


void setUp(void){}
void tearDown(void){}

void test_operand1ExtractValue(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndThrow(string,3);
	
	Try{
		operand1ExtractValue(string);
	}Catch(error){
		TEST_ASSERT_EQUAL(error,ERR_EMPTY_VALUE);
		return;
	}
	TEST_FAIL_MESSAGE("No exception thrown.");
}


void test_operand1ExtractValue_it_is_value(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x123);
	value = operand1ExtractValue(string);
			
			
	TEST_ASSERT_EQUAL(value,0x123);
}

void test_operand2ExtractValue1(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndThrow(string,4);
	Try{
		operand2ExtractValue(string);
	}Catch(error){
		TEST_ASSERT_EQUAL(error,ERR_INVALID_ARGUMENT);
		return;
	}
	TEST_FAIL_MESSAGE("No exception thrown.");
}

void test_operand2ExtractValue2(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	extractValue_ExpectAndThrow(string,6);
	operand2ExtractValue(string);
	extractValue_ExpectAndReturn(string,0x02);
	value = operand2ExtractValue(string);
			
			
	TEST_ASSERT_EQUAL(value,0x2);
}



void test_operand3ExtractACCESSBANKED_is_empty_argument(void){
	int value,error;

	Text *new = textNew("");
	String *string = stringNew(new);
	

	extractACCESSBANKED_ExpectAndThrow(string,4);
	Try{
		operand3ExtractACCESSBANKED(string,0);
	}Catch(error){
		TEST_ASSERT_EQUAL(error,ERR_INVALID_ARGUMENT);
		return;
	}
	TEST_FAIL_MESSAGE("No exception thrown.");
}


void test_operand3ExtractACCESSBANKED_is_not_empty_argument(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	

	extractACCESSBANKED_ExpectAndThrow(string,6);
	value = operand3ExtractACCESSBANKED(string,0x20);


	TEST_ASSERT_EQUAL(value,0x1);
}

void test_operand3ExtractACCESSBANKED_is_not_empty_argument1(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	

	extractACCESSBANKED_ExpectAndThrow(string,6);
	value = operand3ExtractACCESSBANKED(string,0x81);


	TEST_ASSERT_EQUAL(value,0x0);
}

int test_FBA1(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x123);
	extractValue_ExpectAndThrow(string,6);
	extractValue_ExpectAndReturn(string,0x123);
	extractACCESSBANKED_ExpectAndReturn(string,1);
	value = FBA(string);
		
	TEST_ASSERT_EQUAL(value,0x25);

}
