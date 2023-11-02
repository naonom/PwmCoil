int MotorFlag;
int count1 = 0;
int count2 = 0;
boolean CountFlag = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  //pinMode(3, OUTPUT);
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
        MotorFlag = 3;
        break;
      case '4':
        Serial.println("patern 4");
        MotorFlag = 4;
        break;

      case '5':
        Serial.println("patern 5");
        MotorFlag = 5;
        break;
      
      case '0':
        Serial.println("end");
        MotorFlag = 0;
        analogWrite(11, LOW);
        delay(100);
        break;
    }
  }
  if(MotorFlag == 1){
    if(count1 >= 255){
      CountFlag = true;
      count1 = 255;
    }
    if(count1 <= 0){
      CountFlag = false;
      count1 = 0;
    }

    analogWrite(9, count1);
    delay(50);
    analogWrite(9, 255-count1);
    delay(50);

    if(CountFlag == true){
      count1 -= 4;
    }else{
      count1 += 4;
    }
  }
  if(MotorFlag == 2){
    if(count2 >= 255){
      CountFlag = true;
      count2 = 255;
    }
    if(count2 <= 0){
      CountFlag = false;
      count2 = 0;
    }
    analogWrite(9, count2);
    if(CountFlag == true){
      count2 -= 3;
    }else{
      count2 += 3;
    }
    delay(30);
  }
  if(MotorFlag == 3){
    digitalWrite(9, HIGH);
    Serial.println("HIGH");
    delay(700);
    digitalWrite(9, LOW);
    Serial.println("LOW");
    delay(700);
  }
  if(MotorFlag == 4){
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    Serial.println("HIGH");
    delay(2000);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    Serial.println("LOW");
    delay(2000);
  }

  if(MotorFlag == 5){
    analogWrite(9, 125);
    delay(2000);
    analogWrite(9, LOW);
    analogWrite(11, 125);
    delay(2000);
    analogWrite(11, LOW);
    analogWrite(10, 125);
    delay(2000);
    analogWrite(10, LOW);
    analogWrite(6, 125);
    delay(2000);
    analogWrite(6, LOW);
    analogWrite(5, 125);
    delay(2000);
    analogWrite(5, LOW);
    delay(2000);
  }

  

}
