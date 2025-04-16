#include <Arduino.h>
#include "pinmap.h"
#include "ictests.h"

bool test7402() {
  int gates[4][3] = {
    {3, 2, 1},
    {6, 5, 4},
    {14, 15, 16},
    {17, 18, 19}
  };

  // Power the IC
  pinMode(ZIF_PIN(14), OUTPUT); digitalWrite(ZIF_PIN(20), HIGH); // Vcc
  pinMode(ZIF_PIN(7), OUTPUT);  digitalWrite(ZIF_PIN(7), LOW);   // GND

  // Configure pins
  for (int i = 0; i < 4; i++) {
    pinMode(ZIF_PIN(gates[i][0]), OUTPUT); // Input A
    pinMode(ZIF_PIN(gates[i][1]), OUTPUT); // Input B
    pinMode(ZIF_PIN(gates[i][2]), INPUT);  // Output Y
  }

  // Test NOR logic
  for (int i = 0; i < 4; i++) {
    int in1 = gates[i][0];
    int in2 = gates[i][1];
    int out = gates[i][2];

    for (int a = 0; a <= 1; a++) {
      for (int b = 0; b <= 1; b++) {
        digitalWrite(ZIF_PIN(in1), a);
        digitalWrite(ZIF_PIN(in2), b);
        delay(10);
        int y = digitalRead(ZIF_PIN(out));
        int expected = !(a || b); // NOR logic
        if (y != expected) {
          return false;
        }
      }
    }
  }

  return true;
}



bool test7400() {
    int gates[4][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {14, 15, 16},
      {17, 18, 19}
    };
  
    // Power the IC
    pinMode(ZIF_PIN(14), OUTPUT); digitalWrite(ZIF_PIN(20), HIGH); // Vcc
    pinMode(ZIF_PIN(7), OUTPUT);  digitalWrite(ZIF_PIN(7), LOW);   // GND
  
    // Configure pins
    for (int i = 0; i < 4; i++) {
      pinMode(ZIF_PIN(gates[i][0]), OUTPUT);
      pinMode(ZIF_PIN(gates[i][1]), OUTPUT);
      pinMode(ZIF_PIN(gates[i][2]), INPUT);
    }
  
    // Test NAND logic
    for (int i = 0; i < 4; i++) {
      int in1 = gates[i][0];
      int in2 = gates[i][1];
      int out = gates[i][2];
  
      for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
          digitalWrite(ZIF_PIN(in1), a);
          digitalWrite(ZIF_PIN(in2), b);
          delay(5);
          int y = digitalRead(ZIF_PIN(out));
          int expected = !(a && b);
          if (y != expected) {
            return false;
          }
        }
      }
    }
  
    return true;
}
  

bool test7404() {
    int gates[6][2] = {
      {1, 2},
      {3, 4},
      {5, 6},
      {15, 14},
      {17, 16},
      {19, 18}
    };
  
    pinMode(ZIF_PIN(14), OUTPUT); digitalWrite(ZIF_PIN(20), HIGH); // Vcc
    pinMode(ZIF_PIN(7), OUTPUT);  digitalWrite(ZIF_PIN(7), LOW);   // GND
  
    for (int i = 0; i < 6; i++) {
      pinMode(ZIF_PIN(gates[i][0]), OUTPUT);
      pinMode(ZIF_PIN(gates[i][1]), INPUT);
    }
  
    for (int i = 0; i < 6; i++) {
      int in = gates[i][0];
      int out = gates[i][1];
  
      for (int a = 0; a <= 1; a++) {
        digitalWrite(ZIF_PIN(in), a);
        delay(5);
        int y = digitalRead(ZIF_PIN(out));
        int expected = !a;
        if (y != expected) {
          return false;
        }
      }
    }
  
    return true;
}

