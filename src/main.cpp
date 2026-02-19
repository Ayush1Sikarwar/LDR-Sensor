#include <Arduino.h>
/**
 * @file main.cpp
 * @brief LDR-based Light Intensity Monitoring
 * @author Ayush1Sikarwar
 * @date 2026-02-17
 *
 * @details
 * This sketch reads analog brightness data from an LDR (Light Dependent Resistor)
 * connected to an analog input (A0). It prints the raw ADC reading and a
 * human-readable brightness status to the Serial Monitor every second.
 *
 * The program is intended as a simple data acquisition and monitoring demo
 * for educational and prototyping purposes.
 */

// Pin connected to the LDR voltage divider output
int LDR_PIN = A0; /**< @brief Analog pin used to read LDR voltage */

// Last-read raw ADC value from the LDR circuit
int ldrValue = 0; /**< @brief Stores the most recent analogRead() result */

/**
 * @brief Arduino setup routine
 *
 * Initializes Serial communication at 9600 baud and prints a startup banner
 * to the Serial Monitor. This function runs once when the board powers up
 * or resets.
 *
 * @note No parameters or return value. Side effects: opens Serial.
 */
void setup() {

    Serial.begin(9600);

    Serial.println("=================================");
    Serial.println("  LDR Light Intensity Monitor");
    Serial.println("  System Initializing...");
    Serial.println("=================================");
}

/**
 * @brief Main Arduino loop
 *
 * Reads the analog value from the LDR pin, prints the raw ADC value, and
 * classifies the environment as either "Bright Environment" or
 * "Dark Environment" based on a simple threshold. The results are written
 * to the Serial Monitor once per second.
 *
 * @note No parameters or return value. Side effects: performs analogRead()
 * and writes to Serial.
 */
void loop() {

    ldrValue = analogRead(LDR_PIN);

    Serial.print("Raw ADC Value: ");
    Serial.println(ldrValue);

    String brightnessStatus;

    if (ldrValue < 500) {
        brightnessStatus = "Bright Environment";
    } else {
        brightnessStatus = "Dark Environment";
    }

    Serial.print("Status: ");
    Serial.println(brightnessStatus);
    Serial.println("---------------------------------");

    delay(1000);
}
