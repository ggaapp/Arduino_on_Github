/*
 * 텍스트LCD 사용을 위해 LiquidCrystal.h 헤더 파일을 include 한다.
 */ 
#include <LiquidCrystal.h>
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

void Clcd_display(long data) // 텍스트 LCD 디스플레이 함수
{
  int j,k,l,m=0;
  j=(data%10000)/1000; //-------1000의자리 
  k=(data%1000)/100;  //-------100의자리 
  l=(data%100)/10;    //-------10의자리 
  m=(data%10);        //-------1의자리 
  
  lcd.setCursor(0, 0); // LCD 문자출력 시작(열,행)라인 설정 
  lcd.print("CDS10K LKE LAB"); // 메시지 출력할 내용
  lcd.setCursor(0, 1); // LCD 문자출력 시작(열,행)라인 설정 
  lcd.print("CDS10K:"); // 메시지 출력할 내용
  lcd.print(j);   //-------1000의자리 
  lcd.print(k);   //-------100의자리 
  lcd.print(l);   //-------10의자리 
  lcd.print(m);   //-------1의자리 
}
void setup() // 초기화
{
  lcd.begin(16, 2); // LCD의 가로 열과 세로 행 설정
}
/*
 * 조도센서에 출력 되는 아날로그값을 읽어 들여 텍스트 LCD에 출력하도록 한다. 
 */
void loop() // 무한루프 
{
   int sensorValue = analogRead(A0); // 조도센서에 값을 읽어 들여 sesorValue에 저장 
   Clcd_display(sensorValue);  // 텍스트 LCD 디스플레이 함수에 sensorValue 값을 전달
}

