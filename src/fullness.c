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
 * @return ESP_OK on success
 */
esp_err_t
fullness_init (void)
{
    return ultrasonic_init(&g_ultrasonic);
}

/**
 * @brief Measures the fullness of the waste bin (in cm).
 *
 * Returns ESP_OK if the ultrasonic sensor successfully measured the distance
 *
 *
 * @param p_distance Pointer to uint32_t that contains the distance (in cm)
 * @return ESP_OK if ultrasonic sensor successfully measures distance, otherwise:
 *         ESP_ERR_ULTRASONIC_PING - ultrasonic sensor cannot ping
 *         ESP_ERR_ULTRASONIC_PING_TIMEOUT - Device is not responding
 *         ESP_ERR_ULTRASONIC_ECHO_TIMEOUT - Distance is too big or wave is scattered
 */
esp_err_t
fullness_measure (uint32_t *p_distance)
{
    esp_err_t res = ultrasonic_measure_cm(&g_ultrasonic, MAX_US_RANGE, p_distance); //measures distance

    switch (res)
    {
        case ESP_ERR_ULTRASONIC_PING:
            ESP_LOGE("Fullness", "Cannot ping (device is in invalid state)");
            break;
        case ESP_ERR_ULTRASONIC_PING_TIMEOUT:
            ESP_LOGE("Fullness", "Ping timeout (no device found)");
            break;
        case ESP_ERR_ULTRASONIC_ECHO_TIMEOUT:
            ESP_LOGE("Fullness", "Echo timeout (i.e. distance too big)");
            break;
        case ESP_OK:
            break;
        default:
            ESP_LOGE("Fullness", "%s", esp_err_to_name(res));
    }

    return res;
}

/*** end of file ***/