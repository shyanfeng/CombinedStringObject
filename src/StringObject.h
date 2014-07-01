#ifndef __STRING_OBJECT_H__
#define __STRING_OBJECT_H__

#include "Types.h"
#include "Text.h"

#define isSpace(ch) (ch == ' ' || ch == '\t')


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

int stringCharAt(String *string,int relativeIndex);
int stringIsCharAtInSet(String *string,int relativeIndex,char set[]);

int stringToInteger(String *string);
char *stringSubstringInChar(String *string, int start,int length);
Text *stringSubstringInText(String *string,int start,int length);



#endif //__STRING_OBJECT_H__