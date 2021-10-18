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

void app_main()
{
    while (1)
    {
        ESP_LOGI("WasteWatcher", "Hello");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

/*** end of file ***/