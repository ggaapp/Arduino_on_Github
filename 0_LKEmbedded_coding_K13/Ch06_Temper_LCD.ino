//LK임베디드
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int Sound_Sensor = A0; //A0에 센서연결
int Sensor_val;        //센서 ADC값 저장 변수
int Temp_A;            //온도값
int Temp_B;            //온도소수점값
void setup()
{
  lcd.init();                      // LCD 출력준비
  lcd.backlight();                //LCD 백라이트 ON
  lcd.setCursor(5, 0);            //쓰기 좌표 1번줄에 5번칸
  lcd.print("LM35DZ");            // LCD에 LM35DZ 출력
  
  lcd.setCursor(1, 1);            //쓰기 좌표 2번줄에 1번칸
  lcd.print("TEMP:");             //LCD에 TEMP: 출력
  
}
/*
온도값을 텍스트LCD에 표시한다.
*/

void loop()
{
  Sensor_val = analogRead(Sound_Sensor);       //센서값을 읽어와서 Sensor_val에 넣는다
  Sensor_val = map(Sensor_val,0,1023,0,1100);  //0~1023 들어오는 값을 0~1100으로 변경
  Sensor_val = (float)Sensor_val*4.6;          //LM35DZ의 아날로그 값을 온도값으로 변경
  Temp_A = Sensor_val/10;                      //소수점 이상값
  Temp_B = Sensor_val%10;                      //소수점 이하값
  lcd.setCursor(7, 1);                         //쓰기 좌표 2번줄에 7번칸
  lcd.print(Temp_A);                          //Temp_A 값 LCD에 출력
  lcd.print(".");                             //LCD에 . 출력
  lcd.print(Temp_B);                          //Temp_B 값 LCD에 출력
  lcd.print("C");                             //LCD에 C 출력
}
