/**
 * @file fullness.h
 * @author ZotBins
 *
 * @brief Functions relating to measuring the fullness of the waste bin
 *
 */

#ifndef FULLNESS_H
#define FULLNESS_H

#include <stdbool.h>
#include <driver/gpio.h>

// GPIO Pins for Ultrasonic Sensor
#define US_ECHO_PIN 12
#define US_TRIGGER_PIN 13

bool fullness_init(void);
bool fullness_measure(float *p_distance);

#endif /* FULLNESS_H */

/*** end of file ***/