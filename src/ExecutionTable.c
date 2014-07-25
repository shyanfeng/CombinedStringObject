#include <stdio.h>
#include "ExecutionTable.h"
#include "Execute.h"

typedef int (*ExecutionTable)(unsigned int code);

ExecutionTable executionTable[64] = {
	[0x24] = executeBCF,
	[0x25] = executeBCF,
	[0x26] = executeBCF,
	[0x27] = executeBCF,

};