//Install the NeoPixel library
#include <Adafruit_NeoPixel.h>
// Define what pin the neopixel is attached to and how many pins
// XC4385 has 24 pixels, XC4380 only has 8
#define PIN 9
#define NUMPIXELS 24
#define BRIGHTNESS 200 // Set BRIGHTNESS to about 1/5 (max = 255)
// Create LED Array 1
Adafruit_NeoPixel pixels1(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, PIN-1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, PIN-2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS, PIN-3, NEO_GRB + NEO_KHZ800);



void setup()
{
//LED Constants:
 pixels1.begin(); //start the object
 pixels1.setBrightness(0);
 pixels2.begin(); //start the object
 pixels2.setBrightness(0);
 pixels3.begin(); //start the object
 pixels3.setBrightness(0);
 pixels4.begin(); //start the object
 pixels4.setBrightness(0);

//Attendance constants
int  ZoneHP1 = 0;
int  ZoneHP2 = 0;
int  ZoneHP3 = 0;
int  ZoneHP4 = 0;
//Serial Constants
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
  }

// Determine state Logic: 
// Case: recieved data is a '0'
   if (incomingByte == 48)
  {
    pixels1.setBrightness(0);
    pixels2.setBrightness(0);
    pixels3.setBrightness(0);
    pixels4.setBrightness(0);

    ZoneHP1 = 0;
    ZoneHP2 = 0;
    ZoneHP3 = 0;
    ZoneHP4 = 0;
  }
// Case: recieved data is a '1'
  else if (incomingByte == 49)
  {
    pixels1.setBrightness(BRIGHTNESS);
    for (int i = 0; i < pixels1.numPixels(); i++)
    { // For each pixel in strip...
      pixels1.setPixelColor(i, pixels1.Color(255,   255,   0));
    }
    pixels2.setBrightness(0);
    pixels3.setBrightness(BRIGHTNESS);
    for (int i = 0; i < pixels1.numPixels(); i++)
    { // For each pixel in strip...
      pixels3.setPixelColor(i, pixels3.Color(255,   0,   0));
    }
    pixels4.setBrightness(0);

    ZoneHP1 = 10.0;
    ZoneHP2 = 0;
    ZoneHP3 = 20.0;
    ZoneHP4 = 0;
  }
// Case: recieved data is a '2'
  else if (incomingByte == 50)
  {
    pixels1.setBrightness(0);
    pixels2.setBrightness(BRIGHTNESS);
    for (int i = 0; i < pixels1.numPixels(); i++)
    { // For each pixel in strip...
      pixels2.setPixelColor(i, pixels2.Color(255,255,0));
    }
    pixels3.setBrightness(0);
    pixels4.setBrightness(BRIGHTNESS);
    for (int i = 0; i < pixels1.numPixels(); i++)
    { // For each pixel in strip...
      pixels4.setPixelColor(i, pixels4.Color(0,255,0));
    }
    ZoneHP1 = 0;
    ZoneHP2 = 10.0;
    ZoneHP3 = 5.0;
    ZoneHP4 = 0;
  }
// Case: recieved data is a '3'
  else if (incomingByte == 51)
  {
    pixels1.setBrightness(BRIGHTNESS);
    for (int i = 0; i < pixels1.numPixels(); i++)
    { // For each pixel in strip...
      pixels1.setPixelColor(i, pixels1.Color(255,255,0));
    }
    pixels2.setBrightness(0);
    pixels3.setBrightness(0);
    pixels4.setBrightness(BRIGHTNESS);
    for (int i = 0; i < pixels2.numPixels(); i++)
    { // For each pixel in strip...
      pixels4.setPixelColor(i, pixels4.Color(255,255,0));
    }
    ZoneHP1 = 10.0;
    ZoneHP2 = 0;
    ZoneHP3 = 10.0;
    ZoneHP4 = 0;
  }
// Case: recieved data is a '4'
  else if (incomingByte == 52)
  {
    pixels1.setBrightness(0);
    for (int i = 0; i < pixels1.numPixels(); i++)
    { // For each pixel in strip...
      pixels1.setPixelColor(i, pixels1.Color(255,0,0));
    }
    pixels2.setBrightness(BRIGHTNESS);
    for (int i = 0; i < pixels2.numPixels(); i++)
    { // For each pixel in strip...
      pixels2.setPixelColor(i, pixels2.Color(0,255,0));
    }
    pixels3.setBrightness(0);
    pixels4.setBrightness(0);
    ZoneHP1 = 20.0;
    ZoneHP2 = 5.0;
    ZoneHP3 = 0;
    ZoneHP4 = 0;
  }
