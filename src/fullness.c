/**
 * @file fullness.c
 * @author ZotBins
 *
 * @brief Functions relating to measuring the fullness of the waste bin
 *
 */

#include <ultrasonic.h>
#include <esp_log.h>
#include "fullness.h"
#include "config.h"

// GPIO Pins for Ultrasonic Sensor
#define US_ECHO_PIN 12
#define US_TRIGGER_PIN 13

static const ultrasonic_sensor_t g_ultrasonic = 
{
    .trigger_pin = US_TRIGGER_PIN, 
    .echo_pin = US_ECHO_PIN
};

/**
 * @brief Initializes fullness sensor with predefined pins
 *
 * @return True/False depending on the success of sensor initialization
 */
bool
fullness_init (void)
{
    
    gpio_set_direction(13, GPIO_MODE_OUTPUT);
    gpio_set_level(13, 1);

    return true;
    
    //return ultrasonic_init(&g_ultrasonic) == ESP_OK;
}

/**
 * @brief Measures the fullness of the waste bin (in cm).
 *
 * Returns True/False if sensor successfully measures distance.
 * If False, the value of p_distance is invalid and should not be used.
 *
 * @param p_distance Pointer to uint32_t that contains the distance (in cm)
 * @return True if fullness sensor successfully measured distance (p_distance is valid)
 * @return False if fullness sensor was unsuccessful (p_distance is invalid)
 *
 */
bool
fullness_measure (uint32_t *p_distance)
{
    esp_err_t res = ultrasonic_measure(&g_ultrasonic, MAX_US_RANGE, p_distance); //measures distance

    switch (res)
    {
        case ESP_ERR_ULTRASONIC_PING:
            ESP_LOGE("Fullness", "Cannot ping (device is in invalid state)\n");
            break;
        case ESP_ERR_ULTRASONIC_PING_TIMEOUT:
            ESP_LOGE("Fullness", "Ping timeout (no device found)\n");
            break;
        case ESP_ERR_ULTRASONIC_ECHO_TIMEOUT:
            ESP_LOGE("Fullness", "Echo timeout (i.e. distance too big)\n");
            break;
        case ESP_OK:
            ESP_LOGI("Fullness", "Measured Distance: %f\n", *p_distance);
            break;
        default:
            ESP_LOGE("Fullness", "%s\n", esp_err_to_name(res));
    }
    
    return res == ESP_OK;
}

/*** end of file ***/