#include <stdio.h>
#include "FileRegister.h"

unsigned char fileRegisters[4096];

int getFileRegData(int address, int access){
	int data;
	
	fileRegisters[address];
	data = fileRegisters[address];
	printf("%x\n", data);
	
	return data;
}

int setFileRegData(int address, int access, int data){

}