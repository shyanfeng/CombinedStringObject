#include "unity.h"
#include "StringObject.h"


typedef struct FakeText{

 uint32 reference;

 char string[80];

}FakeText;



void setUp(void){}

void tearDown(void){}



void test_stringDump_explore(void){

  FakeText fakeText = {

   .reference = 10,

   .string = "hello world"

  };

  String str = {

   .reference = 20,

   .text = (Text *)&fakeText,

   .start = 0,

   .length = 100

  };

  stringDump(&str);

}



void test_textDump_explore(void){

  FakeText fakeText = {

   .reference = 3,

   .string = "dummy"

  };



  textDump((Text *)&fakeText);

}



void test_textNew_copy_character_to_string(void){

  Text *name1;

  name1 = textNew("Bye");

  textDump(name1);



  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

}



void test_textAssign_assign_character(void){

  Text *name1 = (Text *)"\x00\x00\00\x80""HAHA";

  Text *name2;

  Text *name3;

  textDump(name1);

  name2 = textNew("Bye");

  textDump(name2);

  name3 = textAssign(name2);

  textDump(name2);

  textDump(name3);



  UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name3->reference)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

}





void test_textDel_text_dynamic_delete_1(void){

  Text *name2;

  Text *name3;

  name2 = textNew("Bye");

  textDump(name2);

  name3 = textAssign(name2);

  textDump(name2);

  textDump(name3);

  name3 = textDel(name3);

  textDump(name3);



  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_text_dynamic_NULL(void){

  Text *name2;

  Text *name3;

  name2 = textNew("AAA");

  textDump(name2);

  name3 = textAssign(name2);

  textDump(name2);

  textDump(name3);

  name3 = textDel(name3);

  textDump(name3);

  name2 = textDel(name2);

  textDump(name2);





  if ((((name2)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)88);;};

}



void test_stringNew(void){

  Text *new = textNew("VVV");

  textDump(new);

  String *string = stringNew(new);

  stringDump(string);

  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

}



void test_stringAssign(void){

  Text *new = textNew("VVV");

  textDump(new);

  String *string1 = stringNew(new);

  stringDump(string1);

  String *string2 = stringAssign(string1);

  stringDump(string2);



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDel_1(void){

  Text *new = textNew("VVV");

  textDump(new);

  String *string1 = stringNew(new);

  stringDump(string1);

  String *string2 = stringAssign(string1);

  stringDump(string2);

  string1 = stringDel(string1);

  stringDump(string1);



  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);



}



void test_stringDel_null(void){

  Text *new = textNew("VVV");

  textDump(new);

  String *string1 = stringNew(new);

  stringDump(string1);

  String *string2 = stringAssign(string1);

  stringDump(string2);

  string1 = stringDel(string1);

  stringDump(string1);

  string2 = stringDel(string2);

  stringDump(string2);



  if ((((string2)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)139);;};

}



void test_stringSkip(void){



  String *string1 = stringNew(textNew("VVV"));

  stringSkip(string1,2);

  stringDump(string1);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);



}



void test_stringTrimLeft(void){



  String *string1 = stringNew(textNew("   VVV"));

  stringTrimLeft(string1);

  stringDump(string1);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight(void){



  String *string12 = stringNew(textNew("aaa           "));

  stringTrimRight(string12);

  stringDump(string12);

  UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((string12->start)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string12->length)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim(void){



  String *string1 = stringNew(textNew("   VVV  "));

  stringTrim(string1);

  stringDump(string1);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)176, UNITY_DISPLAY_STYLE_INT);

}
