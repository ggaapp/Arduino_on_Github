//LK임베디드
int LED_A = 3;      //LED출력 핀
int LED_B = 2;      //LED출력 핀
int BallSW_A = 6;  //스위치 입력핀
int BallSW_B = 5;  //스위치 입력핀


void setup(){    //초기화
  pinMode(LED_A,OUTPUT);    //LED출력 설정
  pinMode(LED_B,OUTPUT);    //LED출력 설정
  
  pinMode(BallSW_A,INPUT_PULLUP);  //스위치 풀업 입력설정
  pinMode(BallSW_B,INPUT_PULLUP);  //스위치 풀업 입력설정
}
/*
볼스위치와 LED를 연동한다.
*/
void loop(){    //반복문
  if(digitalRead(BallSW_A) == LOW){  //만약 볼스위치A가 ON이 되면
    digitalWrite(LED_A,HIGH);        //LED_A를 ON시켜주고
  }
  else{                              //볼스위치A가 OFF가 되면
    digitalWrite(LED_A,LOW);         //LED_A를 OFF시켜주 준다
  }
  
  if(digitalRead(BallSW_B) == LOW){  //만약 볼스위치B가 ON이 되면
    digitalWrite(LED_B,HIGH);        //LED_B를 ON시켜주고
  }
  else{                              //볼스위치B가 OFF가 되면
    digitalWrite(LED_B,LOW);         //LED_B를 OFF시켜주 준다
  }


}
