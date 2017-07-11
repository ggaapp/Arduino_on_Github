int led_00 = 2;
int led_01 = 3;
int led_02 = 4;
int led_03 = 5;
int led_04 = 6;

int led_05 = 10;
int led_06 = 11;
int led_07 = 12;
int led_08 = 13;

int bott_01 = 7;    // PULL_DOWN SW
int bott_00 = 8;    // PULL_UP SW
int buzz_00 = 9;

int delayOn = 20;
int delayOff = 60;
int delayBuzz = 1;

void setup()  {
  pinMode(led_00, OUTPUT);    // LED #1
  pinMode(led_01, OUTPUT);    // LED #1
  pinMode(led_02, OUTPUT);    // LED #1
  pinMode(led_03, OUTPUT);    // LED #1
  pinMode(led_04, OUTPUT);    // LED #1
  pinMode(led_05, OUTPUT);    // LED #1
  pinMode(led_06, OUTPUT);    // LED #1
  pinMode(led_07, OUTPUT);    // LED #1
  pinMode(led_08, OUTPUT);    // LED #1

  pinMode(buzz_00, OUTPUT);    // Buzzer

  pinMode(bott_00, INPUT);
  pinMode(bott_01, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(bott_01), swInterrupt, FALLING);

}

void loop() {
  goLeft();
  goRight();
}

void swInterrupt() {
  if ( digitalRead(bott_01) == HIGH ) {
    digitalWrite(buzz_00, HIGH); delay(1000);
    digitalWrite(buzz_00, LOW);
  }
}


void goLeft() {
  for (int i = led_00; i <= led_04; i += 1) {
    digitalWrite(i, HIGH);  delay(delayOn);
  }
  for (int i = led_05; i <= led_08; i += 1) {
    digitalWrite(i, HIGH);  delay(delayOn);
  }
  for (int i = led_00; i <= led_04; i += 1)  {
    digitalWrite(i, LOW);   delay(delayOff);
  }
  for (int i = led_05; i <= led_08; i += 1)  {
    digitalWrite(i, LOW);   delay(delayOff);
  }

  digitalWrite(buzz_00, HIGH); delay(delayBuzz);
  digitalWrite(buzz_00, LOW);
}

void goRight() {
  for (int i = led_08; i >= led_05; i -= 1) {
    digitalWrite(i, HIGH);  delay(delayOn);
  }
  for (int i = led_04; i >= led_00; i -= 1) {
    digitalWrite(i, HIGH);  delay(delayOn);
  }
  for (int i = led_08; i >= led_05; i -= 1)  {
    digitalWrite(i, LOW);   delay(delayOff);
  }
  for (int i = led_04; i >= led_00; i -= 1)  {
    digitalWrite(i, LOW);   delay(delayOff);
  }

  digitalWrite(buzz_00, HIGH); delay(delayBuzz);
  digitalWrite(buzz_00, LOW);
}

