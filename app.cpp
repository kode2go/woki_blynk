#define BLYNK_PRINT Serial
//Nama : Gita Thea Samudra
//NIM  : 20200130013

//#define BLYNK_TEMPLATE_ID value
//#define BLYNK_DEVICE_NAME value
//#define BLYNK_AUTH_TOKEN value

#define BLYNK_TEMPLATE_ID "TMPL22O6KZbPX"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "xx"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth [] = BLYNK_AUTH_TOKEN;
char ssid [] = "Wokwi-GUEST";
char pass [] = "";

BlynkTimer timer;
#define LED 13
int SW_State=0;

BLYNK_WRITE (V0)
{
  SW_State = param.asInt();
  if (SW_State == 1)
  {
    digitalWrite(LED, HIGH);
    Serial.println("LED MENYALA");
    Blynk.virtualWrite(V1,HIGH);
  }
  else 
  {
    digitalWrite(LED, LOW);
    Serial.println("LED MATI");
    Blynk.virtualWrite(V1,LOW);
  }
}
void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);

}
void loop()
{
  Blynk.run();
  timer.run();
}
