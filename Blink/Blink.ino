/*
  Blink

  Programer Brennen Koernke

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// -------------------------------
// Pin Definitions
// -------------------------------
const int speakerPin = 6;   // Piezo speaker connected to pin 6
const int fadeLedPin = 11;  // Fading LED connected to PWM pin 11

// Variables for fading LED
int brightness = 0;         // Current brightness (0–255)
int fadeAmount = 5;         // Amount to change brightness each step

// -------------------------------
// Setup runs once at startup
// -------------------------------
void setup() {
  pinMode(10, OUTPUT);        // LED 1
  pinMode(9, OUTPUT);         // LED 2
  pinMode(speakerPin, OUTPUT);// Speaker output
  pinMode(fadeLedPin, OUTPUT);// Fading LED
}

// -------------------------------
// Main loop runs forever
// -------------------------------
void loop() {

  // ---- Rising Siren + LED flash ----
  for (int frequency = 600; frequency <= 1800; frequency += 20) {
    
    tone(speakerPin, frequency);  // Play current siren frequency

    digitalWrite(9, HIGH);   // LED on pin 9 ON
    digitalWrite(10, LOW);   // LED on pin 10 OFF

    // Fade LED on pin 11
    analogWrite(fadeLedPin, brightness); // Set brightness
    brightness += fadeAmount;            // Increase brightness

    // Reverse fade direction at limits
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    delay(10); // Small delay for smooth siren sound
  }

  // ---- Falling Siren + LED swap ----
  for (int frequency = 1800; frequency >= 600; frequency -= 20) {
    
    tone(speakerPin, frequency);  // Play current siren frequency

    digitalWrite(9, LOW);    // LED on pin 9 OFF
    digitalWrite(10, HIGH);  // LED on pin 10 ON

    // Continue fading LED
    analogWrite(fadeLedPin, brightness);
    brightness += fadeAmount;

    // Reverse fade direction at limits
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    delay(10); // Small delay for smooth siren sound
  }
}

