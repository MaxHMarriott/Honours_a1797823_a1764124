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
 Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}
void loop()
{
  int incomingByte = 0;
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
    digitalWrite(LED_BUILTIN, HIGH);
    pixels.show();
  }
  pixels.setBrightness(BRIGHTNESS);
   if (incomingByte == 48)
  {
   for (int i = 0; i < pixels.numPixels(); i++)
   { // For each pixel in strip...
   pixels.setBrightness(0);
   }
   pixels.show(); // Update strip with new contents
  }
  
  if (incomingByte == 49)
  {
   for (int i = 0; i < pixels.numPixels(); i++)
   { // For each pixel in strip...
   int pixelHue = (20000);
   pixels.setPixelColor(i, pixels.Color(255,   0,   0));
   }
   pixels.show(); // Update strip with new contents
  }

    if (incomingByte == 50)
  {
   for (int i = 0; i < pixels.numPixels(); i++)
   { // For each pixel in strip...
   int pixelHue = (10000);
   pixels.setPixelColor(i, pixels.Color(0,   255,   0));
   }
   pixels.show(); // Update strip with new contents
  }

    if (incomingByte == 51)
  {
   for (int i = 0; i < pixels.numPixels(); i++)
   { // For each pixel in strip...
   int pixelHue = (10000);
   pixels.setPixelColor(i, pixels.Color(0,   0,   255));
   }
   pixels.show(); // Update strip with new contents
  }
}
