#include "unity.h"
#include "Text.h"

void setUp(void){}
void tearDown(void){}



void test_textNew_copy_character_to_string_dynamic(void){
		Text *name1;
		name1 = textNew("Bye");

		
		TEST_ASSERT_EQUAL(0x01,name1->reference);
}

void test_textNew_copy_character_to_string_static(void){
		Text *name1;
		name1 = t"Haha";
	
		
		TEST_ASSERT_EQUAL(0x80000000,name1->reference);
}

void test_textAssign_assign_character(void){
		Text *name1 = t"HAHA";
		Text *name2;
		Text *name3;
		name2 = textNew("Bye");
		name3 = textAssign(name2);
			
		TEST_ASSERT_EQUAL(0x80000000,name1->reference);
		TEST_ASSERT_EQUAL(0x02,name3->reference);
		TEST_ASSERT_EQUAL(0x02,name2->reference);
}

void test_textAssign_assign_character_static(void){
		Text *name1 = t"HeHA";
		Text *name2;
	    name2 = textAssign(name1);
		TEST_ASSERT_EQUAL_HEX32(0x80000000,name2->reference);
}


void test_textDel_text_dynamic_delete_1(void){	
		Text *name2;
		Text *name3;
		name2 = textNew("zzz");
		name3 = textAssign(name2);
		name3 = textDel(name3);

		
		TEST_ASSERT_EQUAL(0x01,name2->reference);			
}

void test_textDel_text_static(void){
		Text *name = t"Come";
		Text *name1 = textDel(name);
		TEST_ASSERT_EQUAL(0x80000000,name1->reference);		
}


void test_textDel_text_dynamic_NULL(void){	
		Text *name2;
		Text *name3;
		name2 = textNew("AAA");
		name3 = textAssign(name2);
		name3 = textDel(name3);
		name2 = textDel(name2);
		
		TEST_ASSERT_NULL(name2);			
}