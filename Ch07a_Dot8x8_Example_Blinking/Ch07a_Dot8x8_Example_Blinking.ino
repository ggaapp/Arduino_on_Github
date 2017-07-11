int pins[17] = { -1,  13, 12, 11, 10, 9,  8,  7, 6,  5, 4, 3, 2, 14, 15, 16, 17 };
int cols[8] = {pins[13], pins[3], pins[4], pins[10], pins[06],pins[11], pins[15], pins[16]};
int rows[8] = {pins[9], pins[14], pins[8], pins[12], pins[1],pins[7], pins[2], pins[5]};



void setup() {
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  for (int i = 1; i <= 8; i++) {
    digitalWrite(cols[i - 1], LOW);
  }

  for (int i = 1; i <= 8; i++) {
    digitalWrite(rows[i - 1], LOW);
  }
}


void loop() {
  digitalWrite(rows[0], HIGH);

  digitalWrite(cols[0], HIGH);
  digitalWrite(cols[1], LOW);
  digitalWrite(cols[2], HIGH);
  digitalWrite(cols[3], LOW);
  digitalWrite(cols[4], HIGH);
  digitalWrite(cols[5], LOW);
  digitalWrite(cols[6], HIGH);
  digitalWrite(cols[7], LOW);
  delay(500);

  digitalWrite(rows[0], LOW);
  delay(500);

}
