#include <string.h>
#include "unity.h"
#include "object.h"
#include "arghandling.h"
#include "execution.h"
#include "helper.h"
#include "parsenexec.h"
#include "puzzle.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

/**
* Test for the object has tag function with a correct tag
*/
void test_object_has_tag_function_correct_tag(void)
{
   TEST_ASSERT_EQUAL_INT(1, object_has_tag(clock, "clock"));
}

/**
* Test for the object has tag function with an incorrect tag
*/
void test_object_has_tag_function_wrong_tag(void)
{
   TEST_ASSERT_EQUAL_INT(0, object_has_tag(clock, "wine"));
}


/**
* Test for the list of objects at location function
*/
void test_list_objects_at_location_function(void)
{
   TEST_ASSERT_EQUAL_INT(5, list_objects_at_location(stage1, visible_object));
}

/**
* Test the parse and execute function
* different inputs that will return true were tried with this function
*/
void test_parse_and_execute_function_true_input(void)
{
    char input[15] = "look around";

   TEST_ASSERT_EQUAL_INT(1,parse_and_execute(input));

   strcpy(input,"");
   TEST_ASSERT_EQUAL_INT(1,parse_and_execute(input));

   strcpy(input,"    ");
   TEST_ASSERT_EQUAL_INT(1,parse_and_execute(input));

   strcpy(input,"look:outside");
   TEST_ASSERT_EQUAL_INT(1,parse_and_execute(input));

   strcpy(input,"create key");
   TEST_ASSERT_EQUAL_INT(1,parse_and_execute(input));

}

/**
* Test for the parse and execute function
* with the input that will fail.
*/
void test_parse_and_execute_function_false_input(void)
{
   TEST_ASSERT_EQUAL_INT(0, parse_and_execute("quit"));
}

/**
* Test for the execute and leave function
*/
void test_execute_leave_function(void)
{
   TEST_ASSERT_EQUAL_INT(1,execute_leave());
}


/**
* Test for the execute and open function with the correct action verb
*/
void test_execute_open_function_right_verb(void)
{
   char input[6] = "open";
   TEST_ASSERT_EQUAL_INT(1,execute_open(input));
}

/**
* Test for the execute and open function with the incorrect action verb
*/
void test_execute_open_function_wrong_verb(void)
{
   char input[6] = "close";
   TEST_ASSERT_EQUAL_INT(1,execute_open(input));
}


int main(void)
{
UNITY_BEGIN();

RUN_TEST(test_object_has_tag_function_correct_tag);
printf("\n");
RUN_TEST(test_object_has_tag_function_wrong_tag);
printf("\n");
RUN_TEST(test_list_objects_at_location_function);
printf("\n");
RUN_TEST(test_parse_and_execute_function_true_input);
printf("\n");
RUN_TEST(test_parse_and_execute_function_false_input);
printf("\n");
RUN_TEST(test_execute_leave_function);
printf("\n");
RUN_TEST(test_execute_open_function_right_verb);
printf("\n");
RUN_TEST(test_execute_open_function_wrong_verb);

return UNITY_END();
}
