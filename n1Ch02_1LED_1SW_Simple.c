// to Learn :
// refer to https://www.youtu.be/
// to Learn pinMode(0~4, INPUT/OUTPUT), digitalRead/Write(0~4) == LOW/HIGH

int led0_Pin = 13;          // 1th LED
int Button0_Pin = 8;        // 1th Switch

void setup()  {
  pinMode(led0_Pin, OUTPUT);      // 13 = OUTPUT
  pinMode(Button0_Pin, INPUT);    // 8 = INPUT
}

void loop() {
  if (digitalRead(Button0_Pin) == LOW) {
     digitalWrite(led0_Pin) == HIGH;
   }
  else  digitalWrite(led0_Pin) == LOW;

  // ##### if Pull-up LOW -> HIGH
  //  if (digitalRead(Button0_Pin) == HIGH) {
  //     digitalWrite(led0_Pin) == HIGH;
  //   }
  //  else  digitalWrite(led0_Pin) == LOW;

}
