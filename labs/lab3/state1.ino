// This borrows code from Examples->EEPROM->eeprom_read

byte value;
int photores;
int eeaddr;
void state1Setup() {
  Serial.println("Reading from EEPROM");
  display.setCursor(0,0);
  display.print("Playback");
  display.display();
  delay(1000);
  display.clearDisplay();
  for (int i = eeaddr; i < (eeaddr+1); i++) {
    value = EEPROM.read(i);
    if (value > 0){
    Serial.println(value);
    display.setCursor(0,0);
    display.print(value*4);
    display.display();
    delay(200);
    display.clearDisplay();
  }
  else {
    display.setCursor(0,0);
    break;
  }
  }
  Serial.println();
  eeaddr = eeaddr + 1;
  Serial.println("Done reading from EEPROM");
}

void state1Loop() {
  photores = value*4;
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
 if (photores > 800){
  setColor(80, 245, 255);
  delay(1000);
  Serial.println("blue playback");
 }
 else if (photores <650){
  setColor(255, 225, 65);
  delay(1000);
  Serial.println("yellow playback");
 }
 else {
  setColor(255, 255, 200);
  delay(1000);
  Serial.println("white playback");
  }
  display.clearDisplay();
}

void doState1() {
  if (lastState != 1) { state1Setup(); }
  state1Loop();
}
