# Esp32-s3 on board RGB led test guide

#### First 
- the most important file in this is the platformio.ini
- make sure its configured like this using devkitc-1

```ini
; PlatformIO Project Configuration File
;
;   Build options: build flags, source filter
;   Upload options: custom upload port, speed and extra flags
;   Library options: dependencies, extra library storages
;   Advanced options: extra scripting
;
; Please visit documentation for the other options and examples
; https://docs.platformio.org/page/projectconf.html

[env:esp32-s3-devkitc-1]
platform = espressif32
board = esp32-s3-devkitc-1
framework = arduino

monitor_speed = 115200

; monitor_dtr and monitor_rts are just for setting print conditions to the monitor
monitor_rts = 0

monitor_dtr = 0

;build flags defines the mode that the usb connection need to be in 
build_flags = 
    -DARDUINO_USB_MODE=1
    -DARDUINO_USB_CDC_ON_BOOT=1

```


#### In src/main.cpp

```cpp
#include <Arduino.h>

#define PIN 48 // use pin 48 for on board RGB LED
void setup(){
  Serial.begin(115200); // same buad rate on ./platformio.ini
}

void loop(){
  Serial.println("WHAT!!!!"); // just to check that the printing works

  // an lsp server or IDE like VScode may alert to neopixelWrite being outdated if so use what it recommends
  // neopixelWrite is part of the std lib of Arduino.h
  // neopixelWrite uses unsigned 8-bit range 0-255
  // so [255, 255, 255] is white 
  neopixelWrite(PIN, 0, 0, 32); // blue
  delay(500);
  neopixelWrite(PIN, 0, 32, 0); // green
  delay(500);
  neopixelWrite(PIN, 32, 0, 0); // red 
  delay(500);
}

```

## File structure (yes this matters kinda)
- files are located in these paths check the source code above if needed
./src/main.cpp
./platformio.ini

- for a better visual see [./lib/README](./lib/README)for a file tree example


## Build and run and that should be it 
- just make sure the [boot] button is being pressed when compiled and that the usb-c port is being used not uart port

















