#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define FIREBASE_HOST "testonoff-1d738.firebaseio.com"
#define FIREBASE_AUTH "X8RRFRqjv7AIU3gWMppP7YrKoyQkclOS1MaVhjKp"


#define WIFI_SSID "iPad"
#define WIFI_PASSWORD "mimimiml"


int up = D1;
int down = D2;

void setup() {
  pinMode(up ,OUTPUT);
  pinMode(down ,OUTPUT);

Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  Serial.println("connecting....");
  while (WiFi.status() != WL_CONNECTED) {
     Serial.println(".");
    delay(500);
  }
   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("up",0);
   Firebase.set("down",0);
    Firebase.set("lift",0);
     Firebase.set("rigth",0);
      
}

void loop() {
  Firebase.set("connect",1);
    int upFirebase = Firebase.getInt("up");
    int downFirebase =Firebase.getInt("down");

    if(upFirebase == 1 && downFirebase == 0){
     digitalWrite(up,HIGH);
     digitalWrite(down,LOW);
    }else if(upFirebase == 0 && downFirebase == 1){
      digitalWrite(up,LOW);
     digitalWrite(down,HIGH);
    }

}
