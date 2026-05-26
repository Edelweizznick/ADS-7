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
    
    first->light = true;
    
    Car *current = first->next;
    int length = 1;
    countOp++;
    
    while (current->light != true) {
        current->light = false;
        current = current->next;
        length++;
        countOp++;
    }
    
    return length;
}

int Train::getOpCount() {
    return countOp;
}
