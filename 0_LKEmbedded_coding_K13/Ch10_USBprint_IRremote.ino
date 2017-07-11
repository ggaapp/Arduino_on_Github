/*
 * 적외선 IR 리모콘 통신을 위해 IRremote.h 헤더 파일을 include 한다.
 */ 
#include <IRremote.h>
/*
    * 각 핀 정의
 */
int RECV_PIN = 2; // IR 수신센서
IRrecv irrecv(RECV_PIN);
decode_results results;
 
void setup() // 초기화
{
    Serial.begin(9600); // 시리얼통신 사용, 통신 보레이트 9600bps 설정 
    irrecv.enableIRIn(); // 수신센서 감지 시작(Start the receiver) 
}
/*
* IR리모콘 버튼을 누르면 적외선 신호가 IR 리모콘 수신센서가 감지하며, 
* 수신 된 데이터 값을 분석 한 후, 수신값을 시리얼통신을 이용하여 전송하여 PC에서 확인 하도록 한다.
*/
void loop() // 무한루프 
{
    if(irrecv.decode(&results)){
        if(results.decode_type == NEC){
          switch(results.value){
            case 0x00FF6897: // Key 0
                Serial.println("Press '0'"); // 시리얼통신으로 데이터 출력 "Press '0'"
                break;
            case 0x00FF30CF: // Key 1
                Serial.println("Press '1'"); // 시리얼통신으로 데이터 출력 "Press '1'"
                break;
            case 0x00FF18E7: // Key 2
                Serial.println("Press '2'"); // 시리얼통신으로 데이터 출력 "Press '2'"
                break;
            case 0x00FF7A85: // Key 3
                Serial.println("Press '3'"); // 시리얼통신으로 데이터 출력 "Press '3'"
                break;
            case 0x00FF10EF: // Key 4
                Serial.println("Press '4'"); // 시리얼통신으로 데이터 출력 "Press '4'"
                break;
            case 0x00FF38C7: // Key 5
                Serial.println("Press '5'"); // 시리얼통신으로 데이터 출력 "Press '5'"
                break;
            case 0x00FF5AA5: // Key 6
                Serial.println("Press '6'"); // 시리얼통신으로 데이터 출력 "Press '6'"
                break;
            case 0x00FF42BD: // Key 7
                Serial.println("Press '7'"); // 시리얼통신으로 데이터 출력 "Press '7'"
                break;
            case 0x00FF4AB5: // Key 8
                Serial.println("Press '8'"); // 시리얼통신으로 데이터 출력 "Press '8'"
                break;
            case 0x00FF52AD: // Key 9
                Serial.println("Press '9'"); // 시리얼통신으로 데이터 출력 "Press '9'"
                break;
            default:
                break;
          }           
        }
        irrecv.resume();  // 다음 값 수신(Receive the next value)
    }
}

