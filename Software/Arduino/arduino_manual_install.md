# Arduino / Manual Installation

> **NOTE:** The following installation instructions apply specifically to [**Adafruit's HUZZAH32-ESP32 Feather**](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather)

## Prepare the Arduino IDE
1.  Install the latest version of the [**Arduino IDE**](https://www.arduino.cc/en/Main/Software)

2.  Install the ESP-boards library using Boards Manager *(within Arduino IDE)*
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
    
3.  Install **Adafruit's MQTT Libraries** using Libraries Manager *(within Arduino IDE)*
    1.  Go to `Sketch > Include Library > Libraries Manager`
    2.  Search, download and install the latest version of the `Adafruit MQTT Library`
    
4. Test by opening the **mqtt_template.ino** file
    1.  Go to `Tools > Boards` and select the **Adafruit ESP32 Feather** board *(you may need to scroll)*
    2.  Verify/Compile Sketch `(Ctrl + R)`
        1.  _Errors here will be related to library installation problems (Steps 2 and 3)_
    3.  Connect **Adafruit ESP32 Feather**
    4.  Select the corresponding COM port in `Tools > Port`
    5.  Upload Sketch `(Ctrl + U)`
        1.  _Errors here will be related to the connection, ports or issues with the hardware_

#### References

