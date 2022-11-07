
//Act A
void ActMotorA(int power){
  Serial.println("ACT");
  digitalWrite(enA, HIGH);
  //digitalWrite(inA1, HIGH);
  ledcWrite(0, 100);
  digitalWrite(inA2, LOW);
}

void ActMotorB(int power){
  Serial.println("ACT");
  digitalWrite(enB, HIGH);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
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
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
  digitalWrite(enB, LOW);
}
