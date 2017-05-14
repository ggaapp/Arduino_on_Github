int led_00 = 5; int led_01 = 6; int led_02 = 7; int led_03 = 8; int led_04 = 9; int led_05 = 10; int led_06 = 11;

int led_07 = 12; int led_08 = 13;

int btn_00 = 3;
int buz_00 = 2;

int delayOn = 60;
int delayOff = 30;
int delayBuzz = 1;

float endStayRate = 3.0;
bool check = false;
int count = 1;
int push = 0;

void blink(int port, float dON, float dOFF) {
  digitalWrite(port, HIGH); delay(dON);
  digitalWrite(port, LOW); delay(dOFF);
}

void buzz(int buzzON) {
  digitalWrite(buz_00, HIGH); delay(buzzON);
  digitalWrite(buz_00, LOW);
}

void oneturn() {
  buzz(delayBuzz);
  push = led_00;
  blink(led_00, delayOn*endStayRate, delayOff);
  for ( int i = led_01; i <=led_05; i+=1 ) {
    push = i;
    blink(i, delayOn, delayOff);
  }

  buzz(delayBuzz);
  push = led_06;
  blink(led_06, delayOn*endStayRate, delayOff);

  for( int i=led_05; i>=led_01; i-=1) {
    push = i;
    blink(i, delayOn, delayOff);
  }
}


void setup()  {
  pinMode(led_00, OUTPUT);
  pinMode(led_01, OUTPUT);
  pinMode(led_02, OUTPUT);
  pinMode(led_03, OUTPUT);
  pinMode(led_04, OUTPUT);
  pinMode(led_05, OUTPUT);
  pinMode(led_06, OUTPUT);
  pinMode(led_07, OUTPUT);
  pinMode(led_08, OUTPUT);

  pinMode(buz_00, OUTPUT);
  pinMode(btn_00, INPUT_PULLUP); //Pull-up interrupt
  attachInterrupt(digitalPinToInterrupt(btn_00), swInterrupt, LOW);
  // (PIN,FUNC,OPTION) = if OPTION(CHANGE,FALLING,RAISING,LOW), go func
}

void loop() {
  oneturn();
}

void swInterrupt() {
    if ( digitalRead(led_00) == HIGH) {
        if ( delayOn >= 4 ) {
            delayOn = delayOn - 2;
            delayOff = delayOff -1;
        }     
        digitalWrite(led_07,LOW); 
        digitalWrite(led_08,LOW);     
        buzz(60);
        for (int i = led_00 ;i <=led_06;i+=1) {
              digitalWrite(i,HIGH); delay(delayOn);
              buzz(20);
        }
        delay(2000);
    }
    else {
            for (int k=0; k<=3; k+=1)   {
                    digitalWrite(led_07,HIGH); 
                    digitalWrite(led_08,HIGH);
                    digitalWrite(push,HIGH);
                    buzz(20);
                    
                    digitalWrite(led_07,LOW); 
                    digitalWrite(led_08,LOW);
                    digitalWrite(push,LOW);
                    buzz(20);
           }
          digitalWrite(led_07,HIGH); 
          digitalWrite(led_08,HIGH);
            
        }
        delay(2000);
}    
