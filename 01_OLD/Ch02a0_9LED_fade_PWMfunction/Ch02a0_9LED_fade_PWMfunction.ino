/*  Fade = ~3, ~5, ~6, ~9, ~10 ~11.  */

int led_00 = 3;
int led_01 = 5;
int led_02 = 6;
int led_03 = 9;   // buzzer fixed
int led_04 = 10;
int led_05 = 11;

int bott = 7;
int buzz_00 = 9;

int delayBuzz = 1;

float endStayRate = 4.0;
bool flag = false;

int delayFade = 30;     // stay each steps of fade
int brightness = 0;     // how bright the LED is -- will grow upto 255
int fadeAmount = 15;     // how many points to fade the LED by

void setup() {
  pinMode(led_00, OUTPUT);
  pinMode(led_01, OUTPUT);
  pinMode(led_02, OUTPUT);
  //  pinMode(led_03, OUTPUT);    --- buzzer fixed
  pinMode(led_04, OUTPUT);
  pinMode(led_05, OUTPUT);

  pinMode(bott, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(bott), speedUp, FALLING);
}

void fadeInNOut(int port, int delayTime)  {
  for (int i = 0; i <= 255; i += fadeAmount)  {
    brightness = i;
    analogWrite(port, brightness);
    delay(delayTime);
  }

  for (int i = 255; i >= 0; i -= fadeAmount)  {
    brightness = i;
    analogWrite(port, brightness);
    delay(delayTime);
  }
}

void loop() {
  for (int i = led_00; i <= led_05; i += 1) {
    if (i == 3 or i == 5 or i == 6 or i == 10 or i == 11) {
      fadeInNOut(i, delayFade);
    }
  }

  for (int i = led_04; i >= led_01; i -= 1) {
    if (i == 3 or i == 5 or i == 6 or i == 10 or i == 11) {
      fadeInNOut(i, delayFade);
    }
  }
}

void speedUp()  {
  if ( delayFade > 2 ) {
    delayFade -= 1;
    digitalWrite(buzz_00, HIGH); delay(delayBuzz * endStayRate);
    digitalWrite(buzz_00, LOW);
  }
}


/*
  analogWrite(led_00, brightness);
  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
*/
