//Install the NeoPixel library
// Define what pin the neopixel is attached to and how many pins
// XC4385 has 24 pixels, XC4380 only has 8
#define PIN 9
#define NUMPIXELS 24
#define BRIGHTNESS 200 // Set BRIGHTNESS to about 1/5 (max = 255)
// Create the object
int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(10);
  digitalWrite(LED_BUILTIN, LOW);
}
