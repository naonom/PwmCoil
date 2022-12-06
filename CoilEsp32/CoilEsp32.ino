//coil pin
const int inA1 = 12;
const int inA2 = 14;
const int enA = 13;
const int inB1 = 27;
const int inB2 = 15;
const int enB = 25;

//resist pin
const int re1 = 35;
const int re2 = 34;

//resist value
volatile int val1 = 0;
volatile int val2 = 0;

//coil var
int MotorFlag;

//subProsess
void readResist(void * pvParameters){
  while(1){
    val1 = analogRead(re1);
    val2 = analogRead(re2);
    String ans = String(val1)+" "+String(val2);
    Serial.println(ans);
    delay(500);
  }
}

void setup() {
  pinMode(inA2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(enB, OUTPUT);
  
  ledcSetup(0, 7812.5, 8);
  ledcAttachPin(inA1, 0);

  ledcSetup(1, 7812.5, 8);
  ledcAttachPin(inB1, 1);

  pinMode(re1, ANALOG);
  pinMode(re2, ANALOG);
  Serial.begin(115200);
  
  xTaskCreatePinnedToCore(readResist, "readResist", 4096, NULL, 1, NULL, 0);

  MotorFlag = 0;
  
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
      case '4':
        Serial.println("patern 4");
        MotorFlag = 4;
        break;
      case '0':
        Serial.println("end");
        MotorFlag = 0;
        StopMotor();
        break;
    }
  }
  if(MotorFlag == 1){
    OnOff();
  }
  if(MotorFlag == 2){
    pwm();
  }
  if(MotorFlag == 3){
    smallToBig();
  }
  if(MotorFlag == 4){
    drop();
  }
}
