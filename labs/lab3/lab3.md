# Lab 3: Data Logger (and using cool sensors!)

*A lab report by Christine Ku.*

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

0-1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

1024 = 2^10
10 bits of resolution

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

0-5V, serial monitor values: 0-1008, couldn't get to 1023

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

Linear, as resistance increases, voltage increases

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

force-sensor.ino

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**
Flex sensor: 10k
Photo Cell: 10k
Softpot: 10k to power, 10k to gnd => 20k

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**
Linear: as resistance increases, current decreases and voltage increases
### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

### 3. IR Proximity Sensor

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**

**b. Upload your merged code to your lab report repository and link to it here.**

## Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**
Yes because you want to go in a certain order and maintain which state does what throughout the execution. 

**b. Why is the code here all in the setup() functions and not in the loop() functions?**
It's not being executed continuously, only one time at the start.

**c. How many byte-sized data samples can you store on the Atmega328?**
1024 bytes

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**
Convert the data read to the byte data type after AnalogRead. For I2C, you can use the Wire.write to send the byte data over, assigning the data type within the function's argument.

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**
Split the data value up into multiple bytes and store them in consecutive addresses. 

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
