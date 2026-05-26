#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
    if (first == nullptr) return;
    Car* current = first->next;
    while (current != first) {
        Car* next = current->next;
        delete current;
        current = next;
    }
    delete first;
}

void Train::addCar(bool light) {
    Car* car = new Car{light, nullptr, nullptr};
    if (first == nullptr) {
        first = car;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = car;
        car->prev = last;
        car->next = first;
        first->prev = car;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;

    countOp = 0;
    Car* start = first;

    if (!start->light) {
        start->light = true;
        countOp++;
    }

    Car* current = start->next;
    countOp++;

    int length = 1;

    while (true) {
        if (current->light) {
            current = current->next;
            countOp++;

            if (current == start) {
                return length;
            } else {
                current = current->prev;
                countOp++;
            }
        }

        if (!current->light) {
            current->light = true;
            countOp++;
        }

        current = current->next;
        countOp++;
        length++;
    }
}

int Train::getOpCount() {
    return countOp;
}
