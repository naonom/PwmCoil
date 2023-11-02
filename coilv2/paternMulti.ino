boolean isFirst = true;

//countFlag = 0;
//int power[5] = {0, 0, 0, 0, 0};
// 11 10 9 6 5
//boolean countFlag[5] = {false, false, false, false, false};
//int timerCount[5] = {0, 0, 0, 0, 0};
int count = 0;
boolean isFlag = false;

//frame 20 (50 to 1sec)
//count 125x3 = 375
void move(){
  //init
  if(isFirst == true){
    power[0] = 125;
    isFirst = false;
    count = 0;
  }

  if(count >= 0  && count < 125){
    power[0] -= 1;
    power[2] += 1;
  }
  if(count >= 125 && count < 250){
    power[2] -= 1;
    power[3] += 1;
  }
  if(count >= 250 && count < 375){
    power[3] -= 1;
  }

  count+=1;

  if(count == 375){
    delay(2000);
    isFirst = true;
  }
  
  Serial.println(power[0]);

}