/*  Fade = ~3, ~5, ~6, ~9, ~10 ~11.  */

int led_00 = 5;
int led_01 = 6;
int led_02 = 9;
int led_03 = 10;
int led_04 = 11;

int bott = 3;
int buzz_00 = 2;

int delayOn = 60;
int delayOff = 30;
int delayBuzz = 1;

float endStayRate = 5.0;
bool flag = false;

int delayFade = 10;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  pinMode(led_00, OUTPUT);
  pinMode(led_01, OUTPUT);
  pinMode(led_02, OUTPUT);
  pinMode(led_03, OUTPUT);
  pinMode(led_04, OUTPUT);

  pinMode(bott, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(bott), speedUp, FALLING);
}

void fadeInNOut(int port, int delayTime)  {
  analogWrite(port, brightness);
  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(delayTime);
}

void loop() {
      fadeInNOut(led_00, delayFade);
      fadeInNOut(led_01, delayFade);      
      fadeInNOut(led_02, delayFade);      
      fadeInNOut(led_03, delayFade);      
      fadeInNOut(led_04, delayFade);
      delay(delayFade*endStayRate);
}

void speedUp()  {
  if ( delayFade > 2 ) {
    delayFade -= 1;
    digitalWrite(buzz_00, HIGH); delay(delayBuzz * endStayRate);
    digitalWrite(buzz_00, LOW);
  }
}

