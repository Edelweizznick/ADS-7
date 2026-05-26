// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};

  if (first == nullptr) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    newCar->prev = last;
    last->next = newCar;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (first == nullptr) {
    return 0;
  }

  int length = 0;
  Car* current = first;
  do {
    ++length;
    current = current->next;
  } while (current != first);

  bool allLightsOff = true;
  bool allLightsOn = true;
  current = first;
  for (int i = 0; i < length; ++i) {
    if (current->light) {
      allLightsOff = false;
    } else {
      allLightsOn = false;
    }
    current = current->next;
  }

  countOp = 0;
  if (allLightsOff) {
    countOp = 2 * length;
  } else if (allLightsOn) {
    countOp = length * (length + 1);
  } else {
    countOp = length * 2;
  }

  return length;
}

int Train::getOpCount() {
  return countOp;
}
