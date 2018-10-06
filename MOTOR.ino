#include <ESP8266WiFi.h>
#include <PubSubClient.h>




#define wifi_ssid "IOT02"
#define wifi_password "coeesiot02"

//#define mqtt_server "m13.cloudmqtt.com"
#define mqtt_server "175.101.12.206"
//#define mqtt_port 11973
#define mqtt_port 1883
//#define mqtt_user "qspuplfk"
#define mqtt_user "mamatha"
//#define mqtt_password "k7PCbGMopLrk"
#define mqtt_password "Mamta@123"

#define mytopic "ct"




#define in_led D1 //changed from D4 to D1 Realay shield pin

WiFiClient espClient;
PubSubClient client;
void setup() {
  Serial.begin(115200);
  
  setup_wifi();
  client.setClient(espClient);
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(in_led, OUTPUT);
  //digitalWrite(in_led, HIGH);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    // If you do not want to use a username and password, change next line to
    // if (client.connect("ESP8266Client")) {
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
 Serial.print("Message arrived [");
 Serial.print(topic);
 Serial.print("] ");

 int mydata = (*payload-48)*10; 
 payload++;
 mydata=mydata+(*payload-48);
 
 
 //Serial.println(mydata);
 /*
 for (int i = 0; i < length; i++) {
  //char receivedChar = (char)payload[i];
  //Serial.print(receivedChar);
  Serial.print(*payload);
  if(*payload < 30)
  //if (receivedChar == '0')
   digitalWrite(in_led, LOW);
 // if (receivedChar == '1')
   else
   digitalWrite(in_led, HIGH);
 }
 Serial.println();*/
 if(mydata > 35)
 {

 
 digitalWrite(in_led, HIGH);
 Serial.print(mydata);
  Serial.println("relayon");
 }
 else
 digitalWrite(in_led, LOW);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
 
  client.subscribe(mytopic);
  delay(1000);
}
