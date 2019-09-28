int redPin = 10;
int greenPin = 9;
int bluePin = 8;
 
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void loop()
{
setColor(255, 255, 200);  // white
delay(1000);
setColor(255,225,65);  // yellow-ish
delay(1000);
setColor(70,100,255);     //purple-ish
delay(1000);
setColor(80,245,255);     //blue-ish
delay(1000);
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
