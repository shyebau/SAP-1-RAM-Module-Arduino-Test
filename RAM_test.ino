/// Built using Arduino UNO R4, may need to change pins
/// RAM chip write enable is active low

void setup() {

  int addrOut[4] = {13, 12, 11, 10};
  int dataOut[8] = {7, 6, 5, 4, A0, A1, A2, A3};
  
  for (int i : addrOut){   /// Initial address 0000
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  for (int i : dataOut){   /// Initial data 00000000
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(3, OUTPUT);
}

void incBit(int bits[], int size) {       /// Bit incrementer for LOW and HIGH values
  for (int i = size - 1; i >= 0; i--) {
    if (bits[i] == LOW) {
      bits[i] = HIGH;
      break;
      }
    bits[i] = LOW;
    }
  }

void loop() {

  digitalWrite(3, LOW);

  int addrIn[4] = {LOW, LOW, LOW, LOW};      /// Current testing state for address and data
  int dataIn[8] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

  int addrOut[4] = {13, 12, 11, 10};         /// Copy pins properly, in order from MSB to LSB
  int dataOut[8] = {7, 6, 5, 4, A0, A1, A2, A3};

  for (int i = 0; i < 16; i++){              /// Increments and stores first 4 and last 4 bits
    for (int j = 0; j < 4; j++){             /// into the corresponding address
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

  digitalWrite(3, HIGH);    /// Write disable, starts reading

  while (true){                          /// Cycles through address 0000-1111 and sends the address
    for (int i = 0; i < 16; i++){        /// to the circuit, verify the circuit functionality visually
      for (int j = 0; j < 4; j++){
        digitalWrite(addrOut[j], addrIn[j]);
      }
      incBit(addrIn, 4);
      delay(100);
    }
  }
}
