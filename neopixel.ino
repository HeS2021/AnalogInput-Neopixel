#include <Adafruit_NeoPixel.h>

#define PIN 		   12	 
#define NUMPIXELS      40
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define AIN_RED   A0 
#define AIN_GREEN A1 
#define AIN_BLUE  A2
#define AIN_LEDS_CTRL  A3


int ref_red   = 0; 
int ref_blue  = 0; 
int ref_green = 0; 

void setup() {
  pixels.begin();
}

void loop() {

  ref_red = analogRead(AIN_RED);
  ref_blue = analogRead(AIN_BLUE);
  ref_green = analogRead(AIN_GREEN);
  
  int val = analogRead(AIN_LEDS_CTRL);
  
  pixels.clear(); //Turn off all leds
  
  val = map(val,0,1023,0,40);
  //Turn on only a certain number of led
  for (int i=0; i < val; i++){
    pixels.setPixelColor(i, pixels.Color(100, 100, 100));
  }
  /*
  for (int i=val; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0, 0,0));
  }
*/
  pixels.show();
  delay(100);
}

