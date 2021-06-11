#include <Capacitor.h> // Capacitor library
#include <CapacitorLite.h>
#include <Servo.h> // Servo library

/* Notes:
YELLOW = Signal
RED = 5V Power
BROWN = Ground */
int servoPinA = 3; // Servo PWM pin @ D3
int servoPinB = 5;
Servo ServoA;
Servo ServoB;

Capacitor capA(9, A5); // Capacitor @ D8 and A5
Capacitor capB(11, A3);

void setup() {
  Serial.begin(9600);
  ServoA.attach(servoPinA, 500, 2450);
  ServoB.attach(servoPinB, 500, 2450);
}


void loop() {
  float capAOutput = capA.Measure();
  float capBOutput = capB.Measure();
  int rotateAngleA = servoRotateA(capAOutput);
  int rotateAngleB = servoRotateB(capBOutput);
  ServoA.write(rotateAngleA);
  ServoB.write(rotateAngleB);

  Serial.print("CapA: ");
  Serial.print(capAOutput);
  Serial.print(", ");
  Serial.print("RotateA: ");
  Serial.print(rotateAngleA);
  Serial.print(", ");
  Serial.print("CapB: ");
  Serial.print(capBOutput);
  Serial.print(", ");
  Serial.print("RotateB: ");
  Serial.println(rotateAngleB);
  
  /*
  Serial.print(capAOutput);
  Serial.print(",");
  Serial.print(rotateAngleA);
  Serial.print(",");
  Serial.print(capBOutput);
  Serial.print(",");
  Serial.println(rotateAngleB);
  */
  delay(250);
}

int servoRotateA(int input) {
  return map(input, 350, 150, 0, 180);
}

int servoRotateB(int input) {
  return map(input, 150, 350, 0, 180);
}
