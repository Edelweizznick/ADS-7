#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
  if (!first) return;
  Car* curr = first;
  do {
    Car* nextCar = curr->next;
    delete curr;
    curr = nextCar;
  } while (curr != first);
}

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

int Train::getOpCount() const {
  return countOp;
}

int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  Car* home = first;
  home->light = true; // Устанавливаем маркер ON
  int k = 1;
  while (true) {
    Car* curr = home;
    // Идём вперёд k шагов
    for (int i = 0; i < k; ++i) {
      curr = curr->next;
      countOp++;
    }
    curr->light = false; // Выключаем
    // Возвращаемся k шагов
    for (int i = 0; i < k; ++i) {
      curr = curr->prev;
      countOp++;
    }
    if (!home->light) { // Если маркер выключен — цикл замкнулся, k = n
      return k;
    }
    k++;
  }
}