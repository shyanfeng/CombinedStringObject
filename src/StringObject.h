#ifndef __STRING_OBJECT_H__
#define __STRING_OBJECT_H__

#include "Types.h"

#define t (Text *)"\x00\x00\00\x80"
#define isSpace(ch) (ch == ' ' || ch == '\t')

typedef struct Text{
	uint32 reference;
	char string[0];	
}Text;

typedef struct String{
	uint32 reference;
	Text *text;
	uint32 start;
	uint32 length;	
}String;

void stringDump(String *string);
void textDump(Text *text);

Text *textNew(char *charStr);
Text *textAssign(Text *text);
Text *textDel(Text *text);

String *stringNew(Text *text);
String *stringAssign(String *string);
String *stringDel(String *string);

void stringSkip(String *string,int numChar2skip);
void stringTrimLeft(String *string);
void stringTrimRight(String *string);
void stringTrim(String *string);

int stringRemoveChar(String *string);
int stringLength(String *string);
String *stringRemoveWordNotContaining(String *string,char delimiters[]);
String *stringRemoveWordContaining(String *string,char containSet[]);
int stringlsEqual(String *string1,String *string2);
int stringlsEqualCaseInsensitive(String *string1,String *string2);

#endif //__STRING_OBJECT_H__