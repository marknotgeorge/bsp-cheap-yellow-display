#include <stdio.h>
#include "bsp/esp-bsp.h"
#include "esp_log.h"
#include "led_indicator_blink_default.h"

static const char *TAG = "LED_EXAMPLE";

static led_indicator_handle_t leds[BSP_LED_NUM];

void app_main(void)
{
    // Initialise LED
    ESP_ERROR_CHECK(bsp_led_indicator_create(leds, NULL, BSP_LED_NUM));

    ESP_LOGI(TAG, "LED example starting...");
    // Start LED effect
    ESP_ERROR_CHECK(led_indicator_start(leds[0], BSP_LED_BREATHE_SLOW));
}
