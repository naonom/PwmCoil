//multiplexer pin
const int outputs[4] = {4,3,2}; // pins for selecting LED A B C
const int io_pin = 9; // pin used for sending power to LEDs
const int inhibit_pin = 8; // pin for turning off all LEDs

void setup() {
  for(int ii;ii<3;ii++){
    pinMode(outputs[ii],OUTPUT); // output selection for LED control
  }
  pinMode(inhibit_pin,OUTPUT); 
  digitalWrite(inhibit_pin,LOW); // raise high to disable all
  pinMode(io_pin,OUTPUT); // this controls the power sent to each LED
  digitalWrite(io_pin,HIGH); // send high to all LEDs when powered on
}

void loop() {
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  // looping through all 8 LEDs
  //for (int jj=0;jj<8;jj++){
  //  // turn on LEDs based on bit conversion
  //  for(int ii=0;ii<3;ii++){
  //    digitalWrite(outputs[ii],bitRead(jj,ii)); 
  //  }
  delay(1000); // delay .1 sec
  //}
}
