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

void test_operand2ExtractDestination_is_empty_argument(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	


	extractDestination_ExpectAndThrow(string,4);
	Try{
		operand2ExtractDestination(string);
	}Catch(error){
		TEST_ASSERT_EQUAL(error,ERR_INVALID_ARGUMENT);
		return;
	}
	TEST_FAIL_MESSAGE("No exception thrown.");
	
}

void test_operand2ExtractDestination_is_not_empty_argument(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	

	extractDestination_ExpectAndThrow(string,6);
	value = operand2ExtractDestination(string);


	TEST_ASSERT_EQUAL(value,0x1);
	
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


	TEST_ASSERT_EQUAL(value,0x0);
}

void test_operand3ExtractACCESSBANKED_is_not_empty_argument1(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	

	extractACCESSBANKED_ExpectAndThrow(string,6);
	value = operand3ExtractACCESSBANKED(string,0x81);


	TEST_ASSERT_EQUAL(value,0x1);
}


//TEST operand1 is not NULL 2,3 NULL


void test_FDA_operand1_is_34_operand2_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x34);
	extractDestination_ExpectAndThrow(string,6);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x35);
}

void test_FDA_operand1_is_85_operand2_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x85);
	extractDestination_ExpectAndThrow(string,6);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x87);
}

void test_FDA_operand1_is_ff_operand2_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0xff);
	extractDestination_ExpectAndThrow(string,6);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x101);
}

void test_FDA_operand1_is_ffe_operand2_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0xffe);
	extractDestination_ExpectAndThrow(string,6);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0xff);
}


//TEST operand1,2 is not NULL 3 NULL

void test_FDA_operand1_is_34_operand2_is_0_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x34);
	extractDestination_ExpectAndReturn(string,0);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x34);
}

void test_FDA_operand1_is_34_operand2_is_1_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x34);
	extractDestination_ExpectAndReturn(string,1);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x35);
}

void test_FDA_operand1_is_85_operand2_is_0_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x85);
	extractDestination_ExpectAndReturn(string,0);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x86);
}

void test_FDA_operand1_is_85_operand2_is_1_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x85);
	extractDestination_ExpectAndReturn(string,1);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x87);
}

void test_FDA_operand1_is_f01_operand2_is_0_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0xf01);
	extractDestination_ExpectAndReturn(string,0);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x2);
}

void test_FDA_operand1_is_f01_operand2_is_1_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0xf01);
	extractDestination_ExpectAndReturn(string,1);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x3);
}

void test_FDA_operand1_is_ffe_operand2_is_0_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0xffe);
	extractDestination_ExpectAndReturn(string,0);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0xfe);
}

void test_FDA_operand1_is_ffe_operand2_is_1_and_operand3_is_NULL(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0xffe);
	extractDestination_ExpectAndReturn(string,1);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0xff);
}


//operand1and3 is not NULL and operand2 is NULL

void test_FDA_operand1_is_34_operand2_is_NULL_and_operand3_is_11(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x34);
	extractDestination_ExpectAndThrow(string,6);
	extractACCESSBANKED_ExpectAndReturn(string,11);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x36);
}

void test_FDA_operand1_is_f01_operand2_is_NULL_and_operand3_is_10(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0xf01);
	extractDestination_ExpectAndThrow(string,6);
	extractACCESSBANKED_ExpectAndReturn(string,10);
	
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x2);
}

