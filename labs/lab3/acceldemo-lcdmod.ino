// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// software SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(void) {
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif

  Serial.begin(9600);
  Serial.println("LIS3DH test!");
  lcd.begin(16, 2);
  lcd.print("LIS3DH test!");
  delay(1000);
  
  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    lcd.clear();
    lcd.print("Couldn't Start");
    while (1);
  }
  lcd.clear();
  lcd.print("Device found!");
  Serial.println("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
  delay(1000);
  lcd.print("Range = ");
  lcd.print(2 << lis.getRange());  
  lcd.print("G");
  Serial.print("Range = "); Serial.print(2 << lis.getRange());  
  Serial.println("G");
}

void loop() {
  lis.read();      // get X Y and Z data at once
  // Then print out the raw data
  delay(100);
  lcd.clear();
  Serial.print("X:  "); Serial.print(lis.x); 
  lcd.print("X:");
  lcd.print(lis.x);
  lcd.setCursor(7, 0);
  lcd.print("Y:");
  lcd.print(lis.y);
  lcd.setCursor(0,1);
  lcd.print("Z:");
  lcd.print(lis.z);
  Serial.print("  \tY:  "); Serial.print(lis.y); 
  Serial.print("  \tZ:  "); Serial.print(lis.z); 
  delay(1000);
  /* Or....get a new sensor event, normalized */ 
  sensors_event_t event; 
  lis.getEvent(&event);
  
  /* Display the results (acceleration is measured in m/s^2) */
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("X:");
  lcd.print(event.acceleration.x);
  lcd.setCursor(9,0);
  lcd.print("Y:");
  lcd.print(event.acceleration.y);
  lcd.setCursor(0,1);
  lcd.print("Z:");
  lcd.print(event.acceleration.z);
  lcd.setCursor(7,1);
  lcd.print("m/s^2");
  Serial.print("\t\tX: "); Serial.print(event.acceleration.x);
  Serial.print(" \tY: "); Serial.print(event.acceleration.y); 
  Serial.print(" \tZ: "); Serial.print(event.acceleration.z); 
  Serial.println(" m/s^2 ");
  delay(1000);
  Serial.println();
 
  delay(200); 
}