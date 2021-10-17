#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <ultrasonic.h>
#include <esp_log.h>

void app_main() 
{
    while (1)
    {
        ESP_LOGI("WasteWatcher", "Hello");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}