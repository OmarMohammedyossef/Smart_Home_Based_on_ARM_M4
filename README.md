# Smart Home Based on ARM M4
The Smart Home System is an embedded system developed using the Stm32f401cc. 
It allows users to set password at first time and control to open the door if user enter password true and button can close the door.
Then there are controller control on the Hall and rooms throw Bluetooth module control on led and air condition of every room and hall. 
# Table of Contents
 Description
 Components
 Software Architecture
# Description
First Part:
It is our system now. Smart home, In the basic needs, The first 
thing is the door system, It will be the first thing that I will set 
password, After what is left, I will stay with the password,
If I enter the password, it is rightly, which will enter me on 
the system and open the door,
In the event that I entered the password wrongly, I will have 
three attempts, After every attempt, you will miss about thirty 
seconds, And then, after that, I can write the password again, 
And so on, This is what is the security or part of the door.

Second Part:
This part where we have a hall, and we have 
the room, We have three basic needs in each part of the home, We have 2 
LEDs, one white and one yellow, We have an air conditioner , 
we have a PIR sensor, and we have an LM35 sensor, Ok, I am in control.
How do you get on the sensor or on the LEDs and the conditioner through the 
Bluetooth module, which is through UART by sending a command and every 
specific command or every number of a certain number, so it will be for a 
certain action that is taken, so if you sell one, the first hand will work, The air 
conditioner extinguishes, and so on, what is the need that I am doing with a 
control via Bluetooth Model, and I can use it through pir sensor, I still have 
two types of control only, Who is Pir sensor or By Bluetooth Module.

# Components
STM32F401CC
LCD
Keypad
Motor
PIR sensor
Buzzer
LED
Wifi Module
LM35

# Software Architecture
MCAL:
• RCC
• GPIO
• SYSTICK
• NVIC
• EXTI
• USART
• ADC

HAL:
• LED
• BUZZER
• LCD
• Keypad
• Motor
• PIR
