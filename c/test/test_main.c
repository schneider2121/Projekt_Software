#include "unity.h"
#include "greeting.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_get_greeting_returns_hello_world(void) {
    TEST_ASSERT_EQUAL_STRING("Hello, World!", get_greeting());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_get_greeting_returns_hello_world);
    return UNITY_END();
}