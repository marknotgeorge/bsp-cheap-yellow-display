# Cheap Yellow Display Board Support Package
A Board Support Package for the ESP32-2432S028R development board, also known as the ['Cheap Yellow Display (CYD)'](https://youtu.be/0AVyvwv0agk?si=KyBl3__vfIgNyeVE). 

The CYD has the following specifications:
* ESP32-WROOM-32 Module with 4MB Flash
* ~~ILI9341 2.8" 320x240 TFT screen with backlight~~ :construction: To be implemented
* ~~Resistive touch screen with XPT2046 controller~~  :construction: To be implemented
* ~~SC8002B audio amplifier with speaker connector (JST PH 2.0-2P)~~  :construction: To be implemented
* ~~Micro-SD card slot~~  :construction: To be implemented
* ~~GT36516 photo-resistor connected to the ESP32's ADC~~  :construction: To be implemented
* MHP5050 RGB LED
* ~~Socket for DHT-11 temperature & humidity sensor ([HCTL HC-1.25-4PWT](https://wmsc.lcsc.com/wmsc/upload/file/pdf/v2/lcsc/2312192331_HCTL-HC-1-25-4PWT_C2845381.pdf))~~  :construction: To be implemented
* ~~I2C connector (HCTL HC-1.25-4PWT)~~  :construction: To be implemented


## Using the component

** The following won't work until the package is uploaded to the Espressif Component Registry:

If you have an existing ESP-IDF project you can run the following command to install the component:
```bash
idf.py add-dependency "igrr/arduino-nano-esp32"
```


## Example

This component includes the following examples:

### ~~display_lvgl_demos~~ :construction: To be implemented
WIP

### led-example
This example uses the built-in RGB LED and the boot button. Press the boot button to cycle through the patterns.


## Licence
This component is provided under Apache 2.0 licence, see [LICENCE](LICENSE.md) file for details.
