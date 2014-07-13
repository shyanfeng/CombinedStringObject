#ifndef _FBA_H_
#define _FBA_H_

#include "Evaluate.h"

int FBA(String *arguments);
int operand1ExtractValue(String *arguments);
int operand2ExtractValue(String *arguments);
int operand3ExtractACCESSBANKED(String *arguments,int fileReg);

#endif //_FBA_H_