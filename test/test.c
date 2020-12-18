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

void test_object_has_tag_function(void)
{
   TEST_ASSERT_EQUAL_INT(1, object_has_tag(clock, "clock"));
}

void test_list_objects_at_location_function(void)
{
   TEST_ASSERT_EQUAL_INT(5, list_objects_at_location(stage1, visible_object));
}

void test_parse_and_execute_function(void)
{
   TEST_ASSERT_EQUAL_INT(0, parse_and_execute("quit"));
}

int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_object_has_tag_function);
RUN_TEST(test_list_objects_at_location_function);
RUN_TEST(test_parse_and_execute_function);

return UNITY_END();
}
