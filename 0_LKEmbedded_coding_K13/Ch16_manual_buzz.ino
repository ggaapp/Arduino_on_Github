//LK임베디드
int Buzzer_Pin = 8; //8번핀에 부저 연결

int Tones[7] = {261, 294, 330, 349, 392, 440, 494};
//               도   레   미   파   솔   라   시 
int Tones_Number; //Tones에 들어갈 변수

void setup(){ //초기화  
}
/*
도 레 미 파 솔 라 시 를 연속적으로 연주한다.
*/
void loop(){ //연속동작

  for(Tones_Number = 0; Tones_Number<7; Tones_Number++){ //for문 7번 반복
  
  tone(Buzzer_Pin,Tones[Tones_Number]); //tone(출력핀번호, 주파수값)
  //tone함수를 이용하여 소리를 만든다
  delay(500); //0.5초 지연
  }
  noTone(Buzzer_Pin);//noTone(소리를 끌 핀번호)
  //noTone 함수를 이용하여 소리를 끈다
  delay(1000); //1초 지연
}
