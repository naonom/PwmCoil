
//pin
const int inA1 = 12;
const int inA2 = 7;
const int enA = 11;
const int inB1 = 3;
const int inB2 = 8;
const int enB = 9;

boolean MotorFlag;
double timeON = 500;
double timeOFF = 500;

void setup() {
  pinMode(13, OUTPUT);//LED

  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(enB, OUTPUT);

  MotorFlag = false;

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    switch(Serial.read()){
      case 's':
        Serial.println("start");
        MotorFlag=true;
        break;
      case 'e':
        Serial.println("end");
        MotorFlag=false;
        break;
      default: break;
    }
  }

  if(MotorFlag == 1){
    start(timeON, timeOFF);
  }
}

void start(double timeON, double timeOFF){
  ActMotorA(252);
  delay(timeON);
  StopMotorA();
  delay(timeOFF);
}

void ActMotorA(double volt){
  digitalWrite(13, true);
  Serial.println("ACT");
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  analogWrite(enA, volt);
   
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
  analogWrite(enB, volt);
}

 //モーターを停止させる処理
 void StopMotorA(){
   digitalWrite(13, false);
   Serial.println("STOP");
   digitalWrite(inA1, LOW);
   digitalWrite(inA2, LOW);
   analogWrite(enA, 0);
   
   digitalWrite(inB1, LOW);
   digitalWrite(inB2, LOW);
   analogWrite(enB, 0);
 }
