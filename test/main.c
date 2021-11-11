#include <unity.h>
#include <esp_log.h>
#include <ultrasonic.h>

#define US_ECHO_PIN 12
#define US_TRIGGER_PIN 13
#define MAX_US_RANGE 5000U

static const ultrasonic_sensor_t g_ultrasonic = {US_TRIGGER_PIN, US_ECHO_PIN};

void test_ultrasonic_sensor(void)
{
    uint32_t fullness;
    ultrasonic_init(&g_ultrasonic);

    ultrasonic_measure_cm(&g_ultrasonic, MAX_US_RANGE, &fullness);
    ESP_LOGI("WasteWatcherTest", "Measured: %d", fullness);
    TEST_ASSERT_TRUE(fullness > 0);
}

void app_main()
{
    UNITY_BEGIN();

    RUN_TEST(test_ultrasonic_sensor);

    UNITY_END();
}