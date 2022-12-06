
//Act A
void ActMotorA(int power){
  Serial.println("ACT A");
  digitalWrite(enA, HIGH);
  ledcWrite(0, power);
}

void ActMotorB(int power){
  Serial.println("ACT B");
  digitalWrite(enB, HIGH);
  //digitalWrite(inB1, HIGH);
  ledcWrite(1, power);
  //digitalWrite(inB2, LOW);
}

void ActMotor(int powerA, int powerB){
  Serial.println("ACT AB");
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  ledcWrite(0, powerA);
  ledcWrite(1, powerB);
  //digitalWrite(inA2, LOW);
  //digitalWrite(inB2, LOW);
}

void StopMotorA(){
  Serial.println("STOP");
  ledcWrite(0, 0);
  digitalWrite(enA, LOW);
}

void StopMotorB(){
  Serial.println("STOP");
  //digitalWrite(inB1, LOW);
  ledcWrite(1, 0);
  digitalWrite(inB2, LOW);
  digitalWrite(enB, LOW);
}

void StopMotor(){
  Serial.println("STOP");
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  ledcWrite(0,0);
  ledcWrite(1,0);
}
