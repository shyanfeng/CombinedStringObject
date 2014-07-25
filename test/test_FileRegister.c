#include "unity.h"
#include "FileRegister.h"
#include "ExecutionTable.h"
#include "Execute.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"

void setUp(void){}
void tearDown(void){}

void test_findActualFileRegister_should_get_data_from_address_in_file_register(){
	int data;
	
	fileRegisters[0x33] = 0x23;
	data = fileRegisters[0x33];
	data = findActualFileRegister(0x33, 0);
	
	TEST_ASSERT_EQUAL(0x23, data);
}

void test_findActualFileRegister_should_get_data_with_access_with_address_0x79(){
	int data;
	
	fileRegisters[0x79] = 0x12;
	data = fileRegisters[0x79];
	data = findActualFileRegister(0x79, 0);
	
	TEST_ASSERT_EQUAL(0x12, data);
}

void test_findActualFileRegister_should_get_data_with_access_with_address_0xf86(){
	int data;
	
	fileRegisters[0xf86] = 0x56;
	data = fileRegisters[0xf86];
	data = findActualFileRegister(0xf86, 0);
	
	TEST_ASSERT_EQUAL(0x56, data);
}

void test_findActualFileRegister_should_get_data_from_bank4_0x123(){
	int data;
	
	fileRegisters[0x123] = 0xa5;
	data = fileRegisters[0x123];
	fileRegisters[BSR] = 0x4;
	data = findActualFileRegister(0x123, 1);
	
	TEST_ASSERT_EQUAL(0, data);
}

void test_findActualFileRegister_should_get_data_from_bank8_0x3d1(){
	int data;
	
	fileRegisters[0x3d1] = 0x4a;
	data = fileRegisters[0x3d1];
	fileRegisters[BSR] = 0x8;
	data = findActualFileRegister(0x123, 1);
	
	TEST_ASSERT_EQUAL(0, data);
}

void test_getFileRegData_should_get_data_with_access_with_address_0x71(){
	int data;
	
	fileRegisters[0x71] = 0x4e;
	data = fileRegisters[0x71];
	data = getFileRegData(0x71, 0);
	
	TEST_ASSERT_EQUAL(0x4e, data);
}

void test_getFileRegData_should_get_data_with_access_with_address_0xfab(){
	int data;
	
	fileRegisters[0xfab] = 0xcd;
	data = fileRegisters[0xfab];
	data = getFileRegData(0xfab, 0);
	
	TEST_ASSERT_EQUAL(0xcd, data);
}

void test_getFileRegData_should_get_data_from_bank4_0x123(){
	int data;
	
	fileRegisters[0x345] = 0xb7;
	data = fileRegisters[0x345];
	fileRegisters[BSR] = 0x7;
	data = findActualFileRegister(0x345, 1);
	
	TEST_ASSERT_EQUAL(0, data);
}

