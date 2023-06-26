#include <Wire.h>

void setup() {
  pinMode(0, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
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
  if(x == 0){
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }else if(x == 1){
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }else if(x == 10){
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  }else if(x == 11){
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  }else if(x == 100){
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  }else if(x == 101){
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  }else if(x == 110){
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
  }else if(x == 111){
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
  }
}
