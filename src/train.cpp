// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getOpCount() {
  return countOp;
}

int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  Car* home = first;
  home->light = true;
  int k = 1;
  while (true) {
    Car* curr = home;
    for (int i = 0; i < k; ++i) {
      curr = curr->next;
      countOp++;
    }
    bool turnedOffMarker = (curr == home);
    curr->light = false;
    for (int i = 0; i < k; ++i) {
      curr = curr->prev;
      countOp++;
    }
    if (turnedOffMarker) {
      return k;
    }
    k++;
  }
}
