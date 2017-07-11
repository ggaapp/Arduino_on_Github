/*
 * FND에 표현할 숫자 값을 2진수 배열형태로 선언 함 
 */
byte seven_seg_digits[10][8] = {
  // h, g, f, e, d, c, b, a
  {0, 0, 1, 1, 1, 1, 1, 1},  // 0
  {0, 0, 0, 0, 0, 1, 1, 0},  // 1
  {0, 1, 0, 1, 1, 0, 1, 1},  // 2
  {0, 1, 0, 0, 1, 1, 1, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1, 0},  // 4
  {0, 1, 1, 0, 1, 1, 0, 1},  // 5
  {0, 1, 1, 1, 1, 1, 0, 1},  // 6
  {0, 0, 1, 0, 0, 1, 1, 1},  // 7
  {0, 1, 1, 1, 1, 1, 1, 1},  // 8
  {0, 1, 1, 0, 1, 1, 1, 1}   // 9
 };
 /*
 * 각 핀 정의 
 */
int Switch1_Pin = A1;	// 스위치1
int Switch2_Pin = A2;	// 스위치2
int Switch3_Pin = A3;	// 스위치3
int Switch4_Pin = A4;	// 스위치4
int Switch5_Pin = A5;	// 스위치5

int Fnd_a = 0; // FND "a"자리 핀 
int Fnd_b = 1; // FND "b"자리 핀 
int Fnd_c = 2; // FND "c"자리 핀 
int Fnd_d = 3; // FND "d"자리 핀 
int Fnd_e = 4; // FND "e"자리 핀 
int Fnd_f = 5; // FND "f"자리 핀 
int Fnd_g = 6; // FND "g"자리 핀 
int Fnd_dot = 7; // FND "dot"자리 핀 

void setup() // 초기화
{      
  pinMode(Fnd_a, OUTPUT); // Fnd 'a' 위치의 핀 출력포트 설정 
  pinMode(Fnd_b, OUTPUT); // Fnd 'b' 위치의 핀 출력포트 설정 
  pinMode(Fnd_c, OUTPUT); // Fnd 'c' 위치의 핀 출력포트 설정 
  pinMode(Fnd_d, OUTPUT); // Fnd 'd' 위치의 핀 출력포트 설정 
  pinMode(Fnd_e, OUTPUT); // Fnd 'e' 위치의 핀 출력포트 설정 
  pinMode(Fnd_f, OUTPUT); // Fnd 'f' 위치의 핀 출력포트 설정 
  pinMode(Fnd_g, OUTPUT); // Fnd 'g' 위치의 핀 출력포트 설정 
  pinMode(Fnd_dot, OUTPUT); // Fnd 'dot' 위치의 핀 출력포트 설정 
  writeDot(0);  // FND에 도트(Dot) LED OFF

  pinMode(Switch1_Pin, INPUT); // 스위치 1번핀 입력포트 설정 
  pinMode(Switch2_Pin, INPUT); // 스위치 2번핀 입력포트 설정 
  pinMode(Switch3_Pin, INPUT); // 스위치 3번핀 입력포트 설정 
  pinMode(Switch4_Pin, INPUT); // 스위치 4번핀 입력포트 설정 
  pinMode(Switch5_Pin, INPUT); // 스위치 5번핀 입력포트 설정 
}
void writeDot(byte dot) // 도트(Dot) Led On/Off 함수
{
  digitalWrite(7, dot);
}    
void NumberDisplay(byte num) // FND 디스플레이 함수 
{
   int j;
   for(j=7; j>=0; j--){ // a ~ g
        digitalWrite(j, seven_seg_digits[num][j]);
   }
}
/*
 * 스위치를 이용하여 FND에 출력 되는 숫자를 표현할 수 있다.
 * 다수의 스위치를 사용하는 만큼 다른 기능도 추가하여 구현 할 수 있다. 
 */
void loop()
{
  if(digitalRead(Switch1_Pin) == LOW) // 첫 번째 스위치 누르면?
  {
    NumberDisplay(1);
  }
  else if(digitalRead(Switch2_Pin) == LOW) // 두 번째 스위치 누르면?
  {
      NumberDisplay(3);
  }
  else if(digitalRead(Switch3_Pin) == LOW) // 세 번째 스위치 누르면?
  {
      NumberDisplay(5);
  }  
  else if(digitalRead(Switch4_Pin) == LOW) // 네 번째 스위치 누르면?
  {
      NumberDisplay(7);
  }
    else if(digitalRead(Switch5_Pin) == LOW) // 다섯 번째 스위치 누르면?
  {
      NumberDisplay(9);
  }
  else  // 스위치를 누르지 않을 경우?
  {
      NumberDisplay(0);
  } 
}

