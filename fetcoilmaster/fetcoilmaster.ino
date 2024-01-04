#include <Wire.h>

int MotorFlag;

void setup() {
  Wire.begin();
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

void slaveWrite(int pin){
  // Serial.println(pin/1000);
  // Serial.println(pin - ((pin/1000)*1000));
  Wire.beginTransmission(8);
  Wire.write(pin);
  Wire.endTransmission();
}

byte x = 1;

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
        Wire.beginTransmission(8);
        Wire.write(0);   
        Wire.endTransmission();
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        break;
    }
  }
  if(MotorFlag == 1){
    Wire.beginTransmission(8);
    Wire.write(0);   
    Wire.endTransmission();
    digitalWrite(9, HIGH);
    Serial.println("9HIGH");
    delay(700);

    digitalWrite(9, LOW);
    Serial.println("LOW");
    digitalWrite(10, HIGH);
    Serial.println("10HIGH");
    delay(700);

    digitalWrite(10, LOW);
    Serial.println("LOW");
    digitalWrite(11, HIGH);
    Serial.println("11HIGH");
    delay(700);

    digitalWrite(11, LOW);
    Serial.println("LOW");
    digitalWrite(3, HIGH);
    Serial.println("3HIGH");
    delay(700);

    digitalWrite(3, LOW);
    Serial.println("LOW");
    digitalWrite(5, HIGH);
    Serial.println("5HIGH");
    delay(700);

    digitalWrite(5, LOW);
    Serial.println("LOW");
    digitalWrite(6, HIGH);
    Serial.println("6HIGH");
    delay(700);

    digitalWrite(6, LOW);
    Serial.println("LOW");
    Wire.beginTransmission(8); 
    Wire.write(1);   
    Wire.endTransmission(); 
    delay(700);

    Wire.beginTransmission(8);
    Wire.write(10);   
    Wire.endTransmission(); 
    delay(700);

    Wire.beginTransmission(8);
    Wire.write(100);   
    Wire.endTransmission(); 
    delay(700);



  // delay(700);
  }
  if(MotorFlag == 2){
    Wire.beginTransmission(8);
    Wire.write(111);   
    Wire.endTransmission();
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);

    delay(2000);

    Wire.beginTransmission(8);
    Wire.write(0);   
    Wire.endTransmission();
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);

    delay(8000);

  }
  if(MotorFlag == 3){
    Wire.beginTransmission(8);
    Wire.write(10);   
    Wire.endTransmission();
    digitalWrite(11, HIGH);
    //digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    //digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    //digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);

    delay(3000);

    Wire.beginTransmission(8);
    Wire.write(0);   
    Wire.endTransmission();
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);

    delay(7000);

  }

  if(MotorFlag == 4){
    digitalWrite(9, HIGH);
    delay(700);
    digitalWrite(6, HIGH);
    slaveWrite(10);
    delay(700);
    digitalWrite(9, LOW);
    slaveWrite(11);
    delay(700);
    
    digitalWrite(5, HIGH);
    slaveWrite(1);
    delay(700);
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
    slaveWrite(0);
    delay(700);
    digitalWrite(7, HIGH);
    delay(700);
    digitalWrite(3,HIGH);
    digitalWrite(5, LOW);
    delay(700);
    digitalWrite(9, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, HIGH);
    delay(700);
    digitalWrite(11, LOW);
    digitalWrite(3, LOW);
    slaveWrite(101);
    delay(700);
    digitalWrite(7, HIGH);
    delay(700);
    slaveWrite(0);
    digitalWrite(7, LOW);
    delay(700);

  }
  if(MotorFlag == 5){
    Wire.beginTransmission(8);
    Wire.write(111);   
    Wire.endTransmission();
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);

    delay(2000);
  }

}


