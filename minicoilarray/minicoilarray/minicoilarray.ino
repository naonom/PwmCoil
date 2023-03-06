//coil pin
const int inA1 = 5; //5
const int inA2 = 11; //11
const int enA = 3; //3
const int inB1 = 6; //6
const int inB2 = 10; //10
const int enB = 9; //9

//coil var
int MotorFlag;

void setup() {
  // put your setup code here, to run once:
  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(inA1, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin(9600);

  MotorFlag = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    switch(Serial.read()){
      case '1':
        Serial.println("patern 1");
        MotorFlag = 1;
        break;
      case '0':
        Serial.println("end");
        MotorFlag = 0;
        StopMotor();
        break;
    }
  }

  if(MotorFlag == 1){
    ActMotorA(255);
    delay(1000);
    StopMotor();
    delay(1000);
    ActMotorB(255);
    delay(1000);
    StopMotor();
    delay(1000);
  }  

}

//ActA
void ActMotorA(int power){
  Serial.println("Act A");
  digitalWrite(enA, HIGH);
  analogWrite(inA1, power);
  digitalWrite(inA2, LOW);
}

//ActB
void ActMotorB(int power){
  Serial.println("Act B");
  digitalWrite(enB, HIGH);
  analogWrite(inB1, power);
  digitalWrite(inB2, LOW);
}

//StopAB
void StopMotor(){
  Serial.println("Stop AB");
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  analogWrite(inA1, 0);
  analogWrite(inB2, 0);
}
