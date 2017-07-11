// to Learn : Tone (pin, frequency, duration)
// Tone (pin, frequency, duration) <--> noTone (pin)
// refer to https://www.youtube.com/watch?v=IZpQkZkjgcE

int switch0_Pin = 7;                  // PIN #
int relay0_Pin = 0;                   // PIN #
int buzzer0_Pin = 13;                 // PIN #

void setup()  {
  pinMode(switch0_Pin, INPUT);        //Pin setting IN ans OUTPUT
  pinMode(relay0_Pin , OUTPUT);       //Pin setting IN ans OUTPUT
  pinMode(buzzer0_Pin, OUTPUT);       //Pin setting IN ans OUTPUT
  }

void loop() {
  if ( digitalRead(switch0_Pin) == LOW )
    {
      digitalWrite(relay0_Pin, HIGH);
      Tone(buzzer0_Pin, 500, 1000);   // 500 = frequency, 1000ms = 1 sec
    }
  else
    { digitalWrite(relay0_Pin, LOW); }
}
