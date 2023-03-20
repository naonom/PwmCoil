
//pin
const int inA1 = 5;
const int inA2 = 11;
const int enA = 3;
const int inB1 = 6;
const int inB2 = 10;
const int enB = 9;

boolean MotorFlag;
double timeON = 100;
double timeOFF = 50;

boolean CountFlag;
int countA = 0;
int countB = 250;

void setup() {
  pinMode(13, OUTPUT);//LED

  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(enB, OUTPUT);

  MotorFlag = false;
  CountFlag = false;
  
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  if(Serial.available()){
    switch(Serial.read()){
      case 's':
        Serial.println("start");
        MotorFlag=true;
        CountFlag=1;
        break;
      case 'e':
        Serial.println("end");
        MotorFlag=false;
        StopMotorA();
        StopMotorB();
        break;
      default: break;
    }
  }

  if(MotorFlag == 1){
    start(timeON, timeOFF);
  }
}

void start(double timeON, double timeOFF){
  if(countA>=255){
    CountFlag = true;
    countA = 250;
    ActMotorB(countB);
  }
  if(countA<=0){
    CountFlag = false;
    StopMotorB();
    delay(1000);
  }
  ActMotorA(countA);
  ActMotorB(countB);
  //StopMotorA();
  //delay(timeOFF);

  if(CountFlag == true){
    countA -= 10;
  }else{
    countA += 10;
  }
  delay(timeON);
}

void ActMotorA(double volt){
  //digitalWrite(13, true);
  Serial.println("ACT");
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  analogWrite(enA, volt);
}

void ActMotorB(double volt){
  //digitalWrite(13, true);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
  analogWrite(enB, volt);
}

 //モーターを停止させる処理
void StopMotorA(){
   //digitalWrite(13, false);
   Serial.println("STOP");
   digitalWrite(inA1, LOW);
   digitalWrite(inA2, LOW);
   analogWrite(enA, 0);
}
void StopMotorB(){
   //digitalWrite(13, false);
   digitalWrite(inB1, LOW);
   digitalWrite(inB2, LOW);
   analogWrite(enB, 0);
}
