void setup() {
  for (int n = 2; n <= 13; n++) {
    pinMode(n, OUTPUT);
  }
}

void loop() {
  for (int n = 2; n <= 13; n++) {
    if (n != 9 ) {
      digitalWrite(n, HIGH);
    }
  }

}
