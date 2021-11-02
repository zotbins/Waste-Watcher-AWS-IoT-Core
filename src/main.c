/**
 * @file main.c
 * @author ZotBins
 *
 * @brief Main application program for the Waste Watcher
 *
 */

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include "fullness.h"

void app_main()
{
    // initialize fullness sensor for use
    float fullness;
    if (!fullness_init()) 
    {
        ESP_LOGE("WasteWatcher","Failed to init fullness sensor");
    }

    while (1)
    {
        fullness_measure(&fullness);
        ESP_LOGI("WasteWatcher", "Measured Distance: %f\n", fullness);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // delays by 1 second
    }
}

/*** end of file ***/