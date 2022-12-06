//OnOff
//pwm
//smallToBig
//drop

int countA = 0;
int countC = 0;
int countW = 0;
int countD = 252;
boolean whichMotor = true;
boolean flag = 0;
boolean CountFlag;

void OnOff(){
  ActMotor(256, 256);
  delay(1000);
  StopMotor();
  delay(1000);
}

void smallToBig(){
  if(countA>=255){
    CountFlag = true;
    countA = 250;
  }
  if(countA<=0){
    CountFlag = false;
    StopMotorA();
    delay(1000);
  }
  OnOffA_p(countA);

  if(CountFlag == true){
    countA -= 6;
  }else{
    countA += 4;
  }
}

//252-100
void OnOffA_p(int power){
  Serial.println(power);
  ActMotorA(power);
  delay(50);
  Serial.println(252-power);
  ActMotorA(252-power);
  delay(50);
}

void drop(){
  if(countD <= 126){
    countD = 252;
    delay(3000);
  }
  OnOffA_p(countD);
  countD -= 4;
}


void pwm(){
  if(countA>=255){
    CountFlag = true;
    countA = 255;
    delay(1000);
  }
  if(countA<=0){
    CountFlag = false;
    StopMotorA();
    delay(1000);
  }
  ActMotorA(countA);
  //ActMotorB(countB);
  //StopMotorA();
  //delay(timeOFF);

  if(CountFlag == true){
    countA -= 3;
  }else{
    countA += 3;
  }
  delay(30);
}
