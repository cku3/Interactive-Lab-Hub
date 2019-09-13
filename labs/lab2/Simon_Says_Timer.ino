#include "pitches.h"
#include <LiquidCrystal.h>

//song tunes
int starttune[] = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_E4, NOTE_C4};
int startdur[] = {10,10,10,10,10,10,10};

int wintune[] = {NOTE_G2, NOTE_C3, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_E4, 
NOTE_GS2, NOTE_C3, NOTE_DS3, NOTE_G3, NOTE_C4, NOTE_DS4, NOTE_GS4, NOTE_DS4,
NOTE_AS2, NOTE_D3, NOTE_F3, NOTE_AS3, NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_C5};
int windur[] = {5, 5, 5, 5, 5, 5, 8, 5, 5, 5, 5, 5, 5, 5, 8, 5, 5, 5, 5, 5, 5, 5, 8, 5, 5, 5, 10};

int losetune[] = {NOTE_B4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4};
int losedur[] = {10, 10, 5, 5, 10, 10, 10, 10};

int button[] = {10, 9, 8, 7}; //The four button input pins
int ledpin[] = {A0, A1, A2, A3};  // LED pins
int turn = 0;  // turn counter
int buttonstate = 0;  // button state checker
int randomArray[100]; //Intentionally long to store up to 100 inputs (doubtful anyone will get this far)
int inputArray[100];  
int countdown;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void fail() { //Function used if the player fails to match the sequence
  lcd.clear();
  lcd.print("Game Over!");
  //for (int y=0; y<=2; y++)
  //{ Flashes lights for failure
   if (turn > 4)
    {
      for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / windur[thisNote];
      tone(A4, wintune[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
  noTone(A4);
    }
    else
    {
      for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / losedur[thisNote];
      tone(A4, losetune[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
  noTone(A4);
    }
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[3], HIGH);
    delay(500);
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[3], LOW);
    delay(200);
  //}
  delay(500);
  lcd.clear();
  turn = -2; //Resets turn value so the game starts over without need for a reset button
}

void input() { //Function for allowing user input and checking input against the generated array

  for (int x=0; x <= turn;)
  { //Statement controlled by turn count

    for(int y=0; y<4; y++)
    {
      
      buttonstate = digitalRead(button[y]);
    
      if (buttonstate == LOW && button[y] == 10)
      { //Checking for button push
        digitalWrite(ledpin[0], HIGH);
        tone(A4, NOTE_G3, 100);
        delay(200);
        digitalWrite(ledpin[0], LOW);
        inputArray[x] = 1;
        delay(250);
        Serial.print(" ");
        Serial.print(1);
        if (inputArray[x] != randomArray[x]) { //Checks value input by user and checks it against
          fail();                              //the value in the same spot on the generated array
          }                                      //The fail function is called if it does not match
        x++;
      }
       if (buttonstate == LOW && button[y] == 9)
      {
        digitalWrite(ledpin[1], HIGH);
        tone(A4, NOTE_A3, 100);
        delay(200);
        digitalWrite(ledpin[1], LOW);
        inputArray[x] = 2;
        delay(250);
        Serial.print(" ");
        Serial.print(2);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }

      if (buttonstate == LOW && button[y] == 8)
      {
        digitalWrite(ledpin[2], HIGH);
        tone(A4, NOTE_B3, 100);
        delay(200);
        digitalWrite(ledpin[2], LOW);
        inputArray[x] = 3;
        delay(250);
        Serial.print(" ");
        Serial.print(3);
        if (inputArray[x] != randomArray[x]) {
          fail();
                  }
        x++;
      }

      if (buttonstate == LOW && button[y] == 7)
      {
        digitalWrite(ledpin[3], HIGH);
        tone(A4, NOTE_C4, 100);
        delay(200);
        digitalWrite(ledpin[3], LOW);
        inputArray[x] = 4;
        delay(250);
        Serial.print(" ");
        Serial.print(4);
        if (inputArray[x] != randomArray[x]) 
        {
          fail();
          lcd.print("failed");
          delay(500);
               }
        x++;
      }
    }
  }
  delay(500);
  turn++; //Increments the turn count, also the last action before starting the output function over again
  delay(500);
}

void setup() {
  for(int x=0; x<4; x++)  // LED pins are outputs
  {
    pinMode(ledpin[x], OUTPUT);
  }
  
  for(int x=0; x<4; x++) 
  {
    pinMode(button[x], INPUT);  // button pins are inputs
    digitalWrite(button[x], INPUT_PULLUP);  // enable internal pullup; buttons start in high position; logic reversed
  }
  lcd.begin(16, 2);
  lcd.print("Simon Says Wake");
  lcd.setCursor(0,1);
  lcd.print("Up!");
  delay(3000);
}

void loop() {
  lcd.clear();
  lcd.print("Hold the blue");
  lcd.setCursor(0,1);
  lcd.print("button to start");
  while (digitalRead(button[3]) == HIGH)
  {
      //fun led pattern
    //delay(1000);
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], LOW);
    delay(300);
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], HIGH);
    delay(300);
    digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[1], LOW);
    delay(300);
    digitalWrite(ledpin[3], HIGH);
    digitalWrite(ledpin[2], LOW);
    delay(300);
    digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[3], LOW);
    delay(300);   
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[1], HIGH);
    delay(300);
  }
  digitalWrite(ledpin[1], LOW);
  lcd.clear();
  lcd.print("sleep duration?");
  delay(1000);
  lcd.clear();
  //settings button pressed, offer alarm settings
  while ((digitalRead(button[0]) == HIGH) && (digitalRead(button[1]) == HIGH) && (digitalRead(button[2]) == HIGH) && (digitalRead(button[3]) == HIGH))
  {
    lcd.print("R:1      Y:6");
    lcd.setCursor(0,1);
    lcd.print("G:8      B:10    ");
  }

  if (digitalRead(button[0]) == LOW)
  {
    countdown=1;
  }
  else if (digitalRead(button[1]) == LOW)
  {
    countdown=6;
  }
  else if (digitalRead(button[2]) == LOW)
  {
    countdown=8;
  }
  else if (digitalRead(button[3]) == LOW)
  {
    countdown=10;
  }

  //timer with countdown param
  lcd.clear();
  lcd.print("Countdown start!");
  delay(1000);
  while (countdown>0){
    lcd.clear();
    lcd.print(countdown);
    delay(1000);
    countdown--;
  }
  
  //time is up!
  lcd.clear(); 
 // lcd.print(digitalRead(button[2]);
  delay(1000);
  while (digitalRead(button[1]) == HIGH)
  {
      lcd.print("ALARM!!!");
      lcd.setCursor(0,1);
      lcd.print("yo press yellow");
      for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / startdur[thisNote];
      tone(A4, starttune[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
    lcd.clear();
  }
  noTone(A4);
  lcd.clear();
  //start game
  lcd.print("Let's play!");
  delay(2000);
  lcd.clear();
  
  for (int y=0; y<=99; y++)
  {
      //function for generating the array to be matched by the player
      digitalWrite(ledpin[0], HIGH);
      digitalWrite(ledpin[1], HIGH);
      digitalWrite(ledpin[2], HIGH);
      digitalWrite(ledpin[3], HIGH);
    
      delay(1000);
      
      digitalWrite(ledpin[0], LOW);
      digitalWrite(ledpin[1], LOW);
      digitalWrite(ledpin[2], LOW);
      digitalWrite(ledpin[3], LOW);
      delay(1000);
    
      for (int y=turn; y <= turn; y++)
      { //Limited by the turn variable
        Serial.println(""); //Some serial output to follow along
        Serial.print("Turn: ");
        Serial.print(y);
        Serial.println("");
        randomArray[y] = random(1, 5); //Assigning a random number (1-4) to the randomArray[y], y being the turn count
        for (int x=0; x <= turn; x++)
        {
          Serial.print(randomArray[x]);
        
          for(int y=0; y<4; y++)
          {
        
            if (randomArray[x] == 1 && ledpin[y] == A0) 
            {  //if statements to display the stored values in the array
              digitalWrite(ledpin[y], HIGH);
              tone(A4, NOTE_G3, 100);
              delay(400);
              digitalWrite(ledpin[y], LOW);
              delay(100);
            }
  
            if (randomArray[x] == 2 && ledpin[y] == A1) 
            {
              digitalWrite(ledpin[y], HIGH);
              tone(A4, NOTE_A3, 100);
              delay(400);
              digitalWrite(ledpin[y], LOW);
              delay(100);
            }
    
            if (randomArray[x] == 3 && ledpin[y] == A2) 
            {
              digitalWrite(ledpin[y], HIGH);
              tone(A4, NOTE_B3, 100);
              delay(400);
              digitalWrite(ledpin[y], LOW);
              delay(100);
            }
  
            if (randomArray[x] == 4 && ledpin[y] == A3) 
            {
              digitalWrite(ledpin[y], HIGH);
              tone(A4, NOTE_C4, 100);
              delay(400);
              digitalWrite(ledpin[y], LOW);
              delay(100);
            }
          }
        }
      }
      input();
      if (turn == -1)
      {
        y=100;
      }
   }
}
