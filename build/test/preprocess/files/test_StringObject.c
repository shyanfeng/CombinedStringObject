#include "unity.h"
#include "Text.h"
#include "StringObject.h"
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



void test_textDump_explore(void){

  FakeText fakeText = {

   .reference = 3,

   .string = "dummy"

  };



  textDump((Text *)&fakeText);

}



void test_textNew_copy_character_to_string_dynamic(void){

  Text *name1;

  name1 = textNew("Bye");

  textDump(name1);



  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

}



void test_textNew_copy_character_to_string_static(void){

  Text *name1;

  name1 = (Text *)"\x00\x00\00\x80""Haha";





  UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

}



void test_textAssign_assign_character(void){

  Text *name1 = (Text *)"\x00\x00\00\x80""HAHA";

  Text *name2;

  Text *name3;

  name2 = textNew("Bye");

  name3 = textAssign(name2);



  UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name3->reference)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

}



void test_textAssign_assign_character_static(void){

  Text *name1 = (Text *)"\x00\x00\00\x80""HeHA";

  Text *name2;

     name2 = textAssign(name1);

  UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((name2->reference)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_HEX32);

}





void test_textDel_text_dynamic_delete_1(void){

  Text *name2;

  Text *name3;

  name2 = textNew("zzz");

  name3 = textAssign(name2);

  name3 = textDel(name3);





  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((name2->reference)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_text_static(void){

  Text *name = (Text *)"\x00\x00\00\x80""Come";

  Text *name1 = textDel(name);

  UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((name1->reference)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

}





void test_textDel_text_dynamic_NULL(void){

  Text *name2;

  Text *name3;

  name2 = textNew("AAA");

  name3 = textAssign(name2);

  name3 = textDel(name3);

  name2 = textDel(name2);



  if ((((name2)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)98);;};

}



void test_stringNew_dynamic(void){

  Text *new = textNew("ok");

  String *string = stringNew(new);

  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

}



void test_stringNew_static(void){

  Text *new = (Text *)"\x00\x00\00\x80""Haiz";

  String *string = stringNew(new);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((string->reference)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((string->start)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x04)), (_U_SINT)((string->length)), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);



}



void test_stringAssign(void){

  Text *new = textNew("VVV");

  String *string1 = stringNew(new);

  String *string2 = stringAssign(string1);



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string2->reference)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((new->reference)), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDel_1(void){

  Text *new = textNew("VVV");

  String *string1 = stringNew(new);

  String *string2 = stringAssign(string1);

  string1 = stringDel(string1);



  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string1->reference)), (((void *)0)), (_U_UINT)133, UNITY_DISPLAY_STYLE_INT);



}



void test_stringDel_null(void){

  Text *new = textNew("VVV");

  String *string1 = stringNew(new);

  String *string2 = stringAssign(string1);

  string1 = stringDel(string1);

  string2 = stringDel(string2);



  if ((((string2)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)144);;};

}





void test_stringSkip(void){



  String *string1 = stringNew(textNew("VVV"));

  stringSkip(string1,2);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_INT);



}



void test_stringTrimLeft(void){



  String *string1 = stringNew(textNew("   VVV"));

  stringTrimLeft(string1);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight(void){



  String *string12 = stringNew(textNew("aaa           "));

  stringTrimRight(string12);

  UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((string12->start)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string12->length)), (((void *)0)), (_U_UINT)170, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim(void){



  String *string1 = stringNew(textNew("   VVV  "));

  stringTrim(string1);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)178, UNITY_DISPLAY_STYLE_INT);

}





void test_stringRemoveChar(void){

  char character;

  String *string1 = stringNew(textNew("a"));

  stringRemoveChar(string1);

  character = stringRemoveChar(string1);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((character)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

}



void test_stringLength(void){

  char character;

  String *string1 = stringNew(textNew("aliaaa"));

  character = stringLength(string1);



  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining(void){



  Text *new = textNew("abcdefghi");

  String *string1 = stringNew(new);

  String *a = stringRemoveWordNotContaining(string1,"ei");



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((a->start)), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((a->length)), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_Bulldog(void){

    Text *name = textNew("Bulldog");

          String *string1 = stringNew(name);

          String *string2 = stringRemoveWordNotContaining(string1 , "gd");





  assertStringEqual(("dog"), (string1), 218, ((void *)0));

        assertStringEqual(("Bull"), (string2), 219, ((void *)0));

}



void test_stringRemoveWordNotContaining_Pearson(void){



    Text *name = textNew("Pearson");

          String *string1 = stringNew(name);

          String *string2 = stringRemoveWordNotContaining(string1 , "rs");





          UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_INT);



}



void test_stringRemoveWordNotContaining_baskinrobbin(void){

   Text *name = textNew("BaskinRobbin");

          String *string1 = stringNew(name);

          string1->start++;

          string1->length--;

          String *string2 = stringRemoveWordNotContaining(string1,"onb");



   assertStringEqual(("aski"), (string2), 240, ((void *)0));

   assertStringEqual(("nRobbin"), (string1), 241, ((void *)0));



}



void test_stringRemoveWordContaining(void){



  Text *new = textNew("1234ABCD56");

  String *string1 = stringNew(new);

  String *a = stringRemoveWordContaining(string1,"3214");

  stringDump(a);

  stringDump(string1);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((a->start)), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((a->length)), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((string1->start)), (((void *)0)), (_U_UINT)255, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((string1->length)), (((void *)0)), (_U_UINT)256, UNITY_DISPLAY_STYLE_INT);



}



void test_stringlsEqual(void){

  int input;

  Text *name2;

  Text *name3;

  name2 = textNew("samsung");

  String *string1 = stringNew(name2);

  string1->start = string1->start+3;

  string1->length = string1->length-3;

  name3 = textNew("sung");

  String *string2 = stringNew(name3);



  input = stringlsEqual(string1,string2);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)273, UNITY_DISPLAY_STYLE_INT);



}



void test_stringlsEqualCaseInsensitive(void){

  int input;

  Text *name2;

  Text *name3;

  name2 = textNew("HAlo");

  String *string1 = stringNew(name2);

  name3 = textNew("halO");

  String *string2 = stringNew(name3);



  input = stringlsEqualCaseInsensitive(string1,string2);

  stringDump(string1);

  stringDump(string2);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((input)), (((void *)0)), (_U_UINT)290, UNITY_DISPLAY_STYLE_INT);



}



void test_stringCharAt(void){

  Text *new = textNew("hello");

  String *string1 = stringNew(new);

  string1->start = 0;



  stringDump(string1);



  UnityAssertEqualNumber((_U_SINT)(('l')), (_U_SINT)((stringCharAt(string1,2))), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsCharAtInSet(void){

  Text *new = textNew("hello");

  String *string1 = stringNew(new);

  string1->start = 0;





  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringIsCharAtInSet(string1,1,"efg"))), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

}
