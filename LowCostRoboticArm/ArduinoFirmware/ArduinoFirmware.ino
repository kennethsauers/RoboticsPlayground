#include <Servo.h>
const int ledPin = 13;
String incomingString;
int ServoId = -1;
int Angle = -1;
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Servo1.attach(4);
  Servo2.attach(12);
  Servo3.attach(6);
  Servo4.attach(7);
  Servo5.attach(8);
  Serial.println("System initilized");
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    incomingString = Serial.readString();
    if(incomingString.startsWith("Servo1")){
      int angle = incomingString.substring(7).toInt();
      Serial.print("Servo1 | ");
      Serial.println(angle);
      Servo1.write(angle);
    }
    else if (incomingString.startsWith("Servo2")){
      int angle = incomingString.substring(7).toInt();
      Serial.print("Servo2 | ");
      Serial.println(angle);
      Servo2.write(angle);
    }
    else if (incomingString.startsWith("Servo3")){
      int angle = incomingString.substring(7).toInt();
      Serial.print("Servo3 | ");
      Serial.println(angle);
      Servo3.write(angle);
    }
    else if (incomingString.startsWith("Servo4")){
      int angle = incomingString.substring(7).toInt();
      Serial.print("Servo4 | ");
      Serial.println(angle);
      Servo4.write(angle);
    }
    else if (incomingString.startsWith("Servo5")){
      int angle = incomingString.substring(7).toInt();
      Serial.print("Servo5 | ");
      Serial.println(angle);
      Servo5.write(angle);
    }
    else{
      Serial.println("Unknown Serial Command |" + incomingString);
    }
  }
}
