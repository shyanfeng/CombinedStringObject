#include <stdio.h>
#include "FDA.h"
#include "Evaluate.h"
#include "StringObject.h"
#include "String.h"
#include "CustomTypeAssert.h"
#include "CException.h"
#include "ErrorCode.h"

int FDA(String *arguments){
	int mask1 = 0xfff;
	int mask2 = 0xff;
	int BANKED = 0x1;
	int F = 0x1;
	int ACCESS = 0;
	int a;
	int operand1,operand2,operand3,maskValue1;
	int opcode;

	CEXCEPTION_T error;
	operand1 = extractValue(arguments);

	if(((operand1 & 0x100)>>8) == 1 ){
		operand1 = operand1&0x7f;
		operand2 = F<<9;
		operand3 = BANKED<<9;
	}else{
		operand1 = operand1&0x7f;
		operand2 = F<<9;
		operand3 = ACCESS<<9;
	}
	
	
	

	return  operand1+operand2+operand3;

}





