const int inA1 = 12;
const int inA2 = 14;
const int enA = 13;
const int inB1 = 27;
const int inB2 = 15;
const int enB = 25;

boolean MotorFlag;
double timeON = 500;
double timeOFF = 500;

void ActMotor(){
  Serial.println("ACT");
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  analogWrite(enA, 252);

  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
  analogWrite(enB, 252);
}


void StopMotor(){
  Serial.println("STOP");
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);
  analogWrite(enA, 0);

  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
  analogWrite(enB, 0);
}

void start(double timeON, double timeOFF){
  ActMotor();
  delay(timeON);
  StopMotor();
  delay(timeOFF);
}


void setup() {
  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);
  pinMode(enA, OUTPUT);
  
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(enB, OUTPUT);

  MotorFlag = false;
  
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    switch(Serial.read()){
      case 's':
        Serial.println("start");
        MotorFlag = true;
        break;
      case 'e':
        Serial.println("end");
        MotorFlag = false;
        break;
      default: break;
    }
  }
  
  if(MotorFlag == 1){
    start(timeON, timeOFF);
  }
}
