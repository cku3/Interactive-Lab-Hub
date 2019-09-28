// This borrows code from Examples->EEPROM->eeprom_write

//String textarray = "hello cornell tech!";
int endAddr;
int photoresW; 
byte bytephoto;
int address;
void state2Setup() {
  digitalWrite(ledPin, LOW);
  Serial.println("Writing to EEPROM");
  photoresW = analogRead(A3);
  bytephoto = photoresW/4;
  //if any of the pin settings for the different states differed for the different states, you could change those settings here.
  //endAddr = min(String(photoresW).length(), EEPROMSIZE);
  for (int i = address; i < (address+1); i++) {
    EEPROM.write(i, bytephoto);
    Serial.println(photoresW);
    display.setCursor(0,0);
    display.print(photoresW);
    display.display();
  }
  address = address + 1;
  Serial.println("photoresW committed to EEPROM!");
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  if (photoresW > 800){
  setColor(80, 245, 255);
  delay(1000);
  Serial.println("blue");
 }
 else if (photoresW <650){
  setColor(255, 225, 65);
  delay(1000);
  Serial.println("yellow");
 }
 else {
  setColor(255, 255, 200);
  delay(1000);
  Serial.println("white");
  }
 display.clearDisplay();
}

void doState2() {
  if (lastState != 2) state2Setup();
  state2Loop();
}
