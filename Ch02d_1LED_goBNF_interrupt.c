int led_00 = 13;
int led_01 = 12;
int led_02 = 11;
int led_03 = 10;
int led_04 = 09;
int led_05 = 08;
int led_06 = 07;
int buz_00 = 06;

int btn_00 = 05;

int delayOn = 60;
int delayOff = 30;
int delayBuzz = 30;
float endStayRate = 1.5;
bool check = false;

void blink(int port, float dON, float dOFF) {
  digitalWrite(port, HIGH); delay(dON);
  digitalWrite(port, LOW); delay(dOFF);
}

void oneturn() {
  blink(led_00, delayOn*endStayRate, delayOff);
  blink(led_01, delayOn, delayOff);
  blink(led_02, delayOn, delayOff);
  blink(led_03, delayOn, delayOff);
  blink(led_04, delayOn, delayOff);
  blink(led_05, delayOn, delayOff);
  blink(led_06, delayOn*endStayRate, delayOff);

  buzz(delayBuzz);

  blink(led_05, delayOn, delayOff);
  blink(led_04, delayOn, delayOff);
  blink(led_03, delayOn, delayOff);
  blink(led_02, delayOn, delayOff);
  blink(led_01, delayOn, delayOff);
}

void buzz(int buzzON) {
  digitalWrite(buz_00, HIGH); delay(buzzON);
  digitalWrite(buz_00, LOW);
}

void setup()  {
  pinMode(led_00, OUTPUT);
  pinMode(led_01, OUTPUT);
  pinMode(led_02, OUTPUT);
  pinMode(led_03, OUTPUT);
  pinMode(led_04, OUTPUT);
  pinMode(led_05, OUTPUT);
  pinMode(led_06, OUTPUT);
  pinMode(buz_00, OUTPUT);

  pinMode(btn_00, INPUT_PULLUP); //Pull-up interrupt
  attachInterrupt(digitalPinToInterrupt(btn_00), swInterrupt, FALLING);
  // (PIN,FUNC,OPTION) = if OPTION(CHANGE,FALLING,RAISING,LOW), go func
}

void loop() {
  delay(1000);
}

void swInterrupt() {
  if ( check == true ) {
    oneturn();
    check == false ;
  } else {
     check == true;
  }
}
