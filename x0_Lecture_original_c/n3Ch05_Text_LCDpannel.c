// to Learn : Text LCD pannel TEST
// refer to https://www.youtu.be/
#include <LiquidCrystal.h>        // declair LCD header file
/* Pannel PIN ARRAY
1.    Vss     GND
2.    Vdd     Suppy 5V
3.    v0      Contrast control
4.    RS      Register Selection signal
5.    R/W     R/W signal ( High=read / Low = write)
6.    Enable  R/W capability
7~10  D0~D3   Data transfer
11~14 D4~D7   Data transfer
15    LED+    Back light power supply = 5V
16    LED-    Back light GND
*/
LiquidCrystal lcd(12,11,5,4,3,2);     // initialize LCD pin SETUP list
/* initialize LCD Pin SETUP list
** 6 Pins Array ( 12= RS, 11= Enable, 5~2= D7~D4 )
*/
unsigned int time;                    // var. for timeset
int data = 12;

void setup() {
  lcd.begin(16,2);                    // Column & Line(row) = (16 x 2)
}

void loop() {
  if (time == 60) time = 0;
  time = mills() / 1000;              // store sec value at Time.
  /* time function mills() return timelaps. if it spend 1,000 mills
      store 1 sec at time()
  */
  lcd.setCursor(0,0);                 // Position of Cursor, start from (0,0)
  lcd.print ("Hello, ArDuino World!");

  lcd.setCursor(0,1);                 // position of Cursor, second line(y)
  lcd.print ("Time Sec:"); lcd.print(time);
}
