LDR Light Intensity Monitor Demo

Brief demo project that reads an analog LDR (Light Dependent Resistor) voltage via an ADC input and reports raw ADC values and a simple brightness status to the serial console. See src/main.cpp for the implementation.

Using CLion

- Open the project in CLion.
- Recommended to use the Arduino or PlatformIO plugin for flashing and serial monitor support.
- Build/run configuration depends on your board/toolchain (Arduino CLI, PlatformIO, or custom CMake).

IDE Version

Tested with CLion 2025.3.2.

Code Overview

- Entry: src/main.cpp.
- Behavior:
  - Initializes Serial at 9600 baud.
  - Configures the LDR input pin (constant LDR_PIN in src/main.cpp, default: analog pin A0).
  - Polls the LDR once per second (delay(1000)).
  - Prints the raw ADC reading and a human-readable brightness status:
    - "Bright Environment" when ADC < 500
    - "Dark Environment" when ADC >= 500
  - Main loop is intentionally simple and left for extension.
- Key calls: Serial.begin(9600);, analogRead(LDR_PIN);, Serial.println(...);, delay(1000);

Libraries

- Arduino.h (core)

Install via Arduino Library Manager or the PlatformIO library registry if needed for your board core.

Dependencies

- Arduino core for your board (e.g., Arduino AVR, ESP32, ESP8266).
- No additional third-party libraries are required for this demo.

Components used with the LDR

- LDR (photoresistor)
- Fixed resistor to form a voltage divider (commonly 10 kΩ)
- Microcontroller board (Arduino Uno / Nano / Mega, ESP8266, ESP32, etc.).
- Jumper wires and breadboard (optional).

Software Requirements

- CLion 2025.3.2
- Arduino toolchain:
  - Arduino IDE or Arduino CLI, or
  - PlatformIO (recommended for integrated build/flash in CLion).
- C/C++ toolchain compatible with chosen board (installed via board support package).

Hardware Requirements

- 3.3V or 5V compatible microcontroller (match sensor voltage).
- LDR (photoresistor) and a fixed resistor for the divider (e.g., 10 kΩ).
- USB cable for programming and power.
- Optional: pull-up/pull-down consideration depending on wiring.

Wiring (typical)

- Create a voltage divider using the LDR and a fixed resistor: the midpoint of the divider connects to the analog input A0.
  - VCC -> LDR -> A0 -> Fixed resistor -> GND (or swap LDR and resistor depending on preferred behavior)
  - Use 5V or 3.3V depending on your board and sensor tolerance.
  - Example: LDR to 5V, fixed 10 kΩ resistor to GND, midpoint to A0 (matches LDR_PIN = A0 in src/main.cpp).

Author

Ayush1Sikarwar (GitHub)
