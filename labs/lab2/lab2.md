# Lab 2: Digital Timer
### Christine Ku
#### Part A: Soldering LCD Displasy

Picture:

![lcd](https://i.imgur.com/QKqfFoE.jpg?1)

#### Part B: Writing to the LCD

*a. What voltage level do you need to power your display?*

5V.

*b. What voltage level do you need to power the display backlight?*

Operating voltage is 3.2V +/- 0.15V. 

*c. What was one mistake you made when wiring up the display? How did you fix it?*
I almost forgot to to connect the power and ground rails for the long breadboard.

*d. What line of code do you need to change to make it flash your name instead of "Hello World"?*

Line 54: lcd.print("Hello World!") --> lcd.print("Christine Ku")

*e. Include a copy of your Lowly Multimeter code in your lab write-up.*

[Lowly_Multimeter](Lowly_Multimeter.ino)

#### Part C. Using a time-based digital sensor

Encoder Serial Monitor Output Video:

[![encoder](https://i.pinimg.com/originals/11/8e/6f/118e6f39fac9344d6589c84d5ee9e667.png)](https://youtu.be/QIUVEj6iAwQ)

#### Part D. Make your Arduino sing!

*a. How would you change the code to make the song play twice as fast?*
One way is to half the note durations.

*b. What song is playing?*
Star Wars!

#### Part E. Timer

Video:

[![simon](https://i.imgur.com/UlQBVSD.jpg)](https://youtu.be/t-AV3ubxmAY)

Code:
[Simon Says Alarm](Simon_Says_Timer.ino)
