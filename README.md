# ESP32 wlan DHT thermometer

Simple thermometer based on ESP32 Development Board and DHT11/22 temperature sensors. Measured values are sent via HTTP to REST API endpoint using onboard Wi-Fi.

## Usage

1. clone the repository
2. `cd themometer`
3. `cp settings.h.sample settings.h`
4. adjust you wlan credentials
5. open the `thermometer` folder in Arduino IDE
6. make sure that [DHT sensor library](https://github.com/adafruit/DHT-sensor-library) is installed in Arduino IDE
7. upload the sketch to your ESP32 Development Board

## Circuit

TODO