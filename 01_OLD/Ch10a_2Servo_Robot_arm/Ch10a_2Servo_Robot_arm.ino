#include <Servo.h>

Servo mServo00;   // object0
Servo mServo01;   // object1

const int servo_00 = 3;
const int servo_01 = 5;

int timeStep = 1000;
int timeSwing = 30;

int buz_00 = 9;

void setup()  {
  Serial.begin(115200);    // baud rate = 115200
  Serial.println("Hello Arduino!");

  mServo00.attach(servo_00);  // initailize00
  mServo01.attach(servo_01);  // initailize01

  pinMode(buz_00, OUTPUT);
}

void lowArm_0() {
  mServo00.write(0);  delay(timeStep);
}

void lowArm_90() {
  mServo00.write(80);  delay(timeStep);
}

void lowArm_180() {
  mServo00.write(165);  delay(timeStep);
}

void lowArm_open() {
  for (int n = 5; n <= 169; n += 5) {
    mServo00.write(n);
    buzz(1);
    delay(timeSwing);
  }
}

void lowArm_close() {
  for (int n = 169; n >= 5; n -= 5) {
    mServo00.write(n); buzz(1);
    delay(timeSwing);
  }
}

void loop() {
  lowArm_0(); lowArm_90(); upperArm_open(); lowArm_close();
  lowArm_180();
  lowArm_close();upperArm_90();  lowArm_open();
  upperArm_close();

  buzz(30);
  delay(5000);
}

void buzz(int buzzON) {
  digitalWrite(buz_00, HIGH); delay(buzzON);
  digitalWrite(buz_00, LOW);
}

void upperArm_0() {
  mServo01.write(0);  delay(timeStep);
}

void upperArm_90() {
  mServo01.write(80);  delay(timeStep);
}

void upperArm_180() {
  mServo01.write(165);  delay(timeStep);
}

void upperArm_open() {
  for (int n = 5; n <= 169; n += 5) {
    mServo01.write(n);
    buzz(1);
    delay(timeSwing);
  }
}

void upperArm_close() {
  for (int n = 169; n >= 5; n -= 5) {
    mServo01.write(n); buzz(1);
    delay(timeSwing);
  }
}
