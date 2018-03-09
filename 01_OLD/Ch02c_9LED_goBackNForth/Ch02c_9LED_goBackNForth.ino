int led_00 = 2;
int led_01 = 3;
int led_02 = 4;
int led_03 = 5;
int led_04 = 6;

int led_05 = 10;
int led_06 = 11;
int led_07 = 12;
int led_08 = 13;

int bott_01 = 7;
int bott_00 = 8;
int buzz_00 = 9;

int delayOn = 60;
int delayOff = 30;
int delayBuzz = 1;

float endStayRate = 4.0;
bool flag = false;

void blink(int port, float dON, float dOFF) {
  digitalWrite(port, HIGH); delay(dON);
  digitalWrite(port, LOW); delay(dOFF);
}

void buzz(int buzzON) {
  digitalWrite(buzz_00, HIGH); delay(buzzON);
  digitalWrite(buzz_00, LOW);
}

void setup()  {
    for (int i = led_00; i <= led_04; i += 1) { //when you change port#, should increase by +1
        pinMode(i, OUTPUT);
    }
    for (int i = led_05; i <= led_08; i += 1) { //when you change port#, should increase by +1
        pinMode(i, OUTPUT);
    }

pinMode(buzz_00, OUTPUT);

pinMode(bott_00, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(bott_00), speedUp, FALLING);
}

void loop() {
  buzz(delayBuzz);
  blink(led_00, delayOn * endStayRate, delayOff);

  for (int i = led_01; i <= led_04; i += 1)   {
      blink(i, delayOn, delayOff);
  }
  for (int i = led_05; i <= led_07; i += 1)   {
      blink(i, delayOn, delayOff);
  }

  buzz(delayBuzz);
  blink(led_08, delayOn * endStayRate, delayOff);

  for (int i = led_07; i >= led_05; i -= 1)   {
      blink(i, delayOn, delayOff);
  }
  for (int i = led_04; i >= led_01; i -= 1)   {
      blink(i, delayOn, delayOff);
  }
}

void speedUp()  {
  if ( delayOn > 2 ) {
    delayOn -= 2;  delayOff -= 1;
    digitalWrite(buzz_00, HIGH); delay(delayBuzz * endStayRate);
    digitalWrite(buzz_00, LOW);
  }
  else {
    delayOn = 6; delayOff = 0;
    digitalWrite(buzz_00, HIGH); delay(delayBuzz * endStayRate);
    digitalWrite(buzz_00, LOW);
  }
}

