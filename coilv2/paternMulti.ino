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
    reset();
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
//frame 20 (50 to 1sec)
void communicate(){
  //init
  if(isFirst == true){
    reset();
    //power[0] = 125;
    isFirst = false;
    count = 0;
  }

  if(count >= 0  && count < 250){
    smallToBigLinear(4,50);
  }
  if(count >= 250 && count < 500){
    power[4] = 0;
    smallToBigLinear(1,50);
  }
  if(count >= 500 && count < 750){
    power[1] = 0;
    smallToBigLinear(4,50);
  }
  if(count >= 750 && count < 850){
    power[4] = 0;
    smallToBigLinear(1,50);
  }
  if(count >= 850 && count < 900){
    reset();
  }
  if(count >= 900 && count < 1150){
    power[1] = 0;
    smallToBigLinear(4,50);
  }
  if(count >= 1150 && count < 1400){
    power[4] = 0;
    smallToBigLinear(1,50);
  }


  count+=1;

  if(count == 1400){
    delay(2000);
    isFirst = true;
  }
}

void movelinear(){
  //init
  if(isFirst == true){
    power[0] = 200;
    isFirst = false;
    count = 0;
  }

  if(count >= 0  && count < 100){
    power[0] -= 2;
    power[1] += 2;
  }
  if(count >= 100 && count < 200){
    power[0] += 2;
    power[1] -= 2;
  }

  count+=1;

  if(count == 200){
    isFirst = true;
  }
  
  Serial.println(power[0]);

}

void movedinamic(){
  //init
  if(isFirst == true){
    power[0] = 250;
    isFirst = false;
    count = 0;
  }

  if(count >= 0  && count < 100){
    power[0] = 250;
    power[1] = 0;
  }
  if(count >= 100 && count < 200){
    power[0] = 0;
    power[1] = 250;
  }

  count+=1;

  if(count == 200){
    isFirst = true;
  }
  
  Serial.println(power[0]);

}