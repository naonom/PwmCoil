int MotorFlag;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  MotorFlag = 0;

}

void loop() {
  if(Serial.available()){
    switch(Serial.read()){
      case '1':
        Serial.println("patern 1");
        MotorFlag = 1;
        break;
      case '0':
        Serial.println("end");
        MotorFlag = 0;
        break;
    }
  }
  if(MotorFlag == 1){
    digitalWrite(10, HIGH);
    Serial.println("10HIGH");
    delay(700);
    digitalWrite(10, LOW);
    Serial.println("LOW");
    delay(700);
    digitalWrite(11, HIGH);
    Serial.println("10HIGH");
    delay(700);
    digitalWrite(11, LOW);
    Serial.println("LOW");
    delay(700);
    digitalWrite(9, HIGH);
    Serial.println("10HIGH");
    delay(700);
    digitalWrite(9, LOW);
    Serial.println("LOW");
    delay(700);
  }

}
