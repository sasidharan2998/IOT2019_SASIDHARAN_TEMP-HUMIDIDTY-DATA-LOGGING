#include <ESP8266WiFi.h>
#include <SD.h>
#include "RTClib.h"
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

RTC_DS3231 rtc;


#include <DHT.h>
 #define FIREBASE_HOST "iotproject-dcbc4.firebaseio.com"
#define FIREBASE_AUTH "735eMELLw1lId782Pfo2Fw7LGAGJxF200rX9ULJA"
#define WIFI_SSID "sasi"
#define WIFI_PASSWORD "012345678"

#define DHTPIN D3     

#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

#define CS_PIN  D4

void setup()
{
  Serial.begin(9600);
  Serial.print("Connecting with SD Card");
 
  dht.begin();
  //pinMode(D4, OUTPUT);
 
  if (!SD.begin(CS_PIN)) {
    Serial.println("Failed to connect to SD Card");

    return;
  }
   
  Serial.println("SD Card Connected");
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 
}
void loop()
{
  DateTime now = rtc.now();
    String datee=(String)now.day()+"-"+(String)now.month()+"-"+(String)now.year();
     String timee=(String)now.hour()+":"+(String)now.minute()+":"+(String)now.second();
      String timestamp=datee+" "+timee;
float Humidity = dht.readHumidity();
  Serial.print("Humidity: ");
  Serial.println(Humidity);
  float Temperature = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.println(Temperature);
 
  File dataFile = SD.open("LOG.txt", FILE_WRITE);
 
  if (dataFile) {
    Serial.println("File was opened sucessfully");
    dataFile.print("Time : ");
     dataFile.print(timestamp);
    dataFile.print("|  Humidity : ");
      dataFile.print(Humidity);
      dataFile.print("|  Temperature : ");
      dataFile.println(Temperature);
 
      dataFile.close();
       Serial.println("File was updated sucessfully");
    }
     else {
    Serial.println(" Failed to open file LOG.txt");
  }
 
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject & root=jsonBuffer.createObject();
    root["Time"]=timee;
    root["Humidity"]=Humidity;
root["Temperature"]=Temperature;
    Firebase.push(datee,root);
  
 
  delay(2000);
 
}