// Case: recieved data is a '5'
  else if (incomingByte == 53)
  {
    pixels1.setBrightness(0);
    pixels2.setBrightness(0);
    pixels3.setBrightness(BRIGHTNESS);
    for (int i = 0; i < pixels1.numPixels(); i++)
    { // For each pixel in strip...
      pixels3.setPixelColor(i, pixels3.Color(255,255,0));
    }
    pixels4.setBrightness(BRIGHTNESS);
    for (int i = 0; i < pixels1.numPixels(); i++)
    { // For each pixel in strip...
      pixels4.setPixelColor(i, pixels4.Color(0,255,0));
    }
    ZoneHP1 = 10.0;
    ZoneHP2 = 5.0;
    ZoneHP3 = 0;
    ZoneHP4 = 0;
  }
// Case: recieved data is a '6' (Zone 1 Being Attended by 1 UGV) (Call twice for 2 UGVs)
  if (incomingByte == 54)
  {
      ZoneHP1 = ZoneHP1 - 1.0;
      if (ZoneHP1 < 0)
      {
      pixels1.setBrightness(0);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels1.setPixelColor(i, pixels1.Color(255,0,0));
      }
     }
     else if (ZoneHP1 < 10)
     {
      pixels1.setBrightness(BRIGHTNESS);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels1.setPixelColor(i, pixels1.Color(255,255,0));
      }
     }
    else if (ZoneHP1 < 20)
     {
      pixels1.setBrightness(BRIGHTNESS);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels1.setPixelColor(i, pixels1.Color(0,255,0));
      }
     }
  }
// Case: recieved data is a '7' (Zone 1 Being Attended by 2 UGV) (Call twice for 2 UGVs)
  if (incomingByte == 55)
 {
      ZoneHP2 = ZoneHP2 - 1.0;
      if (ZoneHP2 < 0)
      {
      pixels2.setBrightness(0);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels2.setPixelColor(i, pixels2.Color(255,0,0));
      }
     }
     else if (ZoneHP2 < 10)
     {
      pixels2.setBrightness(BRIGHTNESS);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels2.setPixelColor(i, pixels2.Color(255,255,0));
      }
     }
    else if (ZoneHP2 < 20)
     {
      pixels2.setBrightness(BRIGHTNESS);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels2.setPixelColor(i, pixels2.Color(0,255,0));
      }
     }
  }
// Case: recieved data is a '8' (Zone 1 Being Attended by 1 UGV) (Call twice for 2 UGVs)
  if (incomingByte == 56)
 {
      ZoneHP3 = ZoneHP3 - 1.0;
      if (ZoneHP3 < 0)
      {
      pixels3.setBrightness(0);
      for (int i = 0; i < pixels3.numPixels(); i++)
      { // For each pixel in strip...
        pixels3.setPixelColor(i, pixels3.Color(255,0,0));
      }
     }
     else if (ZoneHP3 < 10)
     {
      pixels3.setBrightness(BRIGHTNESS);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels3.setPixelColor(i, pixels3.Color(255,255,0));
      }
     }
    else if (ZoneHP3 < 20)
     {
      pixels3.setBrightness(BRIGHTNESS);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels3.setPixelColor(i, pixels3.Color(0,255,0));
      }
     }
  }
// Case: recieved data is a '9' (Zone 1 Being Attended by 2 UGV) (Call twice for 2 UGVS)
  if (incomingByte == 57)
 {
      ZoneHP4 = ZoneHP4 - 1.0;
      if (ZoneHP4 < 0)
      {
      pixels4.setBrightness(0);
      for (int i = 0; i < pixels4.numPixels(); i++)
      { // For each pixel in strip...
        pixels4.setPixelColor(i, pixels4.Color(255,0,0));
      }
     }
     else if (ZoneHP4 < 10)
     {
      pixels4.setBrightness(BRIGHTNESS);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels4.setPixelColor(i, pixels4.Color(255,255,0));
      }
     }
    else if (ZoneHP4 < 20)
     {
      pixels4.setBrightness(BRIGHTNESS);
      for (int i = 0; i < pixels1.numPixels(); i++)
      { // For each pixel in strip...
        pixels4.setPixelColor(i, pixels2.Color(0,255,0));
      }
     }
  }
