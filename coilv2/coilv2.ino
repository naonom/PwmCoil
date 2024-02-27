//move 5 big coils

#include <Wire.h>
int MotorFlag = 0;

unsigned char getdata[4] = {0, 0, 0, 0};
unsigned int data[4] = {0, 0, 0, 0};

int timer = 0;

unsigned int action[5] = {0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
  Serial.println("start");

//6   10
//. 9
//5   11

  //analogWrite(10, power[0]);
  //analogWrite(9, power[1]);
  //analogWrite(6, power[2]);
  //analogWrite(5, power[3]);
  //analogWrite(3, power[4]);
  //motor pin
  //pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);

  //manage patern
  MotorFlag = 0;

  //get sub arduino sensors {256, 256, 256, 256}
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Wire.requestFrom(8, 4);
  
  //init
  reset();
}

void loop() {
  if(Serial.available()){
    switch(Serial.read()){
      case '1':
        Serial.println("patern 1");
        MotorFlag = 1;
        break;
      case '2':
        Serial.println("patern 2");
        MotorFlag = 2;
        break;
      case '3':
        Serial.println("patern 3");
        MotorFlag = 3;
        break;
      case '4':
        Serial.println("patern 4");
        MotorFlag = 4;
        break;
      case '5':
        Serial.println("patern 5");
        MotorFlag = 5;
        break;
      case '6':
        Serial.println("patern 6");
        MotorFlag = 6;
        break;
      case '7':
        Serial.println("patern 7");
        MotorFlag = 7;
        break;
      case '8':
        Serial.println("patern 8");
        MotorFlag = 8;
        break;
      case '9':
        Serial.println("patern 9");
        MotorFlag = 9;
        break;
      case 'a':
        Serial.println("patern 10");
        MotorFlag = 10;
        break;
      case 'b':
        Serial.println("patern 11");
        MotorFlag = 11;
        break;
      case 'c':
        Serial.println("patern 12");
        MotorFlag = 12;
        break;
      case 'd':
        Serial.println("patern 13");
        MotorFlag = 13;
        break;
      case 'e':
        Serial.println("patern 14");
        MotorFlag = 14;
        break;
      case 'f':
        Serial.println("patern 15");
        MotorFlag = 15;
        break;

      case 'g':
        Serial.println("patern 16");
        MotorFlag = 16;
        break;

      case 'h':
        Serial.println("patern 17");
        MotorFlag = 17;
        break;
      case '0':
        Serial.println("end");
        MotorFlag = 0;
        analogWrite(11, LOW);
        analogWrite(10, LOW);
        analogWrite(9, LOW);
        analogWrite(6, LOW);
        analogWrite(5, LOW);
        reset();
        timer = 0;
        for(int i=0; i<5; i++){
          action[i] = 0;
        }
        act();
        delay(20);
        break;
    }
  }

  if(MotorFlag == 1){
    smallToBigLinear(2, 100);
    smallToBigLinear(0, 100);
    smallToBigLinear(1, 100);
    //smallToBigLinear(2, 100);
    smallToBigLinear(3, 100);
    smallToBigLinear(4, 100);
    act();
  }
  if(MotorFlag == 2){
    //smallToBigDinamic(2, 50);
    smallToBigDinamicPower(2, 50, 180);
    act();
  }
  if(MotorFlag ==3){
    move();
    act();
  }
  if(MotorFlag ==4){
    communicate();
    act();
  }
  if(MotorFlag ==5){
    movelinear();
    act();
  }
  if(MotorFlag ==6){
    movedinamic();
    act();
  }
  if(MotorFlag ==7){
    //smallToBigLinearPower(0, 100, data[0]);
    smallToBigLinearPower(2, 100, 80);
    //smallToBigLinearPower(3, 100, data[2]);
    //smallToBigLinearPower(4, 100, data[3]);
    act();
  }
  if(MotorFlag ==8){
    tsuno(2);
    act();
  }
  if(MotorFlag ==9){
    heart(2);
    act();
  }
  if(MotorFlag ==10){
    tsunoDinamic(2);
    act();
  }

  if(MotorFlag ==11){
    cycleAndAmp(4);
    act();
  }

  if(MotorFlag ==12){
    drop(2);
    act();
  }

  if(MotorFlag ==13){
    smallToBigLinearV2(2, 100, 1);
    act();
  }
  if(MotorFlag ==14){
    tsunoSlow(2);
    act();
  }
  if(MotorFlag ==15){
    smallToBigDinamicPower(2, 100, 80);
    act();
  }

  if(MotorFlag ==16){
    if(timer >= 0 && timer < 50){
      heart(2);
    }
    if(timer >= 50 && timer < 70){
      heart(0);
      heart(2);
    }
    if(timer >= 70 && timer < 94){
      heart(0);
      heart(2);
      heart(3);
    }
    if(timer >= 94 && timer < 100){
      heart(3);
    }

    if(timer >= 100 && timer < 144){
      heart(0);
      heart(1);
      heart(3);

    }
    if(timer >= 144 && timer < 164){
      heart(1);
      heart(3);
      heart(4);

    }
    if(timer >= 190 && timer < 194){
      heart(0);
      heart(1);
      heart(4);

    }
    if(timer >= 194 && timer < 236){
      heart(0);
      heart(4);

    }
    if(timer >= 237 && timer < 250){
      heart(0);

    }
    if(timer >= 250 && timer < 260){
      heart(0);
      heart(2);

    }
    if(timer >= 260 && timer < 284){
      heart(0);
      heart(2);
      heart(4);

    }
    if(timer >= 284 && timer < 300){
      heart(2);
      heart(4);

    }
    if(timer >= 300 && timer < 344){
      heart(1);
      heart(2);
      heart(4);

    }
    if(timer >= 344 && timer < 354){
      heart(1);
      heart(4);

    }
    if(timer >= 354 && timer < 394){
      heart(1);

    }
    if(timer == 395){
       timer = 0;
    }
    timer+=1;
    act();
    //Serial.println(timer);
  }

  if(MotorFlag ==17){
    if(data[2] >= 1 && action[2] == 0){
      action[2]+=1;
    }
    
    if(action[2] >= 1){
      smallToBigLinearV2(2, 100, 100);
      timer+=1;
    }
    if(timer == 256){
      action[2] -= 1;
      timer = 0;
    }
    //Serial.println(timer);
    act();
  }

  //Serial.println(data[2]);

  delay(20);
}

void receiveEvent(int howmeny){
  for(uint8_t i = 0; i<4; i++){
    getdata[i] = Wire.read();
    data[i] = int(getdata[i]);
    //Serial.print(data[i]);
    //Serial.print(", ");
  }
  //Serial.println(";");

  delay(100);
}
