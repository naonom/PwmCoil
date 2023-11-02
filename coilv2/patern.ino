int count1 = 0;
int count2 = 0;

//11, 10, 9, 6, 5
int power[5] = {0, 0, 0, 0, 0};
boolean countFlag[5] = {false, false, false, false, false};
int timerCount[5] = {0, 0, 0, 0, 0};


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
  analogWrite(11, power[0]);
  analogWrite(10, power[1]);
  analogWrite(9, power[2]);
  analogWrite(6, power[3]);
  analogWrite(5, power[4]);
}


//act one select coil num to pos
void smallToBigLinear(int pos, int time){
  if(countFlag[pos] == true){
    power[pos] -= time;
  }else{
    power[pos] += time;
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


