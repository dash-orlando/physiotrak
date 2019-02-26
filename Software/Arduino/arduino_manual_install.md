# Arduino / Manual Installation

> **NOTE:** The following installation instructions apply specifically to [**Adafruit's HUZZAH32-ESP32 Feather**](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather)

## Prepare the Arduino IDE
1.  Install the latest version of the [**Arduino IDE**](https://www.arduino.cc/en/Main/Software)
2.  Install the ESP-boards library using Boards Manager
    1.  Open the Arduino IDE
    2.  Go to `File > Prefrences`
    3.  On the `Preferences` window, add the following address under `Additional Boards Manager URLs:`
        ```
        https://adafruit.github.io/arduino-board-index/package_adafruit_index.json
        https://dl.espressif.com/dl/package_esp32_index.json
        ```
        Each entry on a new line, Hit OK!
    4.  Go to `Tools > Boards > Boards Manager`
    5.  On the `Boards Manager` window, search for `esp32` and download the latest libraries from `Espressif Systems`
3.  Install **Adafruit's MQTT Libraries**

#### References
1. [**Setting up a Raspberry Pi as an access point in a standalone network (NAT)**](https://www.raspberrypi.org/documentation/configuration/wireless/access-point.md)

