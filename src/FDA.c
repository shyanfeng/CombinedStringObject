#include <stdio.h>
#include "FDA.h"
#include "Evaluate.h"
#include "StringObject.h"
#include "String.h"
#include "CustomTypeAssert.h"
#include "CException.h"
#include "ErrorCode.h"

int FDA(String *arguments){
	// int mask1 = 0xfff;
	// int mask2 = 0xff;

	// int F = 0x1;
	// int ACCESS = 0;
	// int a;
	// int operand1,operand2,operand3,maskValue1;
	// int opcode;
	
	
	int operand1,operand3,check,value;
	int BANKED = 1;
	int ACCESS = 0;
	ErrorCode error;
	ErrorCode e;
	
	
	Try{
		operand1 = extractValue(arguments);
		printf("%x \n",operand1);
	}Catch(error){
		if(error != ERR_EMPTY_VALUE){
		   operand1 = operand1&0x7f;
			Try{
				operand3 = extractDestination(arguments);
				printf("%x \n",operand3);
			}Catch(e){
				if(e != ERR_EMPTY_VALUE){
					if(operand3 == 1){
						printf("aass \n");
					}else{
						printf("aaas \n");
					}
				}else{
					printf("aas");
				}
			}
		}else{
			Throw(ERR_EMPTY_VALUE);
		}
	}
	
	
	// here:
	// check = (operand1 & 0x100)>>8;
	// if(check == 1){
		// operand3 = ACCESS;
	// }else{
		// operand3 = BANKED;	
	// }
	
	// come:
	// if(operand3 == 0){
		// operand3 = ACCESS;
	// }else{
		// operand3 = BANKED;
	// }
	

	return  operand1;
}




