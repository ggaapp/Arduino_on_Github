// to Learn :
// refer to https://www.youtu.be/
// to Learn pinMode(0~4, INPUT/OUTPUT), digitalRead/Write(0~4) == LOW/HIGH

int led0_Pin = 0;          // 1th LED
int led1_Pin = 1;          // 2th LED
int led2_Pin = 2;          // 3th LED
int led3_Pin = 3;          // 4th LED
int led4_Pin = 4;          // 5th LED

int Button0_Pin = 8;       // 1th Switch
int Button1_Pin = 9;       // 2th Switch
int Button2_Pin = 10;      // 3th Switch
int Button3_Pin = 11;      // 4th Switch
int Button4_Pin = 12;      // 5th Switch

void setup()  {
pinMode(led0_Pin, OUTPUT);    // th LED Port Setting
pinMode(led1_Pin, OUTPUT);    // th LED Port Setting
pinMode(led2_Pin, OUTPUT);    // th LED Port Setting
pinMode(led3_Pin, OUTPUT);    // th LED Port Setting
pinMode(led4_Pin, OUTPUT);    // th LED Port Setting

pinMode(Button0_Pin, INPUT);   // th Swithch Port Setting
pinMode(Button1_Pin, INPUT);   // th Swithch Port Setting
pinMode(Button2_Pin, INPUT);   // th Swithch Port Setting
pinMode(Button3_Pin, INPUT);   // th Swithch Port Setting
pinMode(Button4_Pin, INPUT);   // th Swithch Port Setting
}

void loop() {

  if (digitalRead(Button0_Pin) == LOW) { digitalWrite(led0_Pin) == HIGH }
  else  digitalWrite(led0_Pin) == LOW

  if (digitalRead(Button1_Pin) == LOW) { digitalWrite(led1_Pin) == HIGH }
  else  digitalWrite(led1_Pin) == LOW

  if (digitalRead(Button2_Pin) == LOW) { digitalWrite(led2_Pin) == HIGH }
  else  digitalWrite(led2_Pin) == LOW

  if (digitalRead(Button3_Pin) == LOW) { digitalWrite(led3_Pin) == HIGH }
  else  digitalWrite(led3_Pin) == LOW

  if (digitalRead(Button4_Pin) == LOW) { digitalWrite(led4_Pin) == HIGH }
  else  digitalWrite(led4_Pin) == LOW

}
