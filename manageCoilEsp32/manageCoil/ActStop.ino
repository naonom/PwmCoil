
//Act A
void ActMotorA(int power){
  Serial.println("ACT A");
  digitalWrite(enA, HIGH);
  //digitalWrite(inA1, HIGH);
  ledcWrite(0, power);
  digitalWrite(inA2, LOW);
}

void ActMotorB(int power){
  Serial.println("ACT B");
  digitalWrite(enB, HIGH);
  //digitalWrite(inB1, HIGH);
  ledcWrite(1, power);
  digitalWrite(inB2, LOW);
}

void StopMotorA(){
  Serial.println("STOP");
  //digitalWrite(inA1, LOW);
  ledcWrite(0, 0);
  digitalWrite(inA2, LOW);
  digitalWrite(enA, LOW);
}

void StopMotorB(){
  Serial.println("STOP");
  //digitalWrite(inB1, LOW);
  ledcWrite(1, 0);
  digitalWrite(inB2, LOW);
  digitalWrite(enB, LOW);
}
