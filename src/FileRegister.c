#include <stdio.h>
#include "FileRegister.h"
#include "ExecutionTable.h"
#include "Execute.h"

unsigned char fileRegisters[4096];

int getFileRegData(int address, int access){
	int data;
	int actualAddress;
	
	if(access == 0){
		if((address >= 0x00 && address <= 0x7f) || (address >= 0xf80 && address <= 0xfff)){
			data = fileRegisters[address];
			printf("%x\n", data);
		}
	}else{
		if(fileRegisters[BSR] >= 0x0 && fileRegisters[BSR] <= 0x15){
			if((address >= 0x80 && address <= 0xf79)){
				actualAddress = ((fileRegisters[BSR] & 0x0f)<<8) + (address & 0xff);
				data = fileRegisters[actualAddress];
				printf("%x\n", data);
				
			}
		}
	}
	
	return data;
}

int setFileRegData(int address, int access, int data){

}

int findActualFileRegister(int address, int access){



}

void clearAllFileRegisters(unsigned int fileRegisters){

	fileRegisters = 0;

}