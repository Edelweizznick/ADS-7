// Copyright 2026 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCar(bool light) {
    Car *newCar = new Car;
    newCar->light = light;
    if (first == nullptr) {
        newCar->next = newCar;
        newCar->prev = newCar;
        first = newCar;
    } else {
        Car *last = first->prev;
        newCar->next = first;
        newCar->prev = last;
        last->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    countOp = 0;
    first->light = false;
    Car *current = first->next;
    int length = 1;
    countOp++;
    while (current->light != false) {
        current->light = true;
        current = current->next;
        length++;
        countOp++;
    }
    countOp += length;
    return length;
}

int Train::getOpCount() {
    return countOp;
}
