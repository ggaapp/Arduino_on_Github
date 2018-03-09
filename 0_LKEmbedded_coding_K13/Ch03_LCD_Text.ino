/*
 * 텍스트 LCD 사용을 위해 LiquidCrystal.h 헤더 파일을 include 한다.
 */ 
#include <LiquidCrystal.h> // LiquidCrystal 헤더 파일 선언
/*
 * LiquidCrystal이라는 클래스를 lcd라는 이름으로
 * lcd(12, 11, 5, 4, 3, 2) 초기화 하라는 의미 초기화 하는 값은 반드시 현재
 * 핀배열과 일치해야만 동작 한다. 
 * 12: RS
 * 11: E
 * 2: D4
 * 3: D5
 * 4: D6
 * 5: D7
 */ 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
unsigned int time; // 시간 저장을 위한 변수
int data = 12;
void setup() // 초기화
{ 
  lcd.begin(16, 2); // LCD의 가로 열과 세로 행 설정
}
/*
 * 텍스트 LCD에 아래와 같이 문자를 출력하고 2번째 행에는 초에 해당하는 숫자가 출력 되도록 한다.
 * hello, LK World!
 * Time Sec: 1~60
 */
void loop() // 무한루프 
{
  if(time == 60) time = 0;
  time = millis()/1000; 
  /* 시간 함수 - mills()
   * 이 함수는 아두이노 보드가 현재의 프로그램을 시작한 이후 경과한 시간을 밀리 초 단위로 반환한다.
   * 즉 1000ms가 경과 후, 다시 말해 1초가 지나면 time변수에 1을 저장한다. 
   */
  
  lcd.setCursor(0, 0); // LCD 문자출력 시작(열,행)라인 설정 
  lcd.print("hello, LK World!"); // 메시지 출력할 내용
  lcd.setCursor(0, 1); // LCD 문자출력 시작(열,행)라인 설정 
  lcd.print("Time Sec:");
  lcd.print(time); // 1에서 60초를 숫자로 표현 한다. 
}

