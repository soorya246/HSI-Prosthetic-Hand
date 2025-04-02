// Written by Jorge Nunez 
// Last changes - 04/01/2025

// Import respective library for microcontroller controll - the code below is for ESP32.
#include <ESP32Servo.h>

// Initialize all servo pins - can change to the desired pins on the microcontroller
static const int servoPin1 = 12;  
static const int servoPin2 = 26;  
static const int servoPin3 = 14;  
static const int servoPin4 = 32;  
static const int servoPin5 = 35;  
bool bool_val = False

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {

    // Initialize serial communication at 115200 baud rate or desired baud rate.
    Serial.begin(115200);
    
    // Set the frequency for the servo (50Hz typical). Repeat for all servos.
    servo1.setPeriodHertz(50);  
    servo1.attach(servoPin1);
    servo2.setPeriodHertz(50);  
    servo2.attach(servoPin2); 
    servo3.setPeriodHertz(50);  
    servo3.attach(servoPin3); 
    servo4.setPeriodHertz(50);  
    servo4.attach(servoPin4); 
    servo5.setPeriodHertz(50);
    servo5.attach(servoPin5); 
  //  Set the frequency for the servo (50Hz typical)
}
void loop() { 

    // Call functions for rotate_clockwise
    rotate_clockwise();

    // Implemenet delays to ensure the servos do not immediately go back
    // and forth without stopping.
    delay(2250)
    rotate_counterclockwise();
    delay(2250)
}

void rotate_clockwise(){
    bool bool_val = True
    // TO rotate counterclockwise, input a number such that 1000 < x < 1500.
    // Max clockwise speed is 1000, lowest is 1499, and 1500 is resting.
    servo1.writeMicroseconds(1425);
    servo2.writeMicroseconds(1425);
    servo3.writeMicroseconds(1425);
    servo4.writeMicroseconds(1425);
    servo5.writeMicroseconds(1425);

    //Since we can only control speed, set the amount of time you want the 
    // Servos to rotate in milliseconds. For example, a delay of 2250 is 2.25 seconds
    // and the servos will rotate at the speed given above for 2.25 seconds.
    delay(2250);  

    // Detach stops all commands being send to the servos - This will stop the
    // Servos completely.
    servo1.detach();
    servo2.detach();
    servo3.detach();
    servo4.detach();
    servo5.detach();
}

void rotate_counterclockwise{

    // Must use setup again to re-establish the pins, baud rate, and frequency for the 
    // Servos if clockwise was called before this.
    if bool_val == True{
        setup();
    }
    bool bool_val = False
    // To rotate counterclockwise, set the speed such that 1500 < x < 2000.
    // 1501 is the slowest speed counterclockwise, and 2000 is the fastest.
    // Write at the same speed and delay to ensure strings do not pop.

    // Speed of counterclockwise = 3000 - clockwise_speed
    servo1.writeMicroseconds(1575);
    servo2.writeMicroseconds(1575);
    servo3.writeMicroseconds(1575);
    servo4.writeMicroseconds(1575);
    servo5.writeMicroseconds(1575);
    delay(2250); 
}
