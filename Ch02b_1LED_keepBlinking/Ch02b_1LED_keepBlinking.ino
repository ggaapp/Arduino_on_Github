int led_00 = 5;
int led_01 = 6;
int led_02 = 7;
int led_03 = 8;
int led_04 = 9;
int led_05 = 10;
int led_06 = 11;

int led_07 = 12;
int led_08 = 13;

int bott_00 = 3;
int buzz_00 = 2;

int delayOn = 60;
int delayOff = 200;
int delayBuzz = 1;
float endStayRate = 1.5;

void setup()  {
      for (int i=led_00;i<=led_08; i+=1)  {
        pinMode(i, OUTPUT);
      }
      pinMode(bott_00, INPUT);
      pinMode(buzz_00, OUTPUT);
}

void loop() {
      for (int i=led_00;i<=led_08; i+=1)  {
            digitalWrite(i, HIGH);
      }
      delay(delayOn);
    
      digitalWrite(buzz_00, HIGH);  delay(delayBuzz);
      digitalWrite(buzz_00, LOW);
    
      for (int i=led_00;i<=led_08; i+=1)  {
            digitalWrite(i, LOW);
      }
      delay(delayOff);
}
