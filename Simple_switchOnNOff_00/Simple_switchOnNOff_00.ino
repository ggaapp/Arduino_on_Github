
const int buzzerPin00 = 9;
const int buttonPin00 = 8;
const int buttonPin01 = 7;

const int ledPin00 =  2;
const int ledPin01 =  3;
const int ledPin02 =  4;
const int ledPin03 =  5;
const int ledPin04 =  6;

const int ledPin05 =  10;
const int ledPin06 =  11;
const int ledPin07 =  12;
const int ledPin08 =  13;

int buttonState = 0;

void setup() { 
  for (int i = ledPin00; i <= ledPin04; i += 1) {
    pinMode(i, OUTPUT);
  }

  pinMode(buttonPin00, INPUT);    // PULL_UP SW
  pinMode(buttonPin01, INPUT);    // PULL_DOWN SW
}

void loop() {

  if (digitalRead(buttonPin00) == LOW) {
    for (int i = ledPin05; i <= ledPin08; i += 1) {
      digitalWrite(i, HIGH);
    }

  } else {
    for (int i = ledPin05; i <= ledPin08; i += 1) {
      digitalWrite(i, LOW);
    }
  }

    buttonState = digitalRead(buttonPin01);
    if (buttonState == HIGH) {
      for (int i = ledPin05; i <= ledPin08; i += 1) {
        digitalWrite(i, HIGH);
      }
    } else {
      for (int i = ledPin05; i <= ledPin08; i += 1) {
        digitalWrite(i, LOW);
      }
    }
  }
