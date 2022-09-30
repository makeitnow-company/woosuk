#define MotorA_Rotate D1
#define MotorA_Dir D3
#define MotorB_Rotate D2
#define MotorB_Dir D4

void setup() {
  pinMode(MotorA_Rotate, OUTPUT);
  pinMode(MotorA_Dir, OUTPUT);
  pinMode(MotorB_Rotate, OUTPUT);
  pinMode(MotorB_Dir, OUTPUT);
}

void loop() {
  digitalWrite(MotorA_Dir, HIGH);
  digitalWrite(MotorA_Rotate, HIGH);
  digitalWrite(MotorB_Rotate, HIGH);
  delay(2000);
  digitalWrite(MotorA_Rotate, LOW);
  digitalWrite(MotorB_Rotate, LOW);
  delay(2000);
}
