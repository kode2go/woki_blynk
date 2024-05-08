///Template ID,Device Name,Auth Token จาก device info ใน blynk clound
#define BLYNK_TEMPLATE_ID "TMPL20o-ReO3r"
#define BLYNK_TEMPLATE_NAME "switch"
#define BLYNK_AUTH_TOKEN "2wzUwRv1MrP_-OarfCkzZ6R39EC76pa1"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

///wifi id & pwd
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

int value;
int value1;

const int ledPin = 2;  // Built-in LED pin on most ESP32 boards


BLYNK_WRITE(V0) ///function blynk ลักษณะ input ส่งคำสั่งจาก blynk ลงมา
{
  value = param.asInt();
  //Blynk.virtualWrite(V1, value); 
}


BLYNK_WRITE(V1)
{
  value1 = param.asInt(); 
  //Blynk.virtualWrite(V1, value); 
}

BLYNK_WRITE(V3)
{
  // Set incoming value from pin V6 to a variable
  int switchValue = param.asInt();

  // Check the state of the switch
  if (switchValue == 1)
  {
    Serial.println("Switch is ON");
    //digitalWrite(ledPin, HIGH);
    Blynk.virtualWrite(V2, "Switch is ON");
    digitalWrite(13, HIGH);
    digitalWrite(2,1);

  }
  else
  {
    Serial.println("Switch is OFF");
    //digitalWrite(ledPin, LOW);  // Turn off LED
    digitalWrite(13, LOW);
    Blynk.virtualWrite(V2, "Switch is OFF");
    digitalWrite(2,0);
  }
}

BLYNK_CONNECTED()
{
  Blynk.syncAll();
}

void setup(){
  Serial.begin(115200);
  pinMode(2, OUTPUT); //pin led 
  pinMode(4, OUTPUT); //pin led 


  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
 
} /// end setup


void loop(){
  Blynk.run();
  timer.run();
  // digitalWrite(4, value1);

  // int sw = digitalRead(13);
  // // delay(1000);
  // if(sw==0){
  //   digitalWrite(2,1);
  //   Blynk.virtualWrite(V2, 1); //function blynk ลักษณะ output ส่งขึ้นไปที่ blynk
  //   delay(200);
  // }else{
  //   digitalWrite(2,0);
  //   Blynk.virtualWrite(V2, 0);
  //   }




} /// end loop





