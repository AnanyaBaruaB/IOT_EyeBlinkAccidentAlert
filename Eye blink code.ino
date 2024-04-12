

#define BLYNK_TEMPLATE_ID           "TMPLB3ToyRYB"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "HnCSGuFUip9Xk-XqIcffvn8QtfSEDvsr"//ankon.bubt@gmail.com, ankon007


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "abc";
char pass[] = "123456yx";

const int eye = D5;
const int eng = D6;
const int led = D7;
const int buz = D0;
int PWM=D8;
int pval=0;

int eyenotice;

int val=0;
int eyeval=0;

void setup()
{
Serial.begin(115200);  
Blynk.begin(auth, ssid, pass);
pinMode(eye,INPUT);
pinMode(eng,OUTPUT);
pinMode(led,OUTPUT);
pinMode(buz,OUTPUT);
pinMode(PWM,OUTPUT);
}


void loop()
{
  Blynk.run();
  eyeval=digitalRead(eye);
  Serial.print("EYE: ");
  Serial.println(eyeval);

  
  if(eyeval==0)
  { 
    eyenotice=1;
    delay(50);
    eyeval=digitalRead(eye);
    if(eyeval==0)
   {
      if(val<=30)
      {
      pval=map(val,0,30,255,0);
      digitalWrite(led,HIGH);
      digitalWrite(buz,HIGH);
      analogWrite(PWM,pval);
      }
      else
      {
      digitalWrite(eng,LOW);
      digitalWrite(led,LOW);
      digitalWrite(buz,LOW);
      analogWrite(PWM,0);
      }
   }
    Serial.print("Val: ");
  Serial.println(val);
    val++;
  }
  
  else
  {
          analogWrite(PWM,0);
        eyenotice=0;
    digitalWrite(eng,HIGH);
    digitalWrite(led,LOW);
    digitalWrite(buz,LOW);
    val=0;
  }

         Blynk.virtualWrite(V0, eyeval);
     
         Blynk.virtualWrite(V1, eyenotice);
delay(1);
}  
