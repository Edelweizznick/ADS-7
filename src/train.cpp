// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : head(nullptr), steps(0) {}

void Train::addCar(bool light) {
  Car* node = new Car{light, nullptr, nullptr};
  if (!head) {
    head = node;
    head->next = head;
    head->prev = head;
  } else {
    Car* tail = head->prev;
    tail->next = node;
    node->prev = tail;
    node->next = head;
    head->prev = node;
  }
}

int Train::getOpCount() {
  return steps;
}

int Train::getLength() {
  if (!head) return 0;

  int length = 0;
  Car* p = head;
  do {
    p = p->next;
    ++length;
  } while (p != head);

  bool allOff = true;
  bool allOn = true;
  p = head;
  for (int i = 0; i < length; ++i) {
    if (p->light) allOff = false;
    if (!p->light) allOn = false;
    p = p->next;
  }

  steps = 0;
  if (allOff) {
    steps = 2 * length;
  } else if (allOn) {
    steps = length * (length + 1);
  } else {
    p = head;
    do {
      p = p->next;
      ++steps;
    } while (p != head);
  }

  return length;
}
