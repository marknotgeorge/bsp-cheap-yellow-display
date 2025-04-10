// SPDX-FileCopyrightText : 2024 Mark Johnson
// SPDX-License - Identifier : Apache-2.0

#pragma once

#include "sdkconfig.h"
#include "driver/gpio.h"
// #include "driver/sdmmc_host.h"

// #include "bsp/touch.h"
// #include "iot_button.h"
#include "led_indicator.h"

#if (BSP_CONFIG_NO_GRAPHIC_LIB == 0)
#include "bsp/display.h"
#include "lvgl.h"
#include "esp_lvgl_port.h"
#endif // BSP_CONFIG_NO_GRAPHIC_LIB == 0

/**************************************************************************************************
 *  BSP Capabilities
 **************************************************************************************************/

#if (CONFIG_BSP_NO_GRAPHIC_LIB == 0)
#define BSP_CAPS_DISPLAY 1
#endif // CONFIG_BSP_NO_GRAPHIC_LIB == 0

#define BSP_CAPS_TOUCH 1
#define BSP_CAPS_BUTTONS 1
#define BSP_CAPS_LEDS 1
#define BSP_CAPS_AUDIO 1
#define BSP_CAPS_AUDIO_SPEAKER 1
#define BSP_CAPS_AUDIO_MIC 0
#define BSP_CAPS_SDCARD 1
#define BSP_CAPS_IMU 0

/**************************************************************************************************
 *  CYD Pinout
 **************************************************************************************************/

// RGB LED
typedef enum bsp_led_t
{
    BSP_LED_RED = GPIO_NUM_4,
    BSP_LED_GREEN = GPIO_NUM_16,
    BSP_LED_BLUE = GPIO_NUM_17

} bsp_led_t;

#define BSP_LED_NUM (1)

#define BSP_LED_RED_CHANNEL CONFIG

// Display
#define BSP_LCD_SPI_MOSI (GPIO_NUM_13)
#define BSP_LCD_SPI_MISO (GPIO_NUM_12)
#define BSP_LCD_SPI_CLK (GPIO_NUM_14)
#define BSP_LCD_SPI_CS (GPIO_NUM_15)
#define BSP_LCD_DC (GPIO_NUM_2)
#define BSP_LCD_RST (GPIO_NUM_1)
#define BSP_LCD_BACKLIGHT (GPIO_NUM_21)

// uSD card
#define BSP_SD_MOSI (GPIO_NUM_23)
#define BSP_SD_MISO (GPIO_NUM_19)
#define BSP_SD_SCK (GPIO_NUM_18)
#define BSP_SD_CS (GPIO_NUM_5)

// Touch
#define BSP_TOUCH_IRQ (GPIO_NUM_36)
#define BSP_TOUCH_MOSI (GPIO_NUM_32)
#define BSP_TOUCH_MISO (GPIO_NUM_39)
#define BSP_TOUCH_CLK (GPIO_NUM_25)
#define BSP_TOUCH_CS (GPIO_NUM_33)

// I2C
#define BSP_I2C_SCL (GPIO_NUM_22)
#define BSP_I2C_SDA (GPIO_NUM_21)
#define BSP_I2C_GPIO (GPIO_NUM_35) // An extra pin in the I2C connector

// Audio
#define BSP_POWER_AMP_IO (GPIO_NUM_26)

// DHT-11
#define BSP_DHT_11_PIN (GPIO_NUM_27)

// Buttons
#define BSP_BUTTON_BOOT_IO (GPIO_NUM_0)

typedef enum
{
    BSP_BUTTON_BOOT
} bsp_button_t;

// Default LED effects
enum
{
    BSP_LED_ON,
    BSP_LED_OFF,
    BSP_LED_BLINK_FAST,
    BSP_LED_BLINK_SLOW,
    BSP_LED_BREATHE_FAST,
    BSP_LED_BREATHE_SLOW,
    BSP_LED_MAX,
};

#ifdef __cplusplus
extern "C"
{
#endif

    /// @brief Initialise all LEDs
    /// @note 'led_cnt' and 'led_array' unused - only one config needed to control LEDs
    /// @param[out] led_array Output LED array
    /// @param[out] led_cnt Number of LEDhandlers saved to led_array. Can be NULL
    /// @param led_array_size Size of output LED array. Must be at least BSP_LED_NUM
    /// @return - ESP_OK Success; ESP_ERR_INVALID_ARG Parameter error
    esp_err_t bsp_led_indicator_create(led_indicator_handle_t led_array[], int *led_cnt, int led_array_size);

#ifdef __cplusplus
}
#endif