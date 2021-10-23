/**
 * @file photo.c
 * @author ZotBins
 *
 * @brief Functions relating to taking photos of the waste bin
 *
 */
#include "photo.h"

/**
 * @brief Initalize flash LED
 *
 * @return True/False if flash is successfully initialized
 */
bool
flash_init (void)
{
    return false;
}

/**
 * @brief Toggles the camera flash
 *
 * @param b_status True/False if the flash should be on/off
 * @return True/False depending if the flash successfully changed state
 */
bool
flash_toggle (bool b_on)
{
    return false;
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