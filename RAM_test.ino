void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int addrOut[4] = {13, 12, 11, 10};
  int dataOut[8] = {7, 6, 5, 4, A0, A1, A2, A3};

  for (int i : addrOut){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  for (int i : dataOut){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(3, OUTPUT);
}

void incBit(int bits[], int size) {
  for (int i = size - 1; i >= 0; i--) {
    if (bits[i] == LOW) {
      bits[i] = HIGH;
      break;
      }
    bits[i] = LOW;
    }
  }

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(3, LOW);

  int addrIn[4] = {LOW, LOW, LOW, LOW};
  int dataIn[8] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

  int addrOut[4] = {13, 12, 11, 10};
  int dataOut[8] = {7, 6, 5, 4, A0, A1, A2, A3};
/*
  for (int i = 0; i < 15; i++){
    for (int j : dataOut){
      digitalWrite(j, LOW);
    }
    incBit(addrIn, 8);
  }
*/
  for (int i = 0; i < 16; i++){
    for (int j = 0; j < 4; j++){
      digitalWrite(addrOut[j], addrIn[j]);
    }
    for (int j = 0; j < 8; j++){
      digitalWrite(dataOut[j], dataIn[j]);
    }
    incBit(addrIn, 4);
    incBit(dataIn, 4);
    incBit(dataIn, 8);
    delay(50);
  }

  digitalWrite(3, HIGH);

  for (int i = 0; i < 8; i++){
    dataIn[i] = LOW;
  }

while (true){
  for (int i = 0; i < 16; i++){
      for (int j = 0; j < 4; j++){
        digitalWrite(addrOut[j], addrIn[j]);
      }
      incBit(addrIn, 4);

      delay(100);
    }
}

}
