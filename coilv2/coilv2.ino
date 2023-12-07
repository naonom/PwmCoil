//move 5 big coils

#include <Wire.h>
int MotorFlag = 0;

unsigned char getdata[4] = {0, 0, 0, 0};
unsigned int data[4] = {0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
  Serial.println("start");

  //motor pin
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  //manage patern
  MotorFlag = 0;

  //get sub arduino sensors {256, 256, 256, 256}
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Wire.requestFrom(8, 4);
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
      case '6':
        Serial.println("patern 6");
        MotorFlag = 6;
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
    //smallToBigLinear(2, 100);
    smallToBigLinear(2, 100);
    act();
  }

  if(MotorFlag == 2){
    smallToBigDinamic(2, 50);
    act();
  }

  if(MotorFlag ==3){
    move();
    act();
  }
  if(MotorFlag ==4){
    communicate();
    act();
  }
  if(MotorFlag ==5){
    movelinear();
    act();
  }
  if(MotorFlag ==6){
    movedinamic();
    act();
  }
  delay(20);
}

void receiveEvent(int howmeny){
  for(uint8_t i = 0; i<4; i++){
    getdata[i] = Wire.read();
    data[i] = int(getdata[i]);
    Serial.print(data[i]);
    Serial.print(", ");
  }
  //int x = Wire.read();
  Serial.println(";");

  delay(100);
}
