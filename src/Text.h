#ifndef __TEXT_H__
#define __TEXT_H__
#include "Types.h"
#define t (Text *)"\x00\x00\00\x80"
typedef struct Text{
	uint32 reference;
	char string[0];	
}Text;
	

#endif //__TEXT_H__