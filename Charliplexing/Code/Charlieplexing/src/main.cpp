#include <Arduino.h>

#define L1 PD6
#define L2 PA2
#define L3 PC1
#define L4 PC2

void setLed(uint8_t index) {
  if (index < 0 || index >= 11) {
    pinMode(L1, INPUT);
    pinMode(L2, INPUT);
    pinMode(L3, INPUT);
    pinMode(L4, INPUT);
    return;
  }

  uint32_t high, low;

  switch (index) {
    case 0:
      high = L1;
      low = L2;
      break;
    case 1:
      high = L2;
      low = L1;
      break;
    case 2:
      high = L1;
      low = L3;
      break;
    case 3:
      high = L3;
      low = L1;
      break;
    case 4:
      high = L1;
      low = L4;
      break;
    case 5:
      high = L4;
      low = L1;
      break;
    case 6:
      high = L2;
      low = L3;
      break;
    case 7:
      high = L3;
      low = L2;
      break;
    case 8:
      high = L2;
      low = L4;
      break;
    case 9:
      high = L4;
      low = L2;
      break;
    case 10:
      high = L3;
      low = L4;
      break;
    case 11:
      high = L4;
      low = L3;
      break;
  }

  if (high == L1 || low == L1) {
    pinMode(L1, OUTPUT);
  } else {
    pinMode(L1, INPUT);
  }

  if (high == L2 || low == L2) {
    pinMode(L2, OUTPUT);
  } else {
    pinMode(L2, INPUT);
  }

  if (high == L3 || low == L3) {
    pinMode(L3, OUTPUT);
  } else {
    pinMode(L3, INPUT);
  }

  if (high == L4 || low == L4) {
    pinMode(L4, OUTPUT);
  } else {
    pinMode(L4, INPUT);
  }

  digitalWrite(high, HIGH);
  digitalWrite(low, LOW);
  delayMicroseconds(10);
  digitalWrite(high, LOW);
}

void setup() {
}

uint8_t counter = 0;
long prevTime;
long duration;

void loop1();
void loop2();

void loop() {
  loop1();
}

void loop1() {
  long t = millis();
  duration += t - prevTime;

  if (duration > 200) {
    duration = 0;
    counter++;

    if (counter >= 11) {
      counter = 0;
    }
  }

  for (int i = 0; i <= counter; i++) {
    setLed(i);
  }

  prevTime = t;
}

void loop2() {
  delay(200);

  setLed(counter++);

  if (counter >= 11)
  {
    counter = 0;
  }
}