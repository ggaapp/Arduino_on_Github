/*
 * 각 핀 정의 
 */
int relay0_Pin =  0;	// 릴레이
int Switch0_Pin = 7;	// 스위치
int buzzer0_Pin = 13; 	// 부져

void setup(){		// 초기화
    pinMode(relay0_Pin, OUTPUT);	// 릴레이 핀 출력포트 설정 
    pinMode(Switch0_Pin, INPUT);	// 스위치 핀 입력포트 설정 
    pinMode(buzzer0_Pin, OUTPUT); 	// 부져 핀 출력포트 설정 
}
/*
 * 스위치를 누를 시에 릴레이 및 부져가 On/Off 되도록 한다
 */
void loop(){		// 무한루프
  if(digitalRead(Switch0_Pin) == LOW)	// 스위치를 누르면
  {
    digitalWrite(relay0_Pin, HIGH); 	// 릴레이 On
    tone(buzzer0_Pin, 500, 1000); 	// 500: 음의 높낮이(주파수), 1000ms: 음의 지속시간(1초)
  }
  else
  {
    digitalWrite(relay0_Pin, LOW); 	// 릴레이 Off
  }
}

