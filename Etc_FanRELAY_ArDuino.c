#include <DHT.h>

#define DHTTYPE DHT11   // Type of Temp&Humid Sensors
#define DHTPIN 2        // Pin #  for Temp&Humid Sensors
int fan = 4;            // pin for FAN
int nclls = 7;          // pin for waterLEVEL gauge

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);
  Serial.println("Start Humidity!");
  dht.begin();
  pinMode (fan, OUTPUT);  // Setup pinMode(4) for FAN
  pinMode (7, INPUT);     // setup pinMode(7) for levelGAUGE

}

void loop() {
  float humi = dht.readHumidity();    //Read Humidity
  int nclls = digitalRead(7);         //Read Water level

  if (isnan(humi)){                     //Humidity Sensors

  }else{
     Serial.print("Humidity: ");
     Serial.print(humi);        //value of Humidity Sensors
     Serial.println(" %\t");
     Serial.println(nclls);     // levelGAUGE (HIGH = 0/ LOW = 1)
     if(humi>=60 ){             // if Humidity over 60%
      if(nclls==HIGH){          // if levelGAUGE = 0
        digitalWrite(fan,HIGH); // activate fan

      }
        else{
        digitalWrite(fan,LOW);    // stop fan

        }
     }
      else                      // if Humidity UNDER 60%
      {
          if(nclls==HIGH)         // if levelGAUGE = 0
          {
          digitalWrite(fan,LOW);  // stop fan
          }else{
            digitalWrite(fan,LOW); // if levelGAUGE = 1, stop fan
          }
       }
  }
}
