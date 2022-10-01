#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPLdK3VppgO"
#define BLYNK_DEVICE_NAME "agric"
#define BLYNK_AUTH_TOKEN "rXcW4zJEYv316qryHP7BZPRJiB1_CijO"


char auth[] = "rXcW4zJEYv316qryHP7BZPRJiB1_CijO";
char ssid[] = "love u";
char pass[] = "iloveyou";

BlynkTimer timer;

float hum = 1;
#define Temp A0

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(500L, temp);
  
}




void temp() {
  int analogValue = analogRead(Temp);
float millivolts = (analogValue/1024.0) * 3300;
float celsi = millivolts/10;
float celsius = celsi - 8;


Serial.println(celsius);

Blynk.virtualWrite(V5,celsius);


float humidity = (50 - celsius)+10;

Blynk.virtualWrite(V6,humidity);
  
delay(1000);
  

}

void loop() {
  Blynk.run();
  timer.run();
}