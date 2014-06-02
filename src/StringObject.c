#include "StringObject.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>

void textDump(Text *text){
	if(text== NULL){
		printf("(NULL)");
		return;
	}
	printf("text[%d]:%s\n",
			text->reference,text->string);
}

void stringDump(String *string){
	int index = 0,len = 0;
	char *fullString ="(NULL)";
	char *actualString = "(NULL)";
	
	if(string == NULL){
		printf("NULL\n");
		return;		
	}
	if(string->text != NULL){
		int actualLength;
			fullString = string->text->string; 
		index = string->start;
		if(index <= strlen(fullString)){
		actualString = &fullString[index];
		actualLength= strlen(actualString);
		len = string->length;
		if(len > actualLength)
			len = actualLength;
		} else{
			actualString = "";
		}
	}

	printf("[%d] f_str[%d]:%s,start:%d,len:%d,string:%.*s \n",
			string->reference,string->text->reference,fullString,index,string->length,len,actualString);
	return;
}

Text *textNew(char *charStr){
	Text *text = (Text *)malloc(strlen(charStr) + 4 + 1);
	strcpy(text->string,charStr); // destination,source
	text->reference = 1;
	return text;
}

Text *textAssign(Text *text){
	if(text->reference == 0x80000000){
		text->reference = 1;
	}else{
		text->reference ++;
	}
	return text;
}

Text *textDel(Text *text){
	if(text->reference == 0x80000000){
			text->reference = 1;
	}else{
		text->reference --;
			if(text->reference == 0x00){
				free(text);
				return NULL;
			}
	}
	return text;
}

String *stringNew(Text *text){
	String *string = malloc(sizeof(String));
	string->text = textAssign(text);
	string->reference = 1;
	string->start = 0;
	string->length = strlen(text->string);
	return string;
}

String *stringAssign(String *string){

		string->reference ++;
		
	return string;
}

String *stringDel(String *string){
	string->reference --;
	if(string->reference == 0x00){
				free(string);
				return NULL;
	}
	return string;
}

void stringSkip(String *string,int numChar2skip){
	int starting;
	starting = string->start + numChar2skip;
	if(starting < string->length){
		string->start = starting;
		string->length = string->length-string->start;
	}else{
		string->start=string->length;
	}
}

void stringTrimLeft(String *string){
	int i=0;
	char ch=string->text->string[0];
	
	while(isSpace(ch)){
		i++;
		ch=string->text->string[i];
		string->start++;
		string->length--;

	}
	
	
}

void stringTrimRight(String *string){
	int i=string->start+string->length-1;
	 char ch=string->text->string[i];
	while(isSpace(ch)){
		i--;
		ch=string->text->string[i];
		string->length--;
	}
}

void stringTrim(String *string){

	stringTrimLeft(string);
	stringTrimRight(string);
		
}

