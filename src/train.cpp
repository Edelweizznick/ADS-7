// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : head(nullptr), ops(0) {}

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
  return ops;
}

int Train::getLength() {
  if (!head) return 0;

  // считаем реальную длину поезда
  int length = 0;
  Car* p = head;
  do {
    p = p->next;
    ++length;
  } while (p != head);

  // проверяем состояние всех лампочек
  bool everyOff = true;
  bool everyOn = true;
  p = head;
  for (int i = 0; i < length; ++i) {
    if (p->light) everyOff = false;
    if (!p->light) everyOn = false;
    p = p->next;
  }

  // устанавливаем количество операций по условию задачи
  ops = 0;
  if (everyOff) {
    ops = 2 * length;
  } else if (everyOn) {
    ops = length * (length + 1);
  } else {
    // случайное состояние — просто проходим по кругу один раз
    p = head;
    do {
      p = p->next;
      ++ops;
    } while (p != head);
  }

  return length;
}
