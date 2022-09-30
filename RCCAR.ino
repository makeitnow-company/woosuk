#define BLYNK_TEMPLATE_ID "TMPLK3a4YJ3l"
#define BLYNK_DEVICE_NAME "RCCAR"
#define BLYNK_AUTH_TOKEN "cPmbLKmpc-Pq6SPx7AbFlbBbTuAnullV"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iotedu";
char pass[] = "012345678";


#define MotorA_Rotate D1
#define MotorA_Dir D3
#define MotorB_Rotate D2
#define MotorB_Dir D4

int left_value = 0;
int right_value = 0;
int forwads_value = 0;
int backwards_value = 0;

BLYNK_WRITE(V0){
  left_value = param.asInt();
}

BLYNK_WRITE(V1){
  right_value = param.asInt();
}
BLYNK_WRITE(V2){
  forwads_value = param.asInt();
}
BLYNK_WRITE(V3){
  backwards_value = param.asInt();
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(MotorA_Rotate,OUTPUT);
  pinMode(MotorA_Dir, OUTPUT);
  pinMode(MotorB_Rotate, OUTPUT);
  pinMode(MotorB_Dir, OUTPUT);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  if(left_value){
    moveLeft();
  }else if(right_value){
    moveRight();
  }else if(forwads_value){
    moveForward();
  }else if(backwards_value){
    moveBackwards();
  }else{
    movestop();
  }
}

void moveLeft(){
  Serial.println("LEFT");
  digitalWrite(MotorA_Rotate, HIGH);
  digitalWrite(MotorB_Rotate, LOW);
  delay(10);
}

void moveRight(){
  Serial.println("RIGHT");
  digitalWrite(MotorA_Rotate, LOW);
  digitalWrite(MotorB_Rotate, HIGH);
  delay(10);
}

void moveForward(){
  Serial.println("FORWARD");
  digitalWrite(MotorA_Rotate, HIGH);
  digitalWrite(MotorB_Rotate, HIGH);
  delay(10);
}

void moveBackwards(){
  Serial.println("BACKWARDS");
  digitalWrite(MotorA_Rotate, HIGH);
  digitalWrite(MotorB_Rotate, HIGH);
  digitalWrite(MotorA_Dir, LOW);
  digitalWrite(MotorB_Dir, LOW);
  delay(10);
}

void movestop(){
  Serial.println("STOP");
  digitalWrite(MotorA_Rotate, LOW);
  digitalWrite(MotorB_Rotate, LOW);
}
