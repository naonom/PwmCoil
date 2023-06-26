int MotorFlag;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  //LED
  pinMode(7, OUTPUT);
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
        MotorFlag = 2;
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
    digitalWrite(9, HIGH);
    Serial.println("11HIGH");
    delay(700);
    digitalWrite(9, LOW);
    Serial.println("LOW");
    delay(700);
    digitalWrite(11, HIGH);
    Serial.println("9HIGH");
    delay(700);
    digitalWrite(11, LOW);
    Serial.println("LOW");
    delay(700);
    digitalWrite(3, HIGH);
    Serial.println("3HIGH");
    delay(700);
    digitalWrite(3, LOW);
    Serial.println("LOW");
    delay(700);
    digitalWrite(5, HIGH);
    Serial.println("5HIGH");
    delay(700);
    digitalWrite(5, LOW);
    Serial.println("LOW");
    delay(700);
    digitalWrite(6, HIGH);
    Serial.println("6HIGH");
    delay(700);
    digitalWrite(6, LOW);
    Serial.println("LOW");
    delay(700);
  }
  if(MotorFlag == 2){
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    Serial.println("HIGH");
    delay(700);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    Serial.println("LOW");
    delay(700);
  }
  if(MotorFlag == 3){
    digitalWrite(11, HIGH);
    Serial.println("HIGH");
    delay(700);
    digitalWrite(11, LOW);
    Serial.println("LOW");
    delay(700);
  }

  

}
