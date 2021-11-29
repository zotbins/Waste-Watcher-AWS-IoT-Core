/**
 * @file fullness.h
 * @author ZotBins
 *
 * @brief Functions relating to measuring the fullness of the waste bin
 *
 */

#ifndef FULLNESS_H
#define FULLNESS_H

#include <esp_err.h>

esp_err_t fullness_init(void);
esp_err_t fullness_measure(uint32_t *p_distance);

#endif /* FULLNESS_H */

/*** end of file ***/