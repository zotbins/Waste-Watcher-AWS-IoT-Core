/**
 * @file photo.h
 * @author ZotBins
 *
 * @brief Functions relating to taking photos of the waste bin
 *
 */
#ifndef PHOTO_H
#define PHOTO_H

#include <esp_err.h>

// GPIO pin for camera flash LED
#define FLASH_PIN 4

esp_err_t flash_init(void);
esp_err_t flash_toggle(bool b_on);

esp_err_t camera_init(void);
esp_err_t camera_capture(void);

#endif /* PHOTO_H */

/*** end of file ***/