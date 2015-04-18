#include "sampletestUtils.h"
#include "bracket_matching.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_expression_1_is_correct(){
	ASSERT(test_the_expression("(a*b)"));
}

void test_expression_2_is_incorrect(){
	ASSERT(test_the_expression("a+(b+c)/(x-y))(") == 0);
}

void test_expression_3_is_correct(){
	ASSERT(test_the_expression("((a+b(d-s)+((p*y)*z)+(s-a)))"));
}

void test_expression_4_is_correct(){
	ASSERT(test_the_expression("(a+(b+c)/(x-y))((a+b))"));
}

void test_expression_5_is_incorrect(){
	ASSERT(test_the_expression("a+(b+c))(") == 0);
}

void test_expression_6_is_incorrect(){
	ASSERT(test_the_expression("((a+(b+c))()") == 0);
}

void test_expression_7_is_incorrect(){
	ASSERT(test_the_expression("((a+(b+c))") == 0);
}

void test_expression_8_is_incorrect(){
	ASSERT(test_the_expression("a+(b+c)/(x-y))((a+b)") == 0);
}

void test_expression_9_is_correct(){
	ASSERT(test_the_expression("((a+b(d-s)+((p*y)*z)+(s-a)))"));
}