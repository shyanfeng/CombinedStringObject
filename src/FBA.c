#include <stdio.h>
#include "FBA.h"
#include "Evaluate.h"
#include "StringObject.h"
#include "String.h"
#include "CustomTypeAssert.h"
#include "CException.h"
#include "ErrorCode.h"




int operand1ExtractValue(String *arguments){
	ErrorCode error;
	int operand1;
	
	Try{
		operand1 = extractValue(arguments);
	}Catch(error){
			Throw(error);
	}
	
	return operand1;
}



int operand2ExtractValue(String *arguments){
	ErrorCode error;
	int operand2;
	
	Try{
		operand2 = extractValue(arguments);
			printf("%x \n",operand2);
	}Catch(error){
		if(error == ERR_NO_ARGUMENT){
				operand2 = operand2&7;
				printf("%x \n",operand2);
		}else if(error != ERR_EMPTY_ARGUMENT){
			if(error == ERR_INVALID_ARGUMENT){
					Throw(error);
			}
		}
	}
	
	return operand2;
}

int operand3ExtractACCESSBANKED(String *arguments,int fileReg){
	ErrorCode error;
	int operand3;
	
	Try{
		operand3 = extractACCESSBANKED(arguments);
	}Catch(error){
		if(error == ERR_NO_ARGUMENT){
			if((fileReg >= 0x00 && fileReg <= 0x80)||(fileReg >= 0xff0 && fileReg <= 0xfff)){
				operand3 = 1;
			}else{
				operand3 =  0;
			}
		}else if(error != ERR_EMPTY_ARGUMENT){
			if(error == ERR_INVALID_ARGUMENT){
				Throw(error);
			}
		}
	}
	
	return operand3;
}


int FBA(String *arguments){
	int operand1,operand2,operand3;
	int opcode;
	ErrorCode error;
		
	operand1 = operand1ExtractValue(arguments);
	operand2 = operand2ExtractValue(arguments);
	operand3 = operand3ExtractACCESSBANKED(arguments,operand1);
	
	
	operand1 = operand1&0xff;
	
	

	
	
	return opcode = operand1 + operand2 + operand3;
}