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

bool flag = false;
volatile byte state = HIGH;

int delayOn = 60;
int delayOff = 30;
int delayBuzz = 30;

float endStayRate = 4.0;

void setup() {
  pinMode(led_00, OUTPUT);
  pinMode(led_01, OUTPUT);
  pinMode(led_02, OUTPUT);
  pinMode(led_03, OUTPUT);
  pinMode(led_04, OUTPUT);
  pinMode(led_05, OUTPUT);
  pinMode(led_06, OUTPUT);
  pinMode(led_07, OUTPUT);
  pinMode(led_08, OUTPUT);

  pinMode(buzz_00, OUTPUT);

  pinMode(bott_00, INPUT);  // PULL-UP SW
  pinMode(bott_01, INPUT);  // PULL-DOWN SW
}

void loop() {

  if ( digitalRead(bott_01) == HIGH ) {
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
  } else {
    for (int i = led_00; i <= led_04; i += 1) {
      digitalWrite(i, LOW);
    }
    for (int i = led_05; i <= led_08; i += 1) {
      digitalWrite(i, LOW);
    }
  }

}

/*
  void blink() {
      if ( flag == false)   {
        digitalWrite(buzz_00, HIGH); delay(delayBuzz);
        digitalWrite(buzz_00, LOW);

        state = !state;
        flag = true;
      }

      else {
        flag = false;
      }
  }
*/


void blink(int port, float dON, float dOFF) {
  digitalWrite(port, HIGH); delay(dON);
  digitalWrite(port, LOW); delay(dOFF);
}

void buzz(int buzzON) {
  digitalWrite(buzz_00, HIGH); delay(buzzON);
  digitalWrite(buzz_00, LOW);
}

