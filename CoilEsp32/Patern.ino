//OnOff
//pwm
//smallToBig
//drop
#define PI 3.14

int countA = 0;

int count1 = 0;
int count2 = 100;
boolean flag1;
boolean flag2;

float deg = 0, Rad;
int motorP;
float resist;

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

void AB(){
  Rad = count1/(180/PI);
  motorP = int((sin(Rad)+1)*122);
  resist = val1/1000;
  float temp = resist/4;
  
  if(count1>=360){
    flag1 = true;
    count1 = 360;
    delay(50);
  }
  if(count1<=0){
    flag1 = false;
    delay(50);
  }
  //Serial.println(zeroToOne(val2,4095));
  int pA = (sin(Rad)+1)*128;
  int pB = (sin(Rad+temp)+1)*128;

  String p = String(pB);
  Serial.println(temp);
  
  ActMotor(pA, pB);
  //ActMotorB(countB);
  //StopMotorA();
  //delay(timeOFF);

  if(flag1 == true){
    count1 = 0;
  }else{
    count1 += 3;
  }
  //Serial.println(resist);
  delay(200);
}
