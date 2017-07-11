#include <Servo.h>

const int x = A4, y = A5, servo1 = 3, servo2 = 5, buzz = 9, sw = 11;
int i=0;
float valx, valy;

Servo arm1, arm2;   // declair OBJECT

void setup(){
  arm1.attach(servo1);
  arm2.attach(servo2);

  pinMode(buzz, OUTPUT);  // set buzz pin to OUTPUT

  arm1.write(85);          // initial value out of 0 ~ 169 - set middle
  arm2.write(85);          // initial value out of 0 ~ 169 - set middle
}

void loop() {
  if (i%2 == 0){
    valx = analogRead(x) / 6.5; // 1024/169 = 6.5
    arm1.write(valx);
    delay(20);
    i++;
  }

  else {
    valy = analogRead(y) / 6.5;
    arm2.write(valy);
    delay(20);
    i--;
  }

  if (digitalRead(sw) == LOW) {   // pull-up switch
    digitalWrite(buzz, HIGH);
    delay(10);
    digitalWrite(buzz, LOW);
    delay(10);
  }
