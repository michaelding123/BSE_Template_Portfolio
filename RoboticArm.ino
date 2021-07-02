#include "BluetoothSerial.h"
#include <ESP32Servo.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Define servo motors
Servo right;
Servo left;
Servo claw;
Servo swivel;

// Servo motor pin numbers on ESP32
int rightPin = 18;
int leftPin = 23;
int clawPin = 22;
int swivelPin = 4;

// Set pin numbers for the trigger and echo pins on the Ultrasonic Sensor
const int pingPin = 27;
const int echoPin = 26;

// Motor previous positions
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos;

// User input values
String inputString;
String servochoice;
int positionval;

BluetoothSerial SerialBT;

void setup() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  right.setPeriodHertz(50);

  // Attach the servo motors with each pin number to its corresponding variable
  right.attach(rightPin, 500, 2400);
  left.attach(leftPin, 500, 2400);
  claw.attach(clawPin, 500, 2400);
  swivel.attach(swivelPin, 500, 2400);
  
  // Set initial positions for servo motors.
  servo1PPos = 45;
  servo2PPos = 120;
  servo3PPos = 90;
  servo4PPos = 90;
  right.write(servo1PPos);
  left.write(servo2PPos);
  claw.write(servo3PPos);
  swivel.write(servo4PPos);

  // Begin the Serial
  Serial.begin(115200);
  SerialBT.begin();
  
  //Set initial values
  inputString = "";
  servochoice = "s1";
  positionval = 90;
}

void loop() {
  
  //App sends signals through Bluetooth
  if (SerialBT.available())
  {
    char inChar = (char)SerialBT.read();
    inputString += inChar;

    // Determine servo choice and position once a new line is received from the app
    if (inChar == '\n') {
      String str = inputString;
      servochoice = inputString.substring(0, 2);
      positionval = inputString.substring(2, inputString.length()).toInt();
      inputString = "";
    }

    // Move the right servo motor if choice is s1
    if (servochoice.equals("s1")) {
      if (positionval > servo1PPos) {
        for (int i = servo1PPos; i <= positionval; i++) {
          right.write(i);
          delay(15);
        }
      } else {
        for (int i = servo1PPos; i >= positionval; i--) {
          right.write(i);
          delay(15);
        }
      }
      servo1PPos = positionval;
    }

    // Move the left servo motor if choice is s2
    else if (servochoice.equals("s2")) {
      if (positionval > servo2PPos) {
        for (int i = servo2PPos; i <= positionval; i++) {
          right.write(i);
          delay(15);
        }
      } else {
        for (int i = servo2PPos; i >= positionval; i--) {
          right.write(i);
          delay(15);
        }
      }
      servo2PPos = positionval;
    }

    // Move the claw servo motor if choice is s3
    else if (servochoice.startsWith("s3")) {
      if (positionval > servo3PPos) {
        for (int i = servo3PPos; i <= positionval; i++) {
          claw.write(i);
          delay(15);
        }
      } else {
        for (int i = servo3PPos; i >= positionval; i--) {
          claw.write(i);
          delay(15);
        }
      }
      servo3PPos = positionval;
    }

    // Move the swivel servo motor if choice is s4
    else if (servochoice.startsWith("s4")) {
      if (positionval > servo4PPos) {
        for (int i = servo4PPos; i <= positionval; i++) {
          swivel.write(i);
          delay(15);
        }
      } else {
        for (int i = servo4PPos; i >= positionval; i--) {
          swivel.write(i);
          delay(15);
        }
      }
      servo4PPos = positionval;
    }

  }
  
  delay(20);

  //Calculates object's distance from ultrasonic sensor
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);

  // Close claw depending on distance from object
  if(inches < 3) {
    claw.write(60);
    servo3PPos = 60;
  }
  
  delay(15);
}

// Converts sensor's time value to distance in inches
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
