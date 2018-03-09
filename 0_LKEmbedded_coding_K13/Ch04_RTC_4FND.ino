//LK임베디드
#define CLK_PIN 4
#define DAT_PIN 3
#define RST_PIN 2
 
#include <DS1302.h>
 
byte seven_seg_digits[10][8] = {
  // dp, g, f, e, d, c, b, a
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
  unsigned int FndCnt = 0;
  unsigned int FndPlaceTickCnt = 0;
  char* Read_Time;    //RTC에서 시간값 읽어오는 변수
  int N1, N2, N3, N4; //FND에 띄우기 위해 값을 변조하는 변수
  
  int place_1 = 10; // fnd1의 자리 
  int place_10 = 11; // fnd10의 자리
  int place_100 = 12; // fnd100의 자리
  int place_1000 = 13; // fnd1000의 자리
  
  //각각 FND에 매칭이 되는 아두이노 핀 변수
  int a = 9;
  int b = 8;
  int c = 7;
  int d = 6;
  int e = 5;
  int f = 1;
  int g = 0;
  int dp = 14;
 
/* Initialise the DS1302 library */
DS1302 rtc(RST_PIN, DAT_PIN, CLK_PIN);
 
void setup()
{
  
  //정지 플레그 제거
  rtc.halt(false);
  //비활성화 쓰기 방지
  rtc.writeProtect(false);
  
  //모든핀 출력 설정
  pinMode(a, OUTPUT); //a
  pinMode(b, OUTPUT); //b
  pinMode(c, OUTPUT); //c
  pinMode(d, OUTPUT); //d
  pinMode(e, OUTPUT); //e
  pinMode(f, OUTPUT); //f
  pinMode(g, OUTPUT); //g
  pinMode(dp, OUTPUT); //dp
  
  pinMode(place_1, OUTPUT); //fnd1
  pinMode(place_10, OUTPUT); //fnd10
  pinMode(place_100, OUTPUT); //fnd100
  pinMode(place_1000, OUTPUT); //fnd1000
  
    
  
  rtc.setDOW(THURSDAY); //요일
  rtc.setTime(21,20,55); //setTime(시,분,초) 초기 셋팅
  rtc.setDate(30,10,2015); // setDate(일,월,년); 초기 셋팅
}
 
void NumberDisplay(byte num) //FND에 숫자를 띄우는 함수
{
   digitalWrite(a, seven_seg_digits[num][7]);
   digitalWrite(b, seven_seg_digits[num][6]);
   digitalWrite(c, seven_seg_digits[num][5]);
   digitalWrite(d, seven_seg_digits[num][4]);
   digitalWrite(e, seven_seg_digits[num][3]);
   digitalWrite(f, seven_seg_digits[num][2]);
   digitalWrite(g, seven_seg_digits[num][1]);
   digitalWrite(dp, seven_seg_digits[num][0]);
  
 }
 
void Fnd_4place_Display_()//FND를 4개를 동시에 제어하는 함수
{
  int j,k,l,m=0;
  delay(5);
  switch(FndPlaceTickCnt){
    case 0:
    m=(FndCnt%10);        //-------1의자리
    digitalWrite(place_1,LOW);  digitalWrite(place_10,HIGH);  digitalWrite(place_100,HIGH);  digitalWrite(place_1000,HIGH);
    NumberDisplay(m);
    break;
    case 1:
    l=(FndCnt%100)/10;    //-------10의자리 
    digitalWrite(place_1,HIGH);  digitalWrite(place_10,LOW);  digitalWrite(place_100,HIGH);  digitalWrite(place_1000,HIGH);
    NumberDisplay(l);
    break;
    case 2:
    k=(FndCnt%1000)/100;  //-------100의자리 
    digitalWrite(place_1,HIGH);  digitalWrite(place_10,HIGH);  digitalWrite(place_100,LOW);  digitalWrite(place_1000,HIGH);
    NumberDisplay(k);
    break;
    case 3:
    j=(FndCnt%10000)/1000;//-------1000의자리 
    digitalWrite(place_1,HIGH);  digitalWrite(place_10,HIGH);  digitalWrite(place_100,HIGH);  digitalWrite(place_1000,LOW);
    NumberDisplay(j);
    break;
  }
  FndPlaceTickCnt++;
  if(FndPlaceTickCnt==4) FndPlaceTickCnt = 0;
  
  
}
/*
RTC모듈로 지정된 시간을 4FND로 표시한다.
*/
void loop()
{
  
  Read_Time = rtc.getTimeStr();//FND의 시간값을 읽어서 Read_Time에 넣는다
  //XX:YY:ZZ
  //읽어온 시간값은 아스키코드 값으로 바로 FND에는 띄울 수 없다
  //그러므로 포인터변수인 Read_Time에 넣어서 배열로 원하는 부분을 가져온다
  //단 Read_Time의 2와 5는 시분초를 나누는' : '이 들어 있으므로 주의한다
  
  N1=(Read_Time[3]-48)*1000; //분의 10의자리
  N2=(Read_Time[4]-48)*100;  //분의 1의자리
  N3=(Read_Time[6]-48)*10;   //초의 10의자리
  N4=Read_Time[7]-48;        //초의 1의자리
  
  FndCnt=N1+N2+N3+N4;    //FndCnt에 띄워야할 숫자를 10진수값을 넣어준다
  
  Fnd_4place_Display_();  //FND에 출력
}

