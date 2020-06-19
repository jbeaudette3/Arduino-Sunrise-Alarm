#include <FastLED.h>
#define NUM_LEDS 60
#define DATA_PIN 6
CRGB leds[NUM_LEDS];


/* MATH
 *  15 minutes long
 *  x = 15 * 60 * 1000 / 3 / 255


  15 minutes total length      1 color cycle          1 colorstep        60 seconds      1000 milliseconds
  ------------------------  x  -----------------  x  --------------  x  ------------  x  ------------------
      3 cycles                  255 color steps       X milliseconds     1 minute         1 second

*/



#define wait 1176        // time in milliseconds between each light change
#define trance 60        // rate of flashing in milliseconds
#define FLASH_YOU 100    // how many times does it flash

void setup()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
}


void loop()
{
  off();
  toRedRandom();
  toYellowRandom();
  toWhiteRandom();
  flash();              // please avoid if epileptic
}



void off()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
}

void toRedRandom()
{
  int i = 0;
  for (int x = 0; x < 255; x++)
  {
    i = random(0, NUM_LEDS);
    leds[i] = CRGB(x, 0, 0);
    FastLED.show();
    delay(wait);
  }
}

void toYellowRandom()
{
  int i = 0;
  for (int x = 0; x < 255; x++)
  {
    i = random(0, NUM_LEDS);
    leds[i] = CRGB(255, x, 0);
    FastLED.show();
    delay(wait);
  }
}

void toWhiteRandom()
{
  int i = 0;
  for (int x = 0; x < 255; x++)
  {
    i = random(0, NUM_LEDS);
    leds[i] = CRGB(255, 255, x);
    FastLED.show();
    delay(wait);
  }
}

void flash()                               // please avoid if epileptic
{
  for (int j = 0; j < FLASH_YOU; j++)
  {
    {
      for (int i = 0; i < NUM_LEDS; i++)
        leds[i] = CRGB(255, 255, 255);
    }
    FastLED.show();
    delay(trance);

    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    delay(trance);
  }
}
