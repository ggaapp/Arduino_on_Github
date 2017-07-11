
int buzzerPin00 = 9;
int buttonPin00 = 8, buttonPin01 = 7;

int ledPin00 =  2,  ledPin01 =  3,  ledPin02 =  4,  ledPin03 =  5, ledPin04 =  6;
int ledPin05 =  10, ledPin06 =  11, ledPin07 =  12, ledPin08 =  13;

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
