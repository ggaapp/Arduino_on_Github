int led_n0 = 13 ;
int led_n1 = 12 ;
int led_n2 = 11;
int led_n3 = 10;
int led_n4 = 9;

int buz_n0 = 8;
int stay = 500;

void setup()  {
  pinMode(led_n0, OUTPUT);    // LED #1
  pinMode(led_n1, OUTPUT);    // LED #1
  pinMode(led_n2, OUTPUT);    // LED #1
  pinMode(led_n3, OUTPUT);    // LED #1
  pinMode(led_n4, OUTPUT);    // LED #1

  pinMode(buz_n0, OUTPUT);    // Buzzer
}

void loop() {
  for (i = 13; i>9; i--) {
    digitalWrite(i, HIGH);  delay(stay);
  }

  for (i = 13; i>9; i--)  {
    digitalWrite(i, LOW); delay(stay);
  }

  digitalWrite(buz_n0, HIGH); delay(stay);
  digitalWrite(buz_n0, LOW);  delay(stay);
}
