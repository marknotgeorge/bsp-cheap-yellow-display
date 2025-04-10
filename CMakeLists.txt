idf_component_register(
                    SRCS "src/bsp-cheap-yellow-display.c" "src/led_blink_defaults.c"
                    INCLUDE_DIRS "include"
                    PRIV_INCLUDE_DIRS "priv_include"
                    REQUIRES driver esp_lcd
                    PRIV_REQUIRES fatfs spiffs)
