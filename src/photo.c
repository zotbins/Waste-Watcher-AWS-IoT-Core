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
 * @return True/False if flash is successfully initialized
 */
bool
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

    return gpio_config(&flash_config) == ESP_OK;
}

/**
 * @brief Toggles the camera flash
 *
 * @param b_on True/False if the flash should be on/off
 * @return True/False depending if the flash successfully changed state
 */
bool
flash_toggle (bool b_on)
{
    return gpio_set_level(FLASH_PIN, b_on) == ESP_OK;
}

/**
 * @brief Initalizes the ESP32 Camera
 *
 * @return True/False if succesfully initalizes the camera without errors
 */
bool
camera_init (void)
{
    return false;
}

/**
 * @brief Capture image
 *
 * @return True/False if the camera succesfully captured an image
 */
bool
camera_capture (void)
{
    return false;
}

/*** end of file ***/