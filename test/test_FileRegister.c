#include "unity.h"
#include "FileRegister.h"
#include "ExecutionTable.h"
#include "Execute.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"

void setUp(void){}
void tearDown(void){}

void test_FileRegister_should_get_data_from_address_in_file_register(){
	int data;
	
	data = fileRegisters[0x33] = 0x23;
	printf("%x\n", data);
	data = getFileRegData(0x33, 0);
	printf("%x", data);
	
}

