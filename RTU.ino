#include <dht.h>
#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
dht DHT;
 
void setup(){
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  Serial.begin(9600);
  sensors.begin(); 
  delay(500);//Delay to let system boot
  
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
   sensors.requestTemperatures(); 
    DHT.read11(A1);
    
    Serial.print(sensors.getTempCByIndex(0));
    Serial.print(DHT.humidity);
    Serial.print("% ");
    Serial.print(":");
    Serial.print(DHT.temperature); 
    Serial.println("C ");
    
    delay(2000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop() 
