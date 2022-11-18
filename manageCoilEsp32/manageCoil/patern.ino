int countA = 0;
int countC = 0;
int countW = 0;
int countD = 252;
boolean whichMotor = true;
boolean flag = 0;

void drop(){
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
  //ActMotorB(countB);
  //StopMotorA();
  //delay(timeOFF);

  if(CountFlag == true){
    countA -= 10;
  }else{
    countA += 10;
  }
}
void OnOffA_p(int power){
  ActMotorA(power);
  delay(50);
  StopMotorA();
  delay(50);
}
void OnOffA(){
  ActMotorA(152);
  delay(50);
  StopMotorA();
  delay(50);
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
    countA -= 10;
  }else{
    countA += 10;
  }
  delay(10);
}

void cross(){
  if(countC>=255){
    CountFlag = true;
    countC = 250;
    delay(1000);
  }
  if(countC<=0){
    CountFlag = false;
    StopMotorA();
    delay(1000);
  }

  ActMotorA(countC);
  
  if(CountFlag == true){
    countC -= 10;
  }else{
    countC += 10;
  }
  delay(50);
}

void wave(){
  onewave(250, 85);
}
//power 1-250
//temp 0-100
void onewave(int power, int temp){
  if(countA>=power){
    CountFlag = true;
    countA = 250;
    delay(40);
  }
  if(countA<=0){
    CountFlag = false;
    StopMotorA();
    flag += 1;
    delay(40);
  }
  ActMotorA(countA);
  //ActMotorB(countB);
  //StopMotorA();
  //delay(timeOFF);

  if(CountFlag == true){
    countA -= power/(101-temp);
  }else{
    countA += power/(101-temp);
  }
  delay(10);
}

void reset(){
  countA = 0;
  countC = 0;
  countW = 0;
}
