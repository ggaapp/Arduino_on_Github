float modifConstance = 9.775171; // 100kohm / 1023 grades = 9.775171

void setup() {        // Bit reate (per sec) = digits per second.(BPS)
  Serial.begin(9600);  // Baud rate (per sec) = Symbol per second.(BR)
}

void loof() {
  int risistValue = ananlog(A0);
  int ohm = risistValue * modifConstance;

  Serial.print("Var.Resistance = ");
  Serial.print(ohm);
  delay(1000);

}
