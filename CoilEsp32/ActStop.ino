//ActA
void ActMotorA(int power){
  Serial.println("ACT A");
  digitalWrite(enA, HIGH);
  ledcWrite(0, power);
}

//ActB
void ActMotorB(int power){
  Serial.println("ACT B");
  digitalWrite(enB, HIGH);
  ledcWrite(1, power);
}

//ActAB
void ActMotor(int powerA, int powerB){
  //Serial.println("ACT AB");
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  ledcWrite(0, powerA);
  ledcWrite(1, powerB);
}

//StopA
void StopMotorA(){
  Serial.println("STOP A");
  ledcWrite(0, 0);
  digitalWrite(enA, LOW);
}

//StopB
void StopMotorB(){
  Serial.println("STOP B");
  ledcWrite(1, 0);
  digitalWrite(enB, LOW);
}

//StopAB
void StopMotor(){
  Serial.println("STOP AB");
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  ledcWrite(0,0);
  ledcWrite(1,0);
}
