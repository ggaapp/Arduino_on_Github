//LK임베디드

int dataPin = 2; //74HC595dml 14번 핀과 연결
int holdPin = 3; // 74HC595dml 12번 핀과 연결
int shiftPin = 4; // 74HC595dml 11번 핀과 연결

void setup() {
  pinMode(dataPin, OUTPUT);  //dataPin출력설정
  pinMode(holdPin, OUTPUT);  //holdPin출력설정
  pinMode(shiftPin, OUTPUT); //shiftPin출력설정
}
/*
3개의 핀으로 8개의 LED를 제어한다.
*/
void loop() {
  digitalWrite(holdPin, LOW);    //holdPin LOW출력
  digitalWrite(shiftPin, LOW);   //shiftPin LOW출력
  digitalWrite(dataPin, 1);      //dataPin HIGH출력
  digitalWrite(shiftPin, HIGH);  //shiftPin HIGH출력
  digitalWrite(holdPin, HIGH);   //holdPin HIGH출력
  delay(500);                    //0.5초 지연
  
  digitalWrite(holdPin, LOW);   //holdPin LOW출력
  digitalWrite(shiftPin, LOW);  //shiftPin LOW출력
  digitalWrite(dataPin, 0);     //dataPin LOW출력
  digitalWrite(shiftPin, HIGH); //shiftPin HIGH출력
  digitalWrite(holdPin, HIGH);  //holdPin HIGH출력
  delay(500);                   //0.5초 지연
    
 
  digitalWrite(holdPin, HIGH); //holdPin HIGH출력
}
