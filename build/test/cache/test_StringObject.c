#include "unity.h"
#include "Text.h"
#include "StringObject.h"
#include "String.h"
#include "CustomTypeAssert.h"




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



void test_stringNew_dynamic(void){

  Text *new = textNew("ok");

  String *string = stringNew(new);

  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);

}



void test_stringNew_static(void){

  Text *new = (Text *)"\x00\x00\x00\x80""Haiz";

  String *string = stringNew(new);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((string->start)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x04)), (_U_SINT)((string->length)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);



}



void test_stringAssign(void){

  Text *new = textNew("VVV");

  String *string1 = stringNew(new);

  String *string2 = stringAssign(string1);



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDel_1(void){

  Text *new = textNew("VVV");

  String *string1 = stringNew(new);

  String *string2 = stringAssign(string1);

  string1 = stringDel(string1);



  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);



}



void test_stringDel_null(void){

  Text *new = textNew("VVV");

  String *string1 = stringNew(new);

  String *string2 = stringAssign(string1);

  string1 = stringDel(string1);

  string2 = stringDel(string2);



  if ((((string2)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)72);;};

}





void test_stringSkip(void){



  String *string1 = stringNew(textNew("VVV"));



  stringSkip(string1,2);

  stringDump(string1);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);



}



void test_stringTrimLeft(void){



  String *string1 = stringNew(textNew("   VVV"));

  stringTrimLeft(string1);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

}







void test_stringTrimRight(void){



  String *string12 = stringNew(textNew("aaa           "));

  stringTrimRight(string12);

  UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((string12->start)), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string12->length)), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

}







void test_stringTrim(void){



  String *string1 = stringNew(textNew("   VVV  "));

  stringTrim(string1);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

}





void test_stringRemoveChar(void){

  char character;

  String *string1 = stringNew(textNew("a"));

  stringRemoveChar(string1);

  character = stringRemoveChar(string1);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((character)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);

}



void test_stringLength(void){

  char character;

  String *string1 = stringNew(textNew("aliaaa"));

  character = stringLength(string1);



  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining(void){



  Text *new = textNew("abcdefghi");

  String *string1 = stringNew(new);

  String *a = stringRemoveWordNotContaining(string1,"ei");



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((a->start)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((a->length)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_Bulldog(void){

    Text *name = textNew("Bulldog");

          String *string1 = stringNew(name);

          String *string2 = stringRemoveWordNotContaining(string1 , "gd");





  assertStringEqual(("dog"), (string1), 152, ((void *)0));

        assertStringEqual(("Bull"), (string2), 153, ((void *)0));

}



void test_stringRemoveWordNotContaining_Pearson(void){



    Text *name = textNew("Pearson");

          String *string1 = stringNew(name);

          String *string2 = stringRemoveWordNotContaining(string1 , "rs");





          UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);



}



void test_stringRemoveWordNotContaining_baskinrobbin(void){

   Text *name = textNew("BaskinRobbin");

          String *string1 = stringNew(name);

          string1->start++;

          string1->length--;

          String *string2 = stringRemoveWordNotContaining(string1,"onb");



   assertStringEqual(("aski"), (string2), 174, ((void *)0));

   assertStringEqual(("nRobbin"), (string1), 175, ((void *)0));



}



void test_stringRemoveWordContaining(void){



  Text *new = textNew("abc123");

  String *string1 = stringNew(new);

  String *a = stringRemoveWordContaining(string1,"cba");

  stringDump(a);

  stringDump(string1);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((a->start)), (((void *)0)), (_U_UINT)187, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((a->length)), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)190, UNITY_DISPLAY_STYLE_INT);



}



void test_stringIsEqual(void){

  int input;

  Text *name2;

  Text *name3;

  name2 = textNew("samsung");

  String *string1 = stringNew(name2);

  string1->start = string1->start+3;

  string1->length = string1->length-3;

  name3 = textNew("sung");

  String *string2 = stringNew(name3);



  input = stringIsEqual(string1,string2);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_INT);



}



void test_stringIsEqualCaseInsensitive(void){

  int input;

  Text *name2;

  Text *name3;

  name2 = textNew("HAlo");

  String *string1 = stringNew(name2);

  name3 = textNew("halO");

  String *string2 = stringNew(name3);



  input = stringIsEqualCaseInsensitive(string1,string2);

  stringDump(string1);

  stringDump(string2);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);



}



void test_stringCharAt(void){

  Text *new = textNew("he&lo");

  String *string1 = stringNew(new);

  string1->start = 0;



  stringDump(string1);



  UnityAssertEqualNumber((_U_SINT)(('&')), (_U_SINT)((stringCharAt(string1,2))), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsCharAtInSet(void){

  Text *new = textNew("hello");

  String *string1 = stringNew(new);

  string1->start = 0;





  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringIsCharAtInSet(string1,1,"efg"))), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSubstringInChar(void){

  Text *new = textNew("abc12");

  String *string = stringNew(new);

  printf("%s\n",stringSubstringInChar(string,0,5));

  UnityAssertEqualString((const char*)(" "), (const char*)(stringSubstringInChar(string,0,6)), (((void *)0)), (_U_UINT)251);

}



void test_stringSubstringInText(void){

  Text *new = textNew("abc12");

  String *string = stringNew(new);

  Text *news = stringSubstringInText(string,0,2);



  UnityAssertEqualString((const char*)("ab"), (const char*)(news->string), (((void *)0)), (_U_UINT)259);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((news->reference)), (((void *)0)), (_U_UINT)260, UNITY_DISPLAY_STYLE_INT);

}



void test_stringToInteger(void){

  int a;

  Text *new = textNew("abc12");

  String *string = stringNew(new);

  string->start = 3;

  string->length = 2;

  a = stringToInteger(string);



  UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((a)), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_INT);

}
