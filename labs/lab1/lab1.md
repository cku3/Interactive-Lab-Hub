# Lab 1: Blink and LED

### Christine Ku

Part A. Set Up a Breadboard

Photo: 
![alt text](https://i.imgur.com/PIqHuHY.jpg)

Part B. Manually Blink a LED

a. What color stripes are on a 100 Ohm resistor?

*brown-black-brown*

b. What do you have to do to light your LED?

*After the circuit with the button is made, I can light the LED by pressing the button.*

Part C. Blink a LED using Arduino
1. Blink the on-board LED

a. What line(s) of code do you need to change to make the LED blink (like, at all)?

*None, the code in the example already blinks the LED.*

b. What line(s) of code do you need to change to change the rate of blinking?

*The delay lines control the rate of the blinking.*

c. What circuit element would you want to add to protect the board and external LED?

*I would add a resistor.*

d. At what delay can you no longer perceive the LED blinking? How can you prove to yourself that it is, in fact, still blinking?

*When the delay is set to 10, the LED no longer looks like it's blinking. I can prove to myself that it is by using a multimeter to check the voltage and see that it is going high and low.*

e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.

[blink-changed.ino](https://github.com/cku3/Interactive-Lab-Hub/blob/master/labs/lab1/blink-changed.ino)

2. Blink your LED
Make a video of your LED blinking, and add it to your lab submission.

Video:

[![blinky](https://i.imgur.com/wQG5wk4.png)](https://youtu.be/jIbR6M6BAOk)

Part D. Manually fade an LED
a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?

*The LED does glow brighter and dimmer, but it does not make the LED turn off completely or as bright as possible because it restricts the resistance from being infinite or zero.*

Part E. Fade an LED using Arduino
a. What do you have to modify to make the code control the circuit you've built on your breadboard?

*I changed the led assignment from 9 to 11.*

b. What is analogWrite()? How is that different than digitalWrite()?

*digitalWrite can only be high (5V) or low (0V) vs. analogWrite which can be a range of values that you set for the pulse-width-modulation wave.*

Part F. FRANKENLIGHT!!!
1. Take apart your electronic device, and draw a schematic of what is inside.
a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"

*No, I used my broken headphones.*

b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?

*There is a mic and buttons. The mic pics up on a person talking for calls and recording when connected to a personal device. The buttons convey whether to increase or decrease volume as well as playing or stopping music/a call.*

c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?

*The device is powered by the personal device it is attached to. It has very low voltage and headphone jacks are usually less than 0.8V.*

d. Is information stored in your device? Where? How?

*There is no information stored.*

2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.
Describe what you did here.

3. Build your light!

*I stripped a broken pair of iPhone headphones and connected the audio to transistors so that the LEDs would blink to the beat of the music playing.*

Video:

[![talk](https://i.imgur.com/66Qrs95.jpg)](https://youtu.be/n-o7UD0Oijc)

Schematics: 
1. Headphone Wiring:
![alt text](http://www.circuitbasics.com/wp-content/uploads/2015/03/iPhone-Headphone-Wires-EDITED-RESIZED.jpg)
2. Headphone Jack: 
![alt text](https://i.stack.imgur.com/WpR1r.png)
3. Transistor Datasheet: https://www.st.com/resource/en/datasheet/cd00003223.pdf
4. Circuit: 
![alt text](https://i.imgur.com/F5a6K0D.jpg)

Tools and Materials:
1. 4 LEDs
2. 2 2N2222A NPN Transistors
3. 9V Battery
4. Wire
5. Headphones
6. Phone/Audio Source
7. Solder/Soldering Iron
8. Wire Stripper

Steps:
1. Strip the headphones of the outside insulation.
2. Separate wires within headphones and solder on better contact points for breadboarding.
3. Follow the schematics to wire up circuit.
4. Test one channel first and then once that is working, create the second channel. (Easier to troubleshoot 1 vs. 2)

Testing and Troubleshooting:
1. While stripping the headphones, I checked the continuity of my soldered wires to the headphone jack using a multimeter.
2. Used multimeter to check voltage drops across each component.
3. Make sure your audio source is loud enough. I spent a couple hours trying to figure out why my LEDs weren't blinking only to realize my computer didn't output a loud enough audio/high enough current to trigger the transistors.
