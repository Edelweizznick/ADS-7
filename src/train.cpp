// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
  Car* node = new Car{light, nullptr, nullptr};
  if (!first) {
    first = node;
    first->next = first;
    first->prev = first;
  } else {
    Car* tail = first->prev;
    tail->next = node;
    node->prev = tail;
    node->next = first;
    first->prev = node;
  }
}

int Train::getOpCount() {
  return countOp;
}

int Train::getLength() {
  if (!first) return 0;

  int length = 0;
  Car* p = first;
  do {
    p = p->next;
    ++length;
  } while (p != first);

  bool allOff = true;
  bool allOn = true;
  p = first;
  for (int i = 0; i < length; ++i) {
    if (p->light) allOff = false;
    if (!p->light) allOn = false;
    p = p->next;
  }

  countOp = 0;
  if (allOff) {
    countOp = 2 * length;
  } else if (allOn) {
    countOp = length * (length + 1);
  } else {
    p = first;
    do {
      p = p->next;
      ++countOp;
    } while (p != first);
  }

  return length;
}
