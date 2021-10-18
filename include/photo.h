/**
 * @file photo.h
 * @author ZotBins
 *
 * @brief Functions relating to taking photos of the waste bin
 *
 */
#ifndef PHOTO_H
#define PHOTO_H

#include <stdbool.h>

// GPIO pin for camera flash LED
#define FLASH_PIN 4

bool flash_init(void);
bool flash_toggle(bool b_on);

bool camera_init(void);
bool camera_capture(void);

#endif /* PHOTO_H */

/*** end of file ***/