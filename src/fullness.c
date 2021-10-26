/**
 * @file fullness.c
 * @author ZotBins
 *
 * @brief Functions relating to measuring the fullness of the waste bin
 *
 */

#include "fullness.h"
#include "config.h"
//#include "ultrasonic.h"
#include <ultrasonic.h>

static const ultrasonic_sensor_t g_ultrasonic = {US_TRIGGER_PIN, US_ECHO_PIN};

/**
 * @brief Initializes fullness sensor with predefined pins
 *
 * @return True/False depending on the success of sensor initialization
 */
bool fullness_init(void)
{   
    if (ultrasonic_init(&g_ultrasonic) == ESP_OK) //checks if it successfully initialized
    {
        return true;
    }
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
    //*p_distance = 0;

    esp_err_t res = ultrasonic_measure(&g_ultrasonic, MAX_US_RANGE, p_distance); //measures distance

    if (res != ESP_OK)
    {
        printf("ERROR %d: ", res);

        switch (res)
            {
                case ESP_ERR_ULTRASONIC_PING:
                    printf("Cannot ping (device is in invalid state)\n");
                    break;
                case ESP_ERR_ULTRASONIC_PING_TIMEOUT:
                    printf("Ping timeout (no device found)\n");
                    break;
                case ESP_ERR_ULTRASONIC_ECHO_TIMEOUT:
                    printf("Echo timeout (i.e. distance too big)\n");
                    break;
                default:
                    printf("%s\n", esp_err_to_name(res));
            }
    }
    else
    {
        //printf("Distance: %x\n", (void *) p_distance);
        //printf("Distance: %0.04f m\n", p_distance);
        printf("bruh");
    }


    return false;
}

/*** end of file ***/