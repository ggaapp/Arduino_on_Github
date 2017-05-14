/*  Fade = ~3, ~5, ~6, ~9, ~10 ~11.  */

int led_00 = 5;
int led_01 = 6;
int led_02 = 9;
int led_03 = 10;
int led_04 = 11;

int bott = 3;
int buzz_00 = 2;
int delayBuzz = 10;
float endStayRate = 5.0;

int delayFade = 40;
int brightness = 0;    // how bright the LED is
int fadeAmount = 10;    // how many points to fade the LED by

void setup() {
  pinMode(led_00, OUTPUT);
  pinMode(led_01, OUTPUT);
  pinMode(led_02, OUTPUT);
  pinMode(led_03, OUTPUT);
  pinMode(led_04, OUTPUT);
  
  pinMode(bott, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(bott), speedUp, FALLING);
}

void light(int b0, int b1, int b2, int b3, int b4 )  {
    analogWrite(led_00, b0);
    analogWrite(led_01, b1);
    analogWrite(led_02, b2);
    analogWrite(led_03, b3);
    analogWrite(led_04, b4);
}


void speedUp()  {
  if ( delayFade >= 4 ) {
    delayFade -= 2;
    digitalWrite(buzz_00, HIGH); delay(100);
    digitalWrite(buzz_00, LOW);
  }
}

void loop() {
  for (int i=0; i<=100; i+=20)  {
    light(255-i, 0, 0, 0, 0);
    delay(delayFade);
  }
  
  for (int i=0; i<=100; i+=20)  {
    light(155-i, 255-i, 0, 0, 0);
    delay(delayFade);
  }
    
  for (int i=0; i<=100; i+=20)  {
    light(55-i, 155-i, 255-i, 0, 0);
    delay(delayFade);
  }
  
  for (int i=0; i<=100; i+=20)  {
    light(0, 55-i, 155-i, 255-i, 0);
    delay(delayFade);
  }
  
  for (int i=0; i<=100; i+=20)  {
    light(0, 0, 55-i, 155-i, 255-i);
    delay(delayFade);
  }

  for (int i=0; i<=100; i+=20)  {
    light(0, 0, 0, 255-i, 155-i);
    delay(delayFade);
  }

  for (int i=0; i<=100; i+=20)  {
    light(0, 0, 255-i, 155-i, 55-i);
    delay(delayFade);
  }

  for (int i=0; i<=100; i+=20)  {
    light(0, 255-i, 155-i, 55-i, 0);
    delay(delayFade);
  }

  for (int i=0; i<=100; i+=20)  {
    light(255-i, 155-i, 55-i, 0, 0);
    delay(delayFade);
  }







}


