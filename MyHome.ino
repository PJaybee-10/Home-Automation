#include <ESP8266WiFi.h>
#include "FirebaseArduino.h"

#define FIREBASE_HOST "mmcoe-d41a7.firebaseio.com"  //should not have http:// and the end /
#define FIREBASE_AUTH "CdHp0m8XPCmPSfo6qNEceVYRFGWfYeh3jCXXuLNB"  // go to settings in firebase,select project settings and service account, secrets auth key
#define WIFI_SSID "Vedika"
#define WIFI_PASSWORD "vedi123456"

#define LL1 D0
#define LL2 D1
#define LFan D2
#define KL1 D3
#define KL2 D4
#define KFan D5
#define BL1 D6


void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);

  Serial.begin(115200);
  // connect to wifi.
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
void firebasereconnect(){
  Serial.println("Trying to reconnect");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }
  
int vLL1, vLL2, vKL1, vKL2,vLFan, vKFan, vBL1;
String vLFann;
void loop() {
 
  if (Firebase.failed()) {
      Serial.print("setting number failed:");
      Serial.println(Firebase.error());  
      firebasereconnect();
      return;
  }

//delay(100);
vLL1=Firebase.getInt("LL1");
vLL2=Firebase.getInt("LL2");
vLFann=Firebase.getString("LFan");
vKL1=Firebase.getInt("KL1");
vKL2=Firebase.getInt("KL2");
vKFan=Firebase.getInt("KFan");
vBL1=Firebase.getInt("BL1");
vLFan=vLFann.toInt();
//Serial.println(vLFan);
if(vLL1==1)
{
  digitalWrite(LL1,1);
}
else
{
  digitalWrite(LL1,0);
}

if(vLL2==1)
{
  digitalWrite(LL2,1);
}
else
{
  digitalWrite(LL2,0);
}
if(vKL1==1)
{
  digitalWrite(KL1,1);
}
else
{
  digitalWrite(KL1,0);
}
if(vKL2==1)
{
  digitalWrite(KL2,1);
}
else
{
  digitalWrite(KL2,0);
}
if(vBL1==1)
{
  digitalWrite(BL1,1);
}
else
{
  digitalWrite(BL1,0);
}

analogWrite(LFan,vLFan);
analogWrite(KFan,vKFan);


//String i=Firebase.getString("MyHome/Light1");
/*if(i[1]=='0')
{
  m=0;
}
else
{
  m=1;
}*/
//digitalWrite(D1,m);
//Serial.println(m);
//delay(500);
} 
