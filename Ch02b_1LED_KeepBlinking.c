// to Learn :
// refer to https://www.youtu.be/
// to Learn pinMode(0~4, INPUT/OUTPUT), digitalRead/Write(0~4) == LOW/HIGH

int led0_Pin = 13;          // 1th LED
int Button0_Pin = 8;        // 1th Switch
int Buzz0_pin = 10;         // ADD Active Buzzer

void setup()  {
  pinMode(Buzz0_pin, OUTPUT);   // 10 = OUTPUT
  pinMode(led0_Pin, OUTPUT);    // 13 = OUTPUT

  pinMode(Button0_Pin, INPUT);  // 8 = INPUT
}

void loop() {
  digitalWrite(10, HIGH);       // Buzz ON
  digitalWrite(13, HIGH);       // LED on
  delay(500);                   // 500ms = 0.5 sec

  digitalWrite(10, LOW);        // Buzz OFF
  digitalWrite(13, LOW);        // LED off
  delay(500);                   // 500ms = 0.5 sec
}
