#include <stdio.h>
#include <malloc.h>
#include "String.h"
#include "Text.h"

void textDump(Text *text){
	if(text== NULL){
		printf("(NULL)");
		return;
	}
	printf("text[%d]:%s\n",
			text->reference,text->string);
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