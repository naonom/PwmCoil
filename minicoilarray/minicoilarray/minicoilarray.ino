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
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(enB, OUTPUT);

  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

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
    delay(500);
    StopMotor();
    delay(500);
    ActMotorB(255);
    delay(500);
    StopMotor();
    delay(500);
  }  

}

//ActA
void ActMotorA(int power){
  Serial.println("Act A");
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
}

//ActB
void ActMotorB(int power){
  Serial.println("Act B");
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
}

//StopAB
void StopMotor(){
  Serial.println("Stop AB");
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
}
