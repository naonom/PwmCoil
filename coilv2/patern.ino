int count1 = 0;
int count2 = 0;

//11, 10, 9, 6, 5
float power[5] = {0, 0, 0, 0, 0};
boolean countFlag[5] = {false, false, false, false, false};
int timerCount[5] = {0, 0, 0, 0, 0};
int dropCount[5] = {0, 0, 0, 0, 0};

void reset(){
  count1 = 0;
  count2 = 0;

  for(int i=0; i<=4; i++){
    power[i] = 0;
  }
  for(int n=0; n<=4; n++){
    countFlag[n] = false;
  }
  for(int j=0; j<=4; j++){
    timerCount[j] = 0;
  }

}


//act analog coils
void act(){
  //analogWrite(11, power[0]);
  analogWrite(10, power[0]);
  analogWrite(9, power[1]);
  analogWrite(6, power[2]);
  analogWrite(5, power[3]);
  analogWrite(3, power[4]);
}

//50 to 1 sec 
//act one select coil num to pos
void smallToBigLinear(int pos, int time){

  if(countFlag[pos] == true){
    power[pos] -= 250/time;
  }else{
    power[pos] += 250/time;
  }

  if(power[pos] > 255){
    countFlag[pos] = true;
    power[pos] = 255;
  }
  if(power[pos] < 0){
    countFlag[pos] = false;
    power[pos] = 0;
  }
}

//act one select coil num to pos
//frame 20 ms (50 to 1 sec)
void smallToBigDinamic(int pos, int time){
  if(timerCount[pos] <= time && countFlag[pos] == false){
    power[pos] = 255;
  }
  
  if(timerCount[pos] <= time && countFlag[pos] == true){
    power[pos] = 0;
  }

  if(timerCount[pos] == time){
    timerCount[pos] = 0;
    countFlag[pos] = !countFlag[pos];
  }

  timerCount[pos] += 1;
  //Serial.println(timerCount[pos]);
  //Serial.println(power[pos]);
}

void smallToBigLinearV2(int pos, int makeTime, int disTime){
    if(countFlag[pos] == true){
    power[pos] -= 250/disTime;
  }else{
    power[pos] += 250/makeTime;
  }

  if(power[pos] > 255){
    countFlag[pos] = true;
    power[pos] = 255;
  }
  if(power[pos] < 0){
    countFlag[pos] = false;
    power[pos] = 0;
  }
}

//50 to 1 sec 
//act one select coil num to pos
void smallToBigLinearPower(int pos, float time, float max){
  if(countFlag[pos] == true){
    power[pos] -= max/time;
  }else{
    power[pos] += max/time;
  }

  if(power[pos] > max){
    countFlag[pos] = true;
    power[pos] = max;
  }
  if(power[pos] < 0){
    countFlag[pos] = false;
    power[pos] = 0;
  }
}



//50 to 1 sec
void tsuno(int pos){
  if(timerCount[pos]>=0 && timerCount[pos]<=2){
    power[pos] = 255;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=2 && timerCount[pos]<=149){
    power[pos] = 90;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=150 && timerCount[pos]<=249){
    power[pos] = 0;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]==250){
    timerCount[pos]=0;
  }
}

void tsunoSlow(int pos){
  if(timerCount[pos] == 0 && power[pos]<=90){
    power[pos] += 2;
  }else{
    timerCount[pos]+=1;
  }

  if(timerCount[pos]>=1 && timerCount[pos]<=3){
    power[pos] = 255;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=4 && timerCount[pos]<=149){
    power[pos] = 90;
    timerCount[pos]+=1;
  }

  if(timerCount[pos] >= 150){
    if(power[pos]>0){
      power[pos] -= 2;
    }else{
      delay(1000);
      timerCount[pos] = 0;
    }
  }



  // if(timerCount[pos]>=150 && timerCount[pos]<=249){
  //   power[pos] = 0;
  //   timerCount[pos]+=1;
  // }
  // if(timerCount[pos]==250){
  //   timerCount[pos]=0;
  // }
  //Serial.println(power[pos]);
}
//50 to 1
//25 to 0.5
//12 to 0.25
//6 to 0.15
void heart(int pos){
  if(timerCount[pos]>=0 && timerCount[pos]<=50){
    power[pos] = 50;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=50 && timerCount[pos]<=56){
    power[pos] = 80;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=56 && timerCount[pos]<=62){
    power[pos] = 0;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=62 && timerCount[pos]<=68){
    power[pos] = 255;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=68 && timerCount[pos]<=74){
    power[pos] = 0;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=74 && timerCount[pos]<=80){
    power[pos] = 80;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=80 && timerCount[pos]<=92){
    power[pos] = 50;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]==93){
    timerCount[pos]=0;
  }
}

void tsunoDinamic(int pos){
  if(timerCount[pos]>=0 && timerCount[pos]<=50){
    power[pos] = 85;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=50 && timerCount[pos]<75){
    power[pos] = 0;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=75 && timerCount[pos]<=86){
    power[pos] = 127;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]>=86 && timerCount[pos]<=92){
    power[pos] = 85;
    timerCount[pos]+=1;
  }
  if(timerCount[pos]==93){
    timerCount[pos]=0;
  }
}

void cycleAndAmp(int pos){
  
}

void drop(int pos){
  if(timerCount[pos]==0){
    dropCount[pos] = 0;
  }

  if(countFlag[2] == false){
    power[pos] = dropCount[pos];
  }else{
    power[pos] = 240 - dropCount[pos];
  }

  timerCount[pos]+=1;

  if(dropCount[pos] == 240){
    dropCount[pos] = 0;
  }
  //Serial.println(power[pos]);

  if(dropCheckframe(timerCount[pos])==true){
    if(countFlag[2]==true){
      countFlag[2] = false;
      dropCount[pos] += 4;
    }else{
      countFlag[2] = true;
    }
    //countFlag[2] != countFlag[2];
    //dropCount[pos] += 4;
  }

  if(240 - dropCount[2] <= 0){
    dropCount[2] = 0;
  }
}

boolean dropCheckframe(int num){
  if(num%2==0){
    return false;
  }else{
    return true;
  }
}



