/*
  basic state machine 2
 
  Modified to switch between states to write, read and clear EEPROM
 
 Demonstrates how to use a case statement to create a simple state machine.
 This code uses a potentiometer knob to select between 3 states.
 
 The circuit:
 * pot from analog in 0 to +5V
 * 10K resistor from analog in 0 to ground
 
 created 13 Apr 2010
 by Wendy Ju 
 modified from switchCase by Tom Igoe
 
 12 Sep 2018
 Modified to switch between states to write, read and clear EEPROM
 */

#include <EEPROM.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define COMMON_ANODE
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int numStates = 3;
const int sensorMin =0;
const int sensorMax = 1024;
const int EEPROMSIZE=1024;

int sensorPin = A2;    // select the input pin for the potentiometer
int ledPin = LED_BUILTIN;    
int state,lastState = -1;
int buttonPin = 7;
int redPin = 10;
int greenPin = 9;
int bluePin = 8;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);  
  pinMode(buttonPin, INPUT);
  pinMode(sensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 

   // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));}
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  
  while(!(digitalRead(buttonPin))){
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("Press button to start f.lux data logger");
    display.display();
    display.print(digitalRead(A2));
    display.display();
  }
  Serial.println("ASDSDSADSA");
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void loop() {
  delay(1000);
  display.clearDisplay();
  // map the pot range to number of states :
  state = map(analogRead(sensorPin), sensorMin, sensorMax, 0, numStates);

  // do something different depending on the 
  // range value:
  switch (state) {
  case 0:    
    doState0();
    break;
  case 1:    
    doState2();
    break;
  case 2:    
    doState1();
    break;
  } 
  lastState = state;
}
