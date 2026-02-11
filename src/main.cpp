/**
 * @file main.cpp
 * @brief Simple Arduino sketch that initializes an SSD1306 OLED and displays a welcome message.
 *
 * This program demonstrates basic usage of the Adafruit_SSD1306 and Adafruit_GFX
 * libraries to show static text on an I2C OLED display. It initializes the
 * display in setup() and prints three lines of text. The loop() is intentionally
 * left empty since this demo only shows a static message.
 *
 * Requirements:
 * - Adafruit GFX Library
 * - Adafruit SSD1306 Library
 *
 * @author Kshitij
 * @date 2026-02-11
 * @version 1.0
 * @note Ensure the required libraries are installed via PlatformIO `lib_deps` or
 * the Arduino Library Manager so the headers can be resolved during build.
 */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/** @name Display configuration
 *  Configuration macros for the SSD1306 OLED display.
 *  @{ */
#define SCREEN_WIDTH 128 /**< OLED display width in pixels */
#define SCREEN_HEIGHT 64 /**< OLED display height in pixels */
#define OLED_ADDR 0x3C   /**< I2C address of the OLED (commonly 0x3C or 0x3D) */
/** @} */

/**
 * @brief Global SSD1306 display instance.
 *
 * The Adafruit_SSD1306 constructor takes the display width and height. Call
 * display.begin(...) in setup() to initialize the display hardware and driver.
 */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

/**
 * @brief Arduino setup routine.
 *
 * Initializes the serial console and the OLED display. If the display cannot
 * be initialized the code prints an error to Serial and blocks to make the
 * failure obvious during development.
 */
void setup() {
    Serial.begin(9600);
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println(F("OLED not found"));
        while(true);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Arduino U");
    display.println("OLED with I2C");
    display.println("Hello, kshitij!!");
    display.display();
}

/**
 * @brief Arduino main loop.
 *
 * Empty for this demo since the message is static. Keep loop() lightweight
 * in real applications and avoid long blocking delays unless intended.
 */
void loop() {
    // Nothing to do in the loop
}