#ifndef PINMAP_H
#define PINMAP_H

#define ZIF_PIN(pin) zifPinMap[pin]

const int zifPinMap[] = {
  -1,  // index 0 not used
  34,   // ZIF Pin 1 -> Arduino Pin 22
  36,   // ZIF Pin 2 -> Arduino Pin 23
  38,   // ZIF Pin 3
  40,   // ZIF Pin 4
  42,   // ZIF Pin 5
  44,   // ZIF Pin 6
  46,   // ZIF Pin 7
  48,   // ZIF Pin 8
  50,   // ZIF Pin 9
  52,   // ZIF Pin 10
  53,   // ZIF Pin 11
  51,   // ZIF Pin 12
  49,   // ZIF Pin 13
  47,   // ZIF Pin 14
  45,   // ZIF Pin 15
  43,   // ZIF Pin 16
  41,   // ZIF Pin 17
  39,   // ZIF Pin 18
  37,   // ZIF Pin 19
  35,   // ZIF Pin 20
};

#endif
