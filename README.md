This IoT-based project, this initiative aims to enhance road safety by utilizing an Eye Blink Sensing sensor to detect driver drowsiness, thereby mitigating the risk of accidents associated with driver fatigue.
Components used here:
1) Eye Blink Sensor (IR Infrared)
2) NodeMCU ESP8266
3) Relay Driver Module
4) DC Motor
5) NPN Transistor
6) Resistors
   
![image](https://github.com/AnanyaBaruaB/IOT_EyeBlinkAccidentAlert/assets/130342684/df5a841f-c021-4a80-b5d6-cfd2278547c5)

Circuit Diagram:
![image](https://github.com/AnanyaBaruaB/IOT_EyeBlinkAccidentAlert/assets/130342684/5d9d1e7f-b76d-40e7-8471-8997dfd9467e)

Algorithm: The Algorithm for Eye Blink Accident Detection system has been given below:
1. Start
2. Initialize sensor and LED Loop:
   
   a. Read sensor data to detect eye blinks.
 
   b. If no blink is detected for 7. seconds:
    i. Turn on the LED.
   ii. Activate the buzzer.
  iii. Stop the main motor.
   iv. Activate the break motor.
    v. Wait for 3 seconds.
   vi. Turn off the LED.
  vii. Deactivate the buzzer.
 viii. Turn off the break motor.
   ix. Go back to step 3a.
   
   c. If a blink is detected, keep the main motor running and
the break
