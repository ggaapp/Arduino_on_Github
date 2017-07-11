#include <IRremote.h>

IRrecv irrecv(A4);
decode_results results;
// 표시문자
byte num_list[10][8] = {{
    0b01111110,
    0b11100111,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11000011,
    0b11100111,
    0b01111110
  }, {
    0b00001110,
    0b00011110,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00111111
  }, {
    0b00111100,
    0b01111110,
    0b11100111,
    0b00000111,
    0b00001110,
    0b00011100,
    0b00111000,
    0b11111111
  }, {
    0b01111110,
    0b11100111,
    0b00001110,
    0b00011100,
    0b00001110,
    0b11000011,
    0b11100111,
    0b01111110
  }, {
    0b00001110,
    0b00011110,
    0b00110110,
    0b01100110,
    0b11000110,
    0b11111111,
    0b00000110,
    0b00000110
  }, {
    0b11111111,
    0b11111111,
    0b11100000,
    0b11100000,
    0b00111110,
    0b00000111,
    0b11000111,
    0b01111110
  }, {
    0b01111110,
    0b11100111,
    0b11000000,
    0b11000000,
    0b11111110,
    0b11100111,
    0b11100111,
    0b01111110
  }, {
    0b11111111,
    0b11000111,
    0b11001110,
    0b00001110,
    0b00011100,
    0b00011100,
    0b00111000,
    0b00111000
  }, {
    0b01111110,
    0b11100111,
    0b11000011,
    0b01100110,
    0b01100110,
    0b11000011,
    0b11100111,
    0b01111110
  }, {
    0b01111110,
    0b11100111,
    0b11000011,
    0b01111111,
    0b00000011,
    0b00000011,
    0b11100111,
    0b01111110
  }
}

void setonoff(byte state, int j) {
  for (int i = 0; i < 8; i++) {
    int a = ((state >> (i + j) & 1) == 1 ? HIGH : LOW);
    digitalWrite(i + 10, a);
  }
}

void display_pattern(byte something[8], int v) {
  for (int u = 0; u < 8; u++) {
    setonoff(something[u], v);
    digitalWrite(2 + u, LOW);
    delay(1);
    digitalWrite(2 + u, HIGH);
  }
}

void setup()  {
  Serial.begin(9600);
  Serial.println("Enabling IRin");

  irrecv.enableIRIn();
  Serial.println("Enabled IRin");


  for (int pin = 2; pin < 18; pin++) {
    pinMode(pin, OUTPUT);
  }

  for (int pin = 10; pin < 18; pin++) {
    digitalWrite(pin, HIGH);
    delay(100);
  }

  for (int pin = 2; pin < 10; pin++) {
    digitalWrite(pin, HIGH);
    delay(100);
  }
}

int num_index = 0;

void loop() {
  if (irrecv.decode(&results)) {
    input_remo();
    int i = 0;
    while (i < 100) {
      display_pattern(num_list[num_index], 0);
      i++;
    }
    irrecv.resume();
  }
  delay(100);
}

void input_remo () {
  if (results.value == 0xFF6897) {
    num_index = 0;
  } else if (results.value == 0xFF30CF) {
    num_index = 1;
  } else if (results.value == 0xFF18E7) {
    num_index = 2;
  } else if (results.value == 0xFF7A85) {
    num_index = 3;
  } else if (results.value == 0xFF10EF) {
    num_index = 4;
  } else if (results.value == 0xFF38C7) {
    num_index = 5;
  } else if (results.value == 0xFF5AA5) {
    num_index = 6;
  } else if (results.value == 0xFF42BD) {
    num_index = 7;
  } else if (results.value == 0xFF4AB5) {
    num_index = 8;
  } else if (results.value == 0xFF52AD) {
    num_index = 9;
  }
}
