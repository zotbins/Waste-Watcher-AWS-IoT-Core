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
#include "photo.h"
#include "fullness.h"

void app_main()
{
    uint32_t fullness = 0;
    bool b_on = true;

    // Initialize sensors & periphericals
    ESP_ERROR_CHECK(fullness_init());
    ESP_ERROR_CHECK(flash_init());

    while (1)
    {
        fullness_measure(&fullness);
        ESP_LOGI("WasteWatcher", "Measured Distance: %d", fullness);

        flash_toggle(b_on);
        b_on = !b_on;

        vTaskDelay(1000 / portTICK_PERIOD_MS); // delays by 1 second
    }
}

/*** end of file ***/