#include "StringObject.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

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
			fullString = string->text->string;      // &string->text->string[string->start];
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
		return text;
	}else{
		text->reference ++;
	}
	return text;
}

Text *textDel(Text *text){
	if(text->reference == 0x80000000){
			return text;
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


int stringRemoveChar(String *string){
	int i;
	char StringStart;
	StringStart = string->text->string[string->start];
	if(string->text->string[string->start] != string->text->string[string->length] > string->text->string[0]) {
			string->start++;
			string->length--;
		return StringStart;
	}else{
		return -1;
	}
}

int stringLength(String *string){
	return string->length;
}



String *stringRemoveWordNotContaining(String *string,char delimiters[]){
	int i=0,j=0;
	
	String *stringA = stringNew(string->text);
	stringA->length = 0;
	
	while(string->text->string[i]!=0){
	while(delimiters[j] != 0){
		if(string->text->string[i] == delimiters[j]){
				stringA->start = string->start;				
				stringA->length = i-string->start;	
				string->start = i;
				string->length = string->length - stringA->length ;
				return stringA;
		}
		j++;
		}
		j=0;
		i++;
	}
	
	return stringA; 
}


String *stringRemoveWordContaining(String *string,char containSet[]){
	int i=0,j=0,value=0;
	char isChar=string->text->string[i];
	String *stringA = stringNew(string->text);
	stringA->length = 0;
	stringA->start = string->start;

	while(string->text->string[i]!=0){
	while(containSet[j] != 0){
		if(string->text->string[i] == containSet[j]){
			string->start++;
			string->length--;
			stringA->length++;
			goto here;
		}else{
			value++;	
		}
		j++;
	}
	if(value>=stringA->length){
		goto come;
	}
		here:
		j=0;
		i++;
	}
	come:
	return stringA; 
}


int stringlsEqual(String *string1,String *string2){
	int i = 0, count = 0;
	int j = 0;
	for(i = string1->start, j = string2->start ; i<string1->length || j<string2->length; i++,j++){
		if(string1->text->string[i] != string2->text->string[j]){
			return 0;
		}
	}
	return 1;
}

int stringlsEqualCaseInsensitive(String *string1,String *string2){
	int i =0 ,j = 0;
	
	for(i = 0; string1->text->string[i];i++){
		string1->text->string[i] = tolower(string1->text->string[i]);
	}
	for(i = 0; string2->text->string[i];i++){
		string2->text->string[i] = tolower(string2->text->string[i]);
	}
	
	for(i = string1->start, j = string2->start ; i<string1->length || j<string2->length; i++,j++){
		if(string1->text->string[i] != string2->text->string[j]){
			return 0;
		}
	}
	return 1;

}


int stringCharAt(String *string,int relativeIndex){

	if(relativeIndex < 0 || string->start+relativeIndex>=string->length){
		return -1;
	}else{
		return string->text->string[string->start+relativeIndex];
	}

}

int stringIsCharAtInSet(String *string,int relativeIndex,char set[]){
	int i = 0;

	while(set[i] != 0){
		if(string->text->string[string->start+relativeIndex]==set[i]){
			return 1;
		}
		i++;
	}
	return 0;

}

char *stringSubstringInChar(String *string, int start,int length){

	char *charText = malloc(sizeof(char)*(length+1));
	int i = start,j = 0;
	if(length>string->length){
		return " ";
	}else{
		while(i<length+start){
			charText[j] = string->text->string[i];
			i++;
			j++;
		}
	}
	charText[j] = 0;
	return charText;
}

Text *stringSubstringInText(String *string,int start,int length){
	char *charStr = stringSubstringInChar(string,start,length);
	Text *text = textNew(charStr);
	free(charStr);
	return text;
}

int stringToInteger(String *string){
	int starter,lengther,integerChar;
	starter = string->start;
	lengther = string->length;
	
	char *charStr = stringSubstringInChar(string,starter,lengther); 
	integerChar = atoi(charStr);
	
	free(charStr);
	
	return integerChar;
}




