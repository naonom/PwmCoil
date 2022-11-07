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

void pwm(){
  if(countA>=255){
    CountFlag = true;
    countA = 250;
    //ActMotorA(countA);
    delay(1000);
  }
  if(countA<=0){
    CountFlag = false;
    StopMotorB();
    delay(1000);
  }
  ActMotorA(countA);
  //ActMotorB(countB);
  //StopMotorA();
  //delay(timeOFF);

  if(CountFlag == true){
    countA -= 10;
  }else{
    countA += 10;
  }
  delay(50);
}
