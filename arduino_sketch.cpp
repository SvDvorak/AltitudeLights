#include <Adafruit_NeoPixel.h>
#include <inttypes.h>

#define NEOPIXEL_PIN 1

// We use "pixel" to refer to a single WS2812B package, which contains three LEDs (red, green and blue).

// Select number of pixels.
#define NUM_PIXELS 2700

// We copy some type name defines here to keep the sketch self contained.
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define s16 int16_t

// Create the NeoPixel driver object. On the PC, this becomes the emulator.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// This must be below the short int type names and the NeoPixel library init.
#ifndef Arduino_h
#include "arduino_sketch.hpp"
// When running on the PC, we include stdio.h for printf() debugging.
#include <stdio.h>
#endif

// Example of wrapping stuff that will only compile in the IDE.
#ifdef Arduino_h
void debugMarker()
{
  pinMode(1, OUTPUT);
  for (u8 i = 0; i < 10; ++i) {
    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(1, LOW);
    delay(500);
  }
}
#endif

// End of boilerplate.

void setup()
{
// Arduino_h is only defined when compiling the sketch in the Arduino IDE.
#ifndef Arduino_h
    // Select line, circle or grid pixel layout for emulator.
    // pixels.setPixelLayout(Strip);
    pixels.setPixelLayout(Ring);
    // pixels.setPixelLayout(Grid);
#endif
    pixels.begin();
    // setBrightness() is intended for use only in setup() and not for animations. It's ignored by the emulator (see
    // the README).
    pixels.setBrightness(50);
    pixels.show();
}


struct Segment {
  u32 color;
  s16 speed;
  u8 lengthPercent;
};

int extra, extra2;

void loop()
{
    //clear(0xff0000, 5);
    //delay(1000);

    for (int i=0; i < 250 ;i++){ 
        extra = random(-30,40);
        extra2 = random(-83,40);
        pixels.setPixelColor(random(0, 2700), (36 + extra), (83 + extra2), (214 + extra));
    }
    pixels.show();
}

void clear(u32 color, u16 clearMs)
{
    for (u16 i = 0; i < pixels.numPixels(); ++i) {
        pixels.setPixelColor(i, color);
        pixels.show();
        delay(clearMs);
    }
}

