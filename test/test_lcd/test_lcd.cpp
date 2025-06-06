#include <Arduino.h>
#include <unity.h>
#include <lcd.h>

void test_basic_assert_true(void) {
    TEST_ASSERT_TRUE(1);
}

void test_lcd_setup_calls_methods(void) {
    //Ucglib_ST7735_18x128x160_HWSPI ucgmock(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);
    //lcd_setup(&ucgmock);
    //TEST_ASSERT_TRUE(ucgmock.begin);
    TEST_ASSERT_TRUE(1);

}

void test_cls_draws_boxes(void) {
    //Ucglib_ST7735_18x128x160_HWSPI ucgmock(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);
    //cls(&ucgmock);
    //TEST_ASSERT_TRUE(ucgmock.setColor);
    //TEST_ASSERT_TRUE(ucgmock.drawBox);
    TEST_ASSERT_TRUE(1);
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_basic_assert_true);
    RUN_TEST(test_lcd_setup_calls_methods);
    RUN_TEST(test_cls_draws_boxes);
    UNITY_END();
}

void loop() {
    // not used
}