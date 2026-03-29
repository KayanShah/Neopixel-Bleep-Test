# NeoPixel Bleep Test

I created this project in 2023 to have some fun with friends and test our running abilities. 

The project simulates a **Bleep Test** using a NeoPixel LED strip and an Arduino Uno.  
It was created to visualise the Bleep Test with lights, making it easier to follow the pace of each beep.

**Overview**

- A white dot moves along a 300-LED strip representing the participant’s position in the Bleep Test.
- The buzzer plays a beep at the end of each length, just like in a traditional Bleep Test.
- The speed gradually increases over time by decreasing the delay between LED movements.
- Serial output provides the number of lengths completed and the time taken for each length.

**Features**

- Forward and backward LED movement to simulate lengths.
- Adjustable speed and acceleration.
- Visual feedback with coloured LED patterns at startup (green/red/black) for clear signals.
- Buzzer alerts for each beep.
  
**Hardware**

- Arduino Uno (or compatible)
- WS2811/WS2812 NeoPixel LED strip (300 LEDs recommended)
- Buzzer or piezo speaker connected to pin 11
- Appropriate power supply for the LED strip
- Jumper wires and breadboard (optional)

**Wiring**

- `DATA_PIN` → NeoPixel data input (pin 7)
- `BUZZER_PIN` → Buzzer positive (pin 11)
- Ground → Arduino GND

**Usage**

1. Open `Bleep_test_final.ino` in the Arduino IDE.
2. Connect your Arduino and NeoPixel strip as described above.
3. Upload the sketch to the Arduino.
4. Watch the LEDs move in sync with the Bleep Test beeps.
5. Monitor the serial output to track completed lengths and timings.

**Notes**

- The `delay_var` variable controls the speed for a full length; it decreases after each length to increase pace.
- The LED patterns at startup can be customised for different visual effects.
- Ensure your power supply can safely handle 300 LEDs to avoid flickering or damage.
