#include<Servo.h> // 서보모터 라이브러리 헤더파일 선언 
Servo myservo; // Servo 객체 선언
 
/*
*각 핀 정의 
*/
int Switch0_Pin = 8;  // 1번째 스위치
int Switch1_Pin = 9;  // 2번째 스위치
int Switch2_Pin = 10; // 3번째 스위치

void setup() // 초기화
{
  myservo.attach(9); // 서보모터 핀 선언 및 출력 포트로 설정 
  pinMode(Switch0_Pin, INPUT);  // 1번째 스위치 핀 입력포트 설정 
  pinMode(Switch1_Pin, INPUT);  // 2번째 스위치 핀 입력포트 설정 
  pinMode(Switch2_Pin, INPUT);  // 3번째 스위치 핀 입력포트 설정 
}
/*
 * 스위치를 이용하여 서보모터 회전각을 제어하도록 한다
 * 변위각: 0도, 90도, 180도
 */
void loop() // 무한루프
{
  if(digitalRead(Switch0_Pin) == LOW)  // 1번째 스위치를 누르면
  {
    myservo.write(0); // 모터 0도
  }
  else if(digitalRead(Switch1_Pin) == LOW) // 2번째 스위치를 누르면
  {
  myservo.write(90); // 모터 90도
  }
  else if(digitalRead(Switch2_Pin) == LOW) // 3번째 스위치를 누르면
  {
   myservo.write(180); // 모터 180도
  }
}

