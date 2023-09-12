//Install the NeoPixel library
#include <Adafruit_NeoPixel.h>
// Define what pin the neopixel is attached to and how many pins
// XC4385 has 24 pixels, XC4380 only has 8
#define PIN 9
#define NUMPIXELS 24
#define BRIGHTNESS 200 // Set BRIGHTNESS to about 1/5 (max = 255)
// Create the object
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
 pixels.begin(); //start the object
 pixels.setBrightness(BRIGHTNESS);
}
void loop()
{
delay(10000)

 int k = ceil(rand()*3)

 if (k == 1)
 {
   for (int i = 0; i < pixels.numPixels(); i++)
   { // For each pixel in strip...
   int pixelHue = (20000);
   pixels.setPixelColor(i, pixels.Color(255,   0,   0));
   }
   pixels.show(); // Update strip with new contents
 }

 if (k == 2)
 {
  for (int i = 0; i < pixels.numPixels(); i++)
   { // For each pixel in strip...
   int pixelHue = (10000);
   pixels.setPixelColor(i, pixels.Color(0,   255,   0));
   }
   pixels.show(); // Update strip with new contents
 }

if (k == 3)
{
  for (int i = 0; i < pixels.numPixels(); i++)
   { // For each pixel in strip...
   int pixelHue = (10000);
   pixels.setPixelColor(i, pixels.Color(255,   255,   0));
   }
   pixels.show(); // Update strip with new contents
}

 delay(10000); // Pause for a moment
}