bool test7486() {
    int gates[4][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {15, 16, 14},
      {18, 19, 17}
    };
  
    // Power pins
    pinMode(ZIF_PIN(14), OUTPUT); digitalWrite(ZIF_PIN(20), HIGH); // Vcc
    pinMode(ZIF_PIN(7), OUTPUT);  digitalWrite(ZIF_PIN(7), LOW);   // GND
  
    // Set input/output modes
    for (int i = 0; i < 4; i++) {
      pinMode(ZIF_PIN(gates[i][0]), OUTPUT); // A
      pinMode(ZIF_PIN(gates[i][1]), OUTPUT); // B
      pinMode(ZIF_PIN(gates[i][2]), INPUT);  // Y
    }
  
    for (int i = 0; i < 4; i++) {
      int in1 = gates[i][0];
      int in2 = gates[i][1];
      int out = gates[i][2];
  
      for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
          digitalWrite(ZIF_PIN(in1), a);
          digitalWrite(ZIF_PIN(in2), b);
          delayMicroseconds(100); // Let the output settle
  
          int y = digitalRead(ZIF_PIN(out));
          int expected = a ^ b;
  
          if (y != expected) {
            // Debug info (optional)
            Serial.print("FAIL @ Gate "); Serial.print(i);
            Serial.print(" | A="); Serial.print(a);
            Serial.print(", B="); Serial.print(b);
            Serial.print(", Y="); Serial.print(y);
            Serial.print(" != "); Serial.println(expected);
            return false;
          }
        }
      }
    }
  
    return true;
  }
  
bool test7408() {
    int gates[4][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {15, 16, 14},
      {18, 19, 17}
    };
  
    pinMode(ZIF_PIN(14), OUTPUT); digitalWrite(ZIF_PIN(14), HIGH); // Vcc
    pinMode(ZIF_PIN(7), OUTPUT);  digitalWrite(ZIF_PIN(7), LOW);   // GND
  
    for (int i = 0; i < 4; i++) {
      pinMode(ZIF_PIN(gates[i][0]), OUTPUT);
      pinMode(ZIF_PIN(gates[i][1]), OUTPUT);
      pinMode(ZIF_PIN(gates[i][2]), INPUT);
    }
  
    for (int i = 0; i < 4; i++) {
      int in1 = gates[i][0];
      int in2 = gates[i][1];
      int out = gates[i][2];
  
      for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
          digitalWrite(ZIF_PIN(in1), a);
          digitalWrite(ZIF_PIN(in2), b);
          delay(5);
          int y = digitalRead(ZIF_PIN(out));
          int expected = a && b;
          if (y != expected) return false;
        }
      }
    }
  
    return true;
}

bool test7432() {
    int gates[4][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {15, 16, 14},
      {18, 19, 17}
    };
  
    pinMode(ZIF_PIN(14), OUTPUT); digitalWrite(ZIF_PIN(20), HIGH); // Vcc
    pinMode(ZIF_PIN(7), OUTPUT);  digitalWrite(ZIF_PIN(7), LOW);   // GND
  
    for (int i = 0; i < 4; i++) {
      pinMode(ZIF_PIN(gates[i][0]), OUTPUT);
      pinMode(ZIF_PIN(gates[i][1]), OUTPUT);
      pinMode(ZIF_PIN(gates[i][2]), INPUT);
    }
  
    for (int i = 0; i < 4; i++) {
      int in1 = gates[i][0];
      int in2 = gates[i][1];
      int out = gates[i][2];
  
      for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
          digitalWrite(ZIF_PIN(in1), a);
          digitalWrite(ZIF_PIN(in2), b);
          delay(5);
          int y = digitalRead(ZIF_PIN(out));
          int expected = a || b;
          if (y != expected) return false;
        }
      }
    }
  
    return true;
}

bool test74266() {
    int gates[4][3] = {
      {1, 2, 3},
      {5, 6, 4},
      {14, 15, 16},
      {19, 18, 17}
    };
  
    pinMode(ZIF_PIN(14), OUTPUT); digitalWrite(ZIF_PIN(20), HIGH); // Vcc
    pinMode(ZIF_PIN(7), OUTPUT);  digitalWrite(ZIF_PIN(7), LOW);   // GND
  
    for (int i = 0; i < 4; i++) {
      pinMode(ZIF_PIN(gates[i][0]), OUTPUT);
      pinMode(ZIF_PIN(gates[i][1]), OUTPUT);
      pinMode(ZIF_PIN(gates[i][2]), INPUT);
    }
  
    for (int i = 0; i < 4; i++) {
      int in1 = gates[i][0];
      int in2 = gates[i][1];
      int out = gates[i][2];
  
      for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
          digitalWrite(ZIF_PIN(in1), a);
          digitalWrite(ZIF_PIN(in2), b);
          delay(5);
          int y = digitalRead(ZIF_PIN(out));
          int expected = !(a ^ b);
          if (y != expected) return false;
        }
      }
    }
  
    return true;
}
  