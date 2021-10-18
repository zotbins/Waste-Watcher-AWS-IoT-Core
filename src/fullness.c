/**
 * @file fullness.c
 * @author ZotBins
 *
 * @brief Functions relating to measuring the fullness of the waste bin
 *
 */

#include "fullness.h"
#include <ultrasonic.h>

static const ultrasonic_sensor_t g_ultrasonic = {US_TRIGGER_PIN, US_ECHO_PIN};

/**
 * @brief Initializes fullness sensor with predefined pins
 *
 * @return True/False depending on the success of sensor initialization
 */
bool fullness_init(void)
{
    // TODO: REMOVE THIS, ADDED TO REMOVE COMPLIER WARNING
    (void) g_ultrasonic;
    return false;
}

/**
 * @brief Measures the fullness of the waste bin (in cm).
 *
 * Returns True/False if sensor successfully measures distance.
 * If False, the value of p_distance is invalid and should not be used.
 *
 * @param p_distance Pointer to float that contains the distance (in cm)
 * @return True if fullness sensor successfully measured distance (p_distance is valid)
 * @return False if fullness sensor was unsuccessful (p_distance is invalid)
 *
 */
bool fullness_measure(float *p_distance)
{
    *p_distance = 0;
    return false;
}

/*** end of file ***/