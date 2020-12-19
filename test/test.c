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
* Test for the object has tag function
*/
void test_object_has_tag_function(void)
{
   TEST_ASSERT_EQUAL_INT(1, object_has_tag(clock, "clock"));
}

/**
* Test for the list of objects at location function
*/
void test_list_objects_at_location_function(void)
{
   TEST_ASSERT_EQUAL_INT(5, list_objects_at_location(stage1, visible_object));
}

/**
* Test for the parse and execute function
* different inputs were tried with this function
*/
void test_parse_and_execute_function(void)
{
    char input[15] = "look around";

   TEST_ASSERT_EQUAL_INT(0, parse_and_execute("quit"));

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
* Test for the execute and leave function
*/
void test_execute_leave_function(void)
{
   TEST_ASSERT_EQUAL_INT(1,execute_leave());
}


/**
* Test for the execute and open function
*/
void test_execute_open_function(void)
{
   char input[6] = "open";
   TEST_ASSERT_EQUAL_INT(1,execute_open(input));
}


int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_object_has_tag_function);
RUN_TEST(test_list_objects_at_location_function);
RUN_TEST(test_parse_and_execute_function);
RUN_TEST(test_execute_leave_function);
RUN_TEST(test_execute_open_function);

return UNITY_END();
}
