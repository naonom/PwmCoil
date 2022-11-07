
const int inA1 = 12;
const int inA2 = 14;
const int enA = 13;
const int inB1 = 27;
const int inB2 = 15;
const int enB = 25;

int MotorFlag;
double timeON = 500;
double timeOFF = 500;

boolean CountFlag;
//int countA = 0;

void setup() {
  pinMode(inA2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(enB, OUTPUT);

  MotorFlag = 0;
  CountFlag = false;
  
  ledcSetup(0, 7812.5, 8);
  ledcAttachPin(inA1, 0);

  ledcSetup(1, 7812.5, 8);
  ledcAttachPin(inB1, 1);

  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    switch(Serial.read()){
      case '1':
        Serial.println("patern 1");
        MotorFlag = 1;
        break;
      case '2':
        Serial.println("patern 2");
        MotorFlag = 2;
        break;
      case '3':
        Serial.println("patern 3");
        MotorFlag = 3;
        break;
      case '0':
        Serial.println("end");
        MotorFlag = 0;
        StopMotorA();
        StopMotorB();
        break;
      default: break;
    }
  }
  
  if(MotorFlag == 1){
    OnOff();
  }
  if(MotorFlag == 2){
    pwm();
  }
  if(MotorFlag == 3){
    cross();
  }
  
}
