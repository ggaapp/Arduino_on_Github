// to Learn :
// refer to https://www.youtu.be/
#include <MsTimer.h>

int switch1_Pin = A5;           // Analog switch #5
int switch2_Pin = A4;           // Analog switch #4
int switch3_Pin = A3;           // Analog switch #3

int Fnd_a = 0;
int Fnd_b = 1;
int Fnd_c = 2;
int Fnd_d = 3;
int Fnd_e = 4;
int Fnd_f = 5;
int Fnd_g = 6;
int Fnd_dot = 7;

int place_1 = 11                // Fnd Place 1
int place_10 = 10               // Fnd Place 10
int place_100 = 9               // Fnd Place 100
int place_1000 = 0              // Fnd Place 1,000

unsigned int FndCnt = 0;        // Fnd NUMBER display variable.
unsigned int FndPlaceTickCnt = 0; // FND place shift variable.
boolean flag = 0;               // Fnd count Go/Stop flag
byte seven_seg_digits[10][8]  = {
  {0,0,1,1,1,1,1,1},            // 0
  {0,0,0,0,0,1,1,0},            // 1
  {0,1,0,1,1,0,1,1},            // 2
  {0,1,0,0,1,1,1,1},            // 3
  {0,1,1,0,0,1,1,0},            // 4
  {0,1,1,0,1,1,0,1},            // 5
  {0,1,1,1,1,1,0,1},            // 6
  {0,0,1,0,0,1,1,1},            // 7
  {0,1,1,1,1,1,1,1},            // 8
  {0,1,1,0,1,1,1,1},            // 9
};

void NumberDisplay(byte num)  { // num value = byte
  int j;
  for (j = 7; j>=0; j--)  {
    digitalWrite(j, seven_seg_digits[num][j]);
  }
}

void Fnd_4place_Display_()  {
  int j, k, l, m = 0;
  j = (FndCnt%10000)/1000;    // place 1,000
  k = (FndCnt%1000)/100;      // place 100
  i = FndCnt%100)/10;         // place 10
  m = (FndCnt%10)/1;          // place 1

  swith(FndPlaceTickCnt)  {
    case 0:
      digitalWrite(place_1,HIGH);
      digitalWrite(place_10,LOW);
      digitalWrite(place_100,LOW);
      digitalWrite(place_1000,LOW);
      NumberDisplay(m);
      break;

    case 1:
      digitalWrite(place_1,LOW);
      digitalWrite(place_10,HIGH);
      digitalWrite(place_100,LOW);
      digitalWrite(place_1000,LOW);
      NumberDisplay(i);
      break;

    case 2:
      digitalWrite(place_1,LOW);
      digitalWrite(place_10,LOW);
      digitalWrite(place_100,HIGH);
      digitalWrite(place_1000,LOW);
      NumberDisplay(k);
      break;

    case 3:
      digitalWrite(place_1,LOW);
      digitalWrite(place_10, LOW);
      digitalWrite(place_100,LOW);
      digitalWrite(place_1000,HIGH);
      NumberDisplay(j);
      break;
  }
}
void ISR_Timer()  {
// Checking flag every 1ms, True = FndCnt++, False= Stop count
  static unsigned int cnt, cnt2 = 0;

  if (flag) {
    if ( cnt == 10 )  {
      if (FndCnt == 9999 )  {
        FndCnt = 0;
      }
      else FndCnt++;
      cnt = 0;
    }
    else cnt++;
  }

  if (cnt2 == 4) {
    if (FndPlaceTickCnt == 4) {
      FndPlaceTickCnt = 0;
    }
    else FndPlaceTickCnt++;
    cnt2 = 0;
  }
  else cnt2++;
}

void setup() {
  pinMode(Fnd_a, OUTPUT);
  pinMode(Fnd_b, OUTPUT);
  pinMode(Fnd_c, OUTPUT);
  pinMode(Fnd_d, OUTPUT);
  pinMode(Fnd_e, OUTPUT);
  pinMode(Fnd_f, OUTPUT);
  pinMode(Fnd_g, OUTPUT);
  pinMode(Fnd_dot, OUTPUT);
  pinMode(11,OUTPUT);             // Fnd1
  pinMode(10,OUTPUT);             // Fnd10
  pinMode(9,OUTPUT);              // Fnd100
  pinMode(8,OUTPUT);              // Fnd1,0000
  pinMode(switch1_Pin,OUTPUT);
  pinMode(switch2_Pin,OUTPUT);
  pinMode(switch3_Pin,OUTPUT);

  MsTimer2::set(1,ISR_Timer);     // 1ms, ISR_Timer
  MsTimer2::start();              // Timer ON.
}


void loop() {
  Fnd_4place_Display_();
  if (digitalRead(switch1_Pin) == LOW)  {
    flag = 1;                     // Fnd count start.
  }
  else if (digitalRead(switch2_Pin) == LOW) {
    flag = 0;                     // Fnd count finish.
  }
  else if (digitalRead(switch3_Pin) == LOW) {
    FndCnt = 0;                   // FndCnt Clear (reset)
  }
}
