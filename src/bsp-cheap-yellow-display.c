// SPDX-FileCopyrightText : 2024 Mark Johnson
// SPDX-License - Identifier : Apache-2.0

#include <stdio.h>
#include "esp_vfs_fat.h"
#include "esp_log.h"
#include "esp_check.h"
#include "esp_spiffs.h"

#if (CONFIG_BSP_NO_GRAPHIC_LIB == 0)
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/spi_master.h"
#endif // CONFIG_BSP_NO_GRAPHIC_LIB == 0

#include "driver/ledc.h"

#include "iot_button.h"
#include "led_indicator.h"
#include "bsp/bsp-cheap-yellow-display.h"
#include "bsp/display.h"
#include "bsp_err_check.h"

extern blink_step_t const *bsp_led_blink_defaults_lists[];

static led_indicator_rgb_config_t bsp_led_rgb_config = {
    .is_active_level_high = false, // LEDC active low
    .timer_inited = false,
    .timer_num = LEDC_TIMER_0,
    .red_gpio_num = BSP_LED_RED,
    .green_gpio_num = BSP_LED_GREEN,
    .blue_gpio_num = BSP_LED_BLUE,
    .red_channel = LEDC_CHANNEL_0,
    .green_channel = LEDC_CHANNEL_1,
    .blue_channel = LEDC_CHANNEL_2,
};

static const led_indicator_config_t bsp_led_config = {
    .mode = LED_RGB_MODE,
    .led_indicator_rgb_config = &bsp_led_rgb_config,
    .blink_lists = bsp_led_blink_defaults_lists,
    .blink_list_num = BSP_LED_MAX};

esp_err_t bsp_led_indicator_create(led_indicator_handle_t led_array[], int *led_cnt, int led_array_size)
{
    if (led_array_size < BSP_LED_NUM || led_array == NULL)
    {
        return ESP_ERR_INVALID_ARG;
    }

    if (led_cnt)
    {
        *led_cnt = 0;
    }

    led_array[0] = led_indicator_create(&bsp_led_config);
    if (led_array[0] == NULL)
    {
        return ESP_FAIL;
    }

    if (led_cnt)
    {
        *led_cnt = 1;
    }
    return ESP_OK;
}
