#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPLdK3VppgO"
#define BLYNK_DEVICE_NAME "agric"
#define BLYNK_AUTH_TOKEN "rXcW4zJEYv316qryHP7BZPRJiB1_CijO"


char auth[] = "rXcW4zJEYv316qryHP7BZPRJiB1_CijO";
char ssid[] = "love u";
char pass[] = "iloveyou";

BlynkTimer timer,pa;
int val;
bool Relay = 0;
bool sug ;
bool cane ;
bool crack;
bool m=0;
#define sensor A0
#define waterPump D3
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(waterPump, OUTPUT);
  
}

BLYNK_WRITE(V1) { //paddy
    Relay = param.asInt();
}
BLYNK_WRITE(V2) { // on and off
    sug = param.asInt();
    if (sug == 1) {
      digitalWrite(waterPump, LOW);

    } else {
      digitalWrite(waterPump, HIGH);
    }
}
BLYNK_WRITE(V7) {  // sugar cane
    cane = param.asInt();   
}
void canee(){
  if(val<500){
        digitalWrite(waterPump, LOW);
        }
}
\



BLYNK_WRITE(V8) { // Fire crack
    crack = param.asInt();   
}
void crackk(){
  if(val<300){
        digitalWrite(waterPump, LOW);
        }
}


void loop() {
  int value = analogRead(sensor);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;
  int val = value * 10;
  int a=1,b=1;

  Blynk.run();
  Blynk.virtualWrite(V0, val);
   if(cane==1){
    {
      canee();
      if(cane==1){
        if(val>=500){
          digitalWrite(waterPump, HIGH);
        }
        // else{
        //   digitalWrite(waterPump, LOW);
        // }
      }
    }
     
  }

   if(crack==1){
    {
      crackk();
      if(crack==1){
        if(val>=300){
          digitalWrite(waterPump, HIGH);
        }
        // else{
        //   digitalWrite(waterPump, LOW);
        // }
      }
    }
     
  }
  
  
  if(Relay==1){ // paddy
    if(val<900 && Relay==1){
    digitalWrite(waterPump, LOW); 
     }
     }
     delay(2000);
  if(val<=900 && Relay==1){
       digitalWrite(waterPump, HIGH);
      
     }
     
  
  

 
}