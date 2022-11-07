void OnOffA(){
  ActMotorA(252);
  delay(500);
  StopMotorA();
  delay(500);
}

void OnOffB(){
  ActMotorB(252);
  delay(500);
  StopMotorB();
  delay(500);
}

void OnOff(){
  ActMotorA(252);
  ActMotorB(252);
  delay(500);
  StopMotorA();
  StopMotorB();
  delay(500);
}

void tantanA(){
  ActMotorA(50);
  delay(500);
  StopMotorA();
  delay(500);
}
