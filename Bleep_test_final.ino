#include <FastLED.h>

#define NUM_LEDS 300
#define DATA_PIN 7
#define BUZZER_PIN 11 // Pin for the buzzer
CRGB leds[NUM_LEDS];

float delay_var = 60; // Initial delay value
int lengths = 0;       // Counter for the number of lengths
unsigned long startMillis;
unsigned long lengthMillis;

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
  delay(1000); // Initial pause
  pinMode(BUZZER_PIN, OUTPUT); // Set the buzzer pin as an output
  Serial.begin(9600); // Initialize serial communication
  Serial.println("Welcome to the bleep test.");

  // LED initialization pattern
  ledPattern(CRGB::Green, 500);
  ledPattern(CRGB::Black, 500);
  ledPattern(CRGB::Green, 500);
  ledPattern(CRGB::Black, 500);
  ledPattern(CRGB::Green, 500);
  ledPattern(CRGB::Black, 500);
  ledPattern(CRGB::Red, 500);
  ledPattern(CRGB::Black, 0); // Turn off LEDs
}

void loop() {
  // Record the start time for the current length
  startMillis = millis();

  // Move the white dot forward by 2 LEDs
  for (int whiteLed = 0; whiteLed < NUM_LEDS - 1; whiteLed += 4) {
    leds[whiteLed] = CRGB::White;
    leds[whiteLed + 1] = CRGB::White; // Turn on the next LED too
    FastLED.show();
    delay((int)delay_var); // Use the current delay value
    leds[whiteLed] = CRGB::Black;
    leds[whiteLed + 1] = CRGB::Black; // Turn off the next LED
    checkAndRecordTime(); // Check if time should be recorded
  }

  // Play a bleep sound and increment the lengths counter
  playBleep();
  lengths++;
  
  // Print the number of lengths to the serial monitor
  Serial.print("Number of Lengths: ");
  Serial.print(lengths);

  // Record the end time for the current length
  lengthMillis = millis() - startMillis;

  // Print the time taken for the length in the serial monitor
  Serial.print(", Length Time: ");
  Serial.print(lengthMillis);
  Serial.println(" ms");

  // Move the white dot backward by 2 LEDs
  for (int whiteLed = NUM_LEDS - 4; whiteLed >= 0; whiteLed -= 4) {
    leds[whiteLed] = CRGB::White;
    leds[whiteLed + 1] = CRGB::White; // Turn on the next LED too
    FastLED.show();
    delay((int)delay_var); // Use the current delay value
    leds[whiteLed] = CRGB::Black;
    leds[whiteLed + 1] = CRGB::Black; // Turn off the next LED
    checkAndRecordTime(); // Check if time should be recorded
  }

  // Play a bleep sound and increment the lengths counter
  playBleep();
  lengths++;

  Serial.print("Number of Lengths: ");
  Serial.println(lengths);

  // Decrease the delay gradually and accelerate the rate
  delay_var = delay_var - 2.16; // Accelerate the rate of decrease
  if (delay_var < 0) {  // Limit to the fastest possible time
    delay_var = 0;
  }
}

// Function to play a bleep sound using the buzzer
void playBleep() {
  digitalWrite(BUZZER_PIN, HIGH); // Turn on the buzzer
  delay(500); // Bleep duration
  digitalWrite(BUZZER_PIN, LOW); // Turn off the buzzer
}

// Function to check if time should be recorded when reaching ends
void checkAndRecordTime() {
  if (leds[0] == CRGB::White || leds[NUM_LEDS - 1] == CRGB::White) {
    unsigned long currentTime = millis();
    Serial.print("Length ");
    Serial.print(lengths);
    Serial.print(" Time: ");
    Serial.print(currentTime - startMillis);
    Serial.println(" ms");
    startMillis = currentTime;
  }
}

// Function to display LED pattern with a color and delay
void ledPattern(CRGB color, int delayTime) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
  FastLED.show();
  delay(delayTime);
}
