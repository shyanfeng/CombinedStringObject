#include "unity.h"
#include "FileRegister.h"
#include "ExecutionTable.h"
#include "Execute.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"

void setUp(void){}
void tearDown(void){}

void test_findActualFileRegister_should_return_address_0x23_when_access_is_0(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	address = findActualFileRegister(0x23, 0);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0x23, address);

}

void test_findActualFileRegister_should_return_address_0x67_when_access_is_0(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	address = findActualFileRegister(0x67, 0);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0x67, address);

}

void test_findActualFileRegister_should_return_address_0xff2_when_access_is_0(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	address = findActualFileRegister(0xff2, 0);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0xff2, address);

}

void test_findActualFileRegister_over_range_should_mask_and_return_address_0x30_when_access_is_0(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	address = findActualFileRegister(0x830, 0);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0x30, address);

}

void test_findActualFileRegister_over_range_after_mask_still_over_range_should_return_address_0xf84_when_access_is_0(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	address = findActualFileRegister(0x84, 0);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0xf84, address);

}

void test_findActualFileRegister_BSR_should_return_actual_address_0x856_when_access_is_1(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[BSR] = 0x8;
	address = findActualFileRegister(0x156, 1);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0x856, address);

}

void test_findActualFileRegister_BSR_should_return_actual_address_0x482_when_access_is_1(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[BSR] = 0x4;
	address = findActualFileRegister(0x82, 1);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0x482, address);

}

void test_findActualFileRegister_BSR_should_return_actual_address_0x612_when_access_is_1(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[BSR] = 0x6;
	address = findActualFileRegister(0xf12, 1);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0x612, address);

}

void test_findActualFileRegister_BSR_0x73_should_return_actual_address_0x313_when_access_is_1(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[BSR] = 0x73;
	address = findActualFileRegister(0x13, 1);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0x313, address);

}

void test_findActualFileRegister_BSR_0x7_with_address_0xff90_should_return_actual_address_0x790_when_access_is_1(){
	int address;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[BSR] = 0x7;
	address = findActualFileRegister(0xff90, 1);
	printf("%x", address);
	
	TEST_ASSERT_EQUAL(0x790, address);

}

void test_getFileRegData_should_get_data_from_address_in_file_register(){
	int data;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[0x33] = 0x23;
	data = fileRegisters[0x33];
	data = getFileRegData(0x33, 0);
	
	TEST_ASSERT_EQUAL(0x23, data);
}

void test_getFileRegData_should_get_data_with_access_with_address_0x79(){
	int data;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[0x79] = 0x12;
	data = fileRegisters[0x79];
	data = getFileRegData(0x79, 0);
	
	TEST_ASSERT_EQUAL(0x12, data);
}

void test_getFileRegData_should_get_data_with_access_with_address_0xf86(){
	int data;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[0xf86] = 0x56;
	data = fileRegisters[0xf86];
	data = getFileRegData(0xf86, 0);
	
	TEST_ASSERT_EQUAL(0x56, data);
}

void test_getFileRegData_should_get_data_from_bank4_0x123(){
	int data;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[0x123] = 0xa5;
	data = fileRegisters[0x123];
	fileRegisters[BSR] = 0x4;
	data = getFileRegData(0x123, 1);
	
	TEST_ASSERT_EQUAL(0, data);
}

void test_getFileRegData_should_get_data_from_bank8_0x3d1(){
	int data;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[0x3d1] = 0x4a;
	data = fileRegisters[0x3d1];
	fileRegisters[BSR] = 0x8;
	data = getFileRegData(0x3d1, 1);
	
	TEST_ASSERT_EQUAL(0, data);
}

void test_setFileRegData_access_should_set_data_into_address_0x45(){
	int data;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[0x45] = 0x3c;
	data = fileRegisters[0x45];
	data = setFileRegData(0x45, 0, 0x3c);
	
	TEST_ASSERT_EQUAL(0x3c, data);
	
}

void test_setFileRegData_access_should_set_data_into_address_0x7e(){
	int data;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[0x7e] = 0xc8;
	data = fileRegisters[0x7e];
	data = setFileRegData(0x7e, 0, 0xc8);
	
	TEST_ASSERT_EQUAL(0xc8, data);
	
}

void test_setFileRegData_banked_should_set_data_into_address_0x298(){
	int data;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[0x298] = 0x34;
	data = fileRegisters[0x288];
	fileRegisters[BSR] = 0x4;
	data = setFileRegData(0x288, 1, 0x34);
	
	TEST_ASSERT_EQUAL(0x34, data);
	
}

void test_setFileRegData_banked_should_set_data_into_address_0xf71(){
	int data;
	
	clearAllFileRegisters(fileRegisters);
	
	fileRegisters[0xf71] = 0x62;
	data = fileRegisters[0xf71];
	fileRegisters[BSR] = 0x4;
	data = setFileRegData(0xf71, 1, 0x62);
	
	TEST_ASSERT_EQUAL(0x62, data);
	
}
