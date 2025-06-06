#include <Arduino.h>
#include <unity.h>

void test_basic_assert_true(void) {
    TEST_ASSERT_TRUE(1);
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_basic_assert_true);
    UNITY_END();
}

void loop() {
    // not used
}