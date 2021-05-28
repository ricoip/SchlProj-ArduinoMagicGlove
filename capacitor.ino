#include <Capacitor.h> // Capacitor library
#include <CapacitorLite.h>
#include <Servo.h> // Servo library

/* Notes:
YELLOW = Signal
RED = 5V Power
BROWN = Ground */
int servoPinA = 3; // Servo PWM pin @ D3
Servo ServoA;

Capacitor capA(8, A5); // Capacitor @ D8 and A5


void setup() {
  Serial.begin(9600);
  ServoA.attach(servoPinA, 500, 2450);
}


void loop() {
  float capAOutput = capA.Measure();
  int rotateAngle = servoRotate(capAOutput);
  ServoA.write(rotateAngle);
  Serial.print(capAOutput);
  Serial.print(",");
  Serial.println(rotateAngle);
  delay(100);
}

int servoRotate(int input) {
  int angle = map(input, 150, 300, 0, 120);
  return angle;
}
