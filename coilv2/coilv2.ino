//move 5 big coils
int MotorFlag;

void setup() {
  Serial.begin(9600);
  Serial.println("start");

  //motor pin
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

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
        analogWrite(11, LOW);
        analogWrite(10, LOW);
        analogWrite(9, LOW);
        analogWrite(6, LOW);
        analogWrite(5, LOW);
        break;
    }
  }

  if(MotorFlag == 1){
    smallToBigLinear(2);
    act();
  }



  delay(20);
}
