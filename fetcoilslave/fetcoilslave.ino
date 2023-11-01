#include <Wire.h>

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Wire.begin(8);                // join I2C bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(50);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  int x = Wire.read();    // receive byte as an integer
  //int value = Wire.read();
  //int pin = x;
  //int pin = int(x)/1000;
  //Serial.println(x);
  //int power = x - (pin*1000);
  //if(pin == 3){
  //  analogWrite(3,255);
  //}
  //analogWrite(pin, 255);
  //   pin = value / 1000;
  //   power = value - pin;
  // }else if (value > 100){
  //   pin = value / 100;
  //   power = value - pin;
  // }else{
  //   pin = value / 10;
  //   power = value - pin;
  // }
  //analogWrite(pin, HIGH);
  if(x == 0){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }else if(x == 1){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }else if(x == 10){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  }else if(x == 11){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  }else if(x == 100){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
  }else if(x == 101){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
  }else if(x == 110){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  }else if(x == 111){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  }
  
}


