
# DHT11 Temperature & Humidity Monitor with LED Alerts


A simple real-time environmental monitoring project using the **DHT11 temperature & humidity sensor** and two LEDs that indicate whether the temperature is too high or too low.



##  Project Overview

This project reads **temperature** and **humidity** values using the DHT11 sensor and displays them on the Serial Monitor. Two LEDs act as alerts:

*  **LED1 (Pin 9):** Lights up when **temperature > 30°C**
*  **LED2 (Pin 10):** Lights up when **temperature < 15°C**
* Both LEDs remain off when temperature is in the safe range.

This is great for environment monitoring, home automation, school projects, or IoT experiments.



## Components Required

* Arduino Uno or compatible board
* DHT11 temperature & humidity sensor
* 2 × LEDs (red and blue recommended)
* 2 × 220Ω resistors
* Breadboard & jumper wires



##  Wiring Setup

### **DHT11 Sensor → Arduino**

| DHT11 Pin | Arduino Pin |
| --------- | ----------- |
| VCC       | 5V          |
| GND       | GND         |
| DATA      | 2           |

### **LEDs → Arduino**

| LED              | Arduino Pin | Resistor |
| ---------------- | ----------- | -------- |
| LED1 (high temp) | 9           | 220Ω     |
| LED2 (low temp)  | 10          | 220Ω     |
| LED cathodes     | GND         | —        |

---

##  How the Code Works

### 1. **DHT Library**

The project uses the `DHT.h` library to read sensor values:

```cpp
#include <DHT.h>
```

### 2. **Sensor Initialization**

The DHT11 is set up with:

```cpp
DHT dht(DHTPIN, DHTTYPE);
dht.begin();
```

### 3. **Reading Sensor Data**

The loop reads:

* Humidity (%)
* Temperature (Celsius and Fahrenheit)
* Heat Index (feels-like temperature)

If the sensor fails to read, an error is printed.

### 4. **LED Alerts**

* Temperature > 30°C → LED1 ON
* Temperature < 15°C → LED2 ON
* Otherwise → both OFF

---

##  Serial Output Example

```
Humidity: 48.00  Temperature: 27.00 *C 80.60 *F	Heat index: 28.10 *C 82.58 *F
```

##  Possible Extensions

* Add an LCD or OLED display
* Send data to an IoT platform (Blynk, MQTT, Thingspeak)
* Log temperature to an SD card
* Use a buzzer for additional alerts



