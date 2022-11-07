
const int inA1 = 12;
const int inA2 = 14;
const int enA = 13;
//const int enA = A14;
const int inB1 = 27;
const int inB2 = 15;
const int enB = 25;
//const int enB = A18;

boolean MotorFlag;
double timeON = 500;
double timeOFF = 500;

void setup() {
  //pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);
  pinMode(enA, OUTPUT);
  
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(enB, OUTPUT);

  MotorFlag = 0;

  ledcSetup(0, 7812.5, 8);
  ledcAttachPin(inA1, 0);
  
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
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
      case '0':
        Serial.println("end");
        MotorFlag = 0;
        break;
      default: break;
    }
  }
  
  if(MotorFlag == 1){
    OnOffA();
  }
  if(MotorFlag == 2){
    tantanA();
  }
}
