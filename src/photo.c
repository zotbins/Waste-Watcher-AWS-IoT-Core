/**
 * @file photo.c
 * @author ZotBins
 *
 * @brief Functions relating to taking photos of the waste bin
 *
 */

#include <esp_log.h>
#include <driver/gpio.h>
#include "photo.h"

/**
 * @brief Initalize flash LED
 *
 * @return ESP_OK on success
 */
esp_err_t
flash_init (void)
{
    gpio_config_t flash_config =
    {
        .intr_type = GPIO_PIN_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << FLASH_PIN),
        .pull_down_en = 0,
        .pull_up_en = 0
    };

    return gpio_config(&flash_config);
}

/**
 * @brief Toggles the camera flash
 *
 * @param b_on True/False if the flash should be on/off
 * @return ESP_OK if the state of the flash LED successfully updated
 */
esp_err_t
flash_toggle (bool b_on)
{
    return gpio_set_level(FLASH_PIN, b_on);
}

/**
 * @brief Initalizes the ESP32 Camera
 *
 * @return ESP_OK if succesfully initalizes the camera without errors
 */
esp_err_t
camera_init (void)
{
    return false;
}

/**
 * @brief Capture image
 *
 * @return ESP_OK if the camera succesfully captured an image
 */
esp_err_t
camera_capture (void)
{
    return false;
}

/*** end of file ***/