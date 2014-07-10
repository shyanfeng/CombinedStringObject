#include <stdio.h>
#include "FDA.h"
#include "Evaluate.h"
#include "StringObject.h"
#include "String.h"
#include "CustomTypeAssert.h"
#include "CException.h"
#include "ErrorCode.h"

int FDA(String *arguments){
	
	int operand1,operand3,check,value,value1,opcode;
	int operand2 = 0;
	int BANKED = 1;
	int ACCESS = 0;
	int F = 1;
	int W = 0;
	ErrorCode error;
	ErrorCode e;
	ErrorCode err;
	
	Try{
		operand1 = extractValue(arguments);
		operand1 = operand1&(0x7f);	
		operand2 = extractDestination(arguments);
		goto here;
		operand3 = extractACCESSBANKED(arguments);
	}Catch(error){
		if(error == ERR_EMPTY_VALUE){
			Throw(ERR_EMPTY_VALUE);
		}else{
			operand1;
			Try{
				extractDestination(arguments);
			}Catch(e){
				if(e == ERR_EMPTY_VALUE){
					Try{
						extractACCESSBANKED(arguments);
					}Catch(err){
						if(err == ERR_EMPTY_VALUE){
							printf("aaa");
						}else{
							printf("bbbb");
						}
					}
				}else{
					here:
					if(operand2%2 == 0){
						operand2 = W;
						operand2 = 0x0;
					}else{
						operand2 = F;
						operand2 = 0x1;
					}
				}
			}
		}	
	}
	

	return  opcode = operand1+operand2;
}


// int operand1Value(String *arguments){
	// int operand1,value;
	// operand1 = extractValue(arguments);
	// operand1 = value&0x7f;
	// printf("%x \n",operand1);
	// return operand1;
// }


// operand1 = operand1&0x7f;
			// Try{
				// operand3 = extractDestination(arguments);
				// printf("%x \n",operand3);
			// }Catch(e){
				// if(e != ERR_EMPTY_VALUE){
					// if(operand3 == 1){
						// printf("aass \n");
					// }else{
						// printf("aaas \n");
					// }
				// }else{
					// printf("aas");
				// }
			// }

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