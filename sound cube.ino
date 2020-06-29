#include "FastLED.h" //fast led library 
#define NUM_LEDS 10 //total no. of leds used
#define DATA_PIN 5 //digital pin at which the data pin is connected
#define mic A5 //analog input from mic module
int mic_Value; //to save raw value from mic
int red, green, blue; //to store RGB color values
CRGB leds[NUM_LEDS]; //fast led function 

void setup() {
  FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS); //as our led IC is UCS1903B,fast led support lots of ICs, find more
  LEDS.setBrightness(200); //setting brightness of LED (0 to 255) //info at fastled.io
  randomSeed(analogRead(0));// for generating random no. by taking noise from analog pin 0
  for (int i = 0; i <= 9; i++) //for changing color of all 10 LEDs
  {
    leds[i] = CRGB(200, 200, 200); //for initial white color
    LEDS.show(); //fastled function, without this function the colors won't be updated
  }

}

void loop() {

  mic_Value = analogRead(mic); //storing analog values from mic to mic_value
  if(mic_Value>100) //to avoid small noise
  {
    for(int i=0;i<=9;i++)//for changing color of all 10 LEDs
    {
    red=random(255); //random red color value between 0 to 255
    green=random(255); //random green color value between 0 to 255
    blue=random(255); //random blue color value between 0 to 255
    leds[i]=CRGB(red,green,blue); //assigning color values to LEDs
    LEDS.show();
  }
 }
}
