// ArrayOfLedArrays with strips of different length test
// Marc Miller, Apr 2016
//---------------------------------------------------------------

#include "FastLED.h"
#define LED_TYPE NEOPIXEL
#define NUM_STRIPS 3  // Total number of strips

#define NUM_LEDS 12   // Specify length of each strip
#define NUM_LEDS1 32
#define NUM_LEDS2 30
//etc.

CRGB leds[NUM_STRIPS][NUM_LEDS + NUM_LEDS1 + NUM_LEDS2];  // Add all together here

uint8_t stripLength;  // Used to store a strip length.


//---------------------------------------------------------------
void setup() {
  Serial.begin(115200);  // Allows serial monitor output (check baud rate)
  delay(3000);
  FastLED.addLeds<LED_TYPE, 6>(leds[0], NUM_LEDS);  // Assign data pins
  FastLED.addLeds<LED_TYPE, 11>(leds[1], NUM_LEDS1);
  FastLED.addLeds<LED_TYPE, 13>(leds[2], NUM_LEDS2);
  //etc.
}


//---------------------------------------------------------------
void loop() {
  for(uint8_t x = 0; x < NUM_STRIPS; x++) {
    stripLength = getStripLength(x);
    fill_rainbow( leds[x], stripLength, millis()/3, 256/stripLength );
  }
  FastLED.show();
  delay(3000);

  for(uint8_t x = 0; x < NUM_STRIPS; x++) {
    stripLength = getStripLength(x);
    uint8_t randomColor = random8();
    fill_solid(leds[x], stripLength, CHSV(randomColor,255,255));
  }
  FastLED.show();
  delay(2000);

  FastLED.clear();  // Clear all data
  FastLED.show();
  delay(1000);

}//end main loop


//-----function to return strip length-----
uint8_t getStripLength(uint8_t stripNumber){
  uint8_t L;
  if (stripNumber == 0) { L = NUM_LEDS; }
  if (stripNumber == 1) { L = NUM_LEDS1; }
  if (stripNumber == 2) { L = NUM_LEDS2; }
  //etc.

  //Serial.print("stripNumber ");
  //Serial.print(stripNumber);
  //Serial.print(" = ");
  //Serial.println(L);
  return L;
}

