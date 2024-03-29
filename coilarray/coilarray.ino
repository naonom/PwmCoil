int outputs[4] = {4,3,2}; // pins for selecting LED A B C
//int io_pin = 9; // pin used for sending power to LEDs
int inhibit_pin = 8; // pin for turning off all LEDs

const int pin = 9;
int MotorFlag;

void setup() {
  for(int ii;ii<3;ii++){
    pinMode(outputs[ii],OUTPUT); // output selection for LED control
  }
  pinMode(inhibit_pin,OUTPUT); 
  digitalWrite(inhibit_pin,LOW); // raise high to disable all
  //pinMode(io_pin,OUTPUT); // this controls the power sent to each LED
  //digitalWrite(io_pin,HIGH); // send high to all LEDs when powered on
  pinMode(pin, OUTPUT);
  Serial.begin(9600);

  MotorFlag = 0;
}

void loop(){
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
    Serial.println("act 0");
    digitalWrite(pin,HIGH);
    digitalWrite(inhibit_pin,LOW); // raise high to disable all
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delayMicroseconds(10);
    delay(1000);
    Serial.println("stop");
    digitalWrite(pin,HIGH);
    digitalWrite(inhibit_pin,HIGH); // raise high to disable all
    delayMicroseconds(10);
    delay(1000);
    // Serial.println("act1");
    // digitalWrite(pin,HIGH);
    // digitalWrite(inhibit_pin,LOW); // raise high to disable all
    // digitalWrite(4, LOW);
    // digitalWrite(3, HIGH);
    // digitalWrite(2, LOW);
    // delay(1000);
    // Serial.println("stop");
    // digitalWrite(pin,LOW);
    // delay(1000);
  }
}

