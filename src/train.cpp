#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* nc = new Car{light, nullptr, nullptr};
    if (first == nullptr) {
        first = nc;
        nc->next = nc;
        nc->prev = nc;
    } else {
        Car* last = first->prev;
        last->next = nc;
        nc->prev = last;
        nc->next = first;
        first->prev = nc;
    }
}

int Train::getOpCount() {
    return countOp;
}

int Train::getLength() {
    if (first == nullptr) return 0;
    
    countOp = 0;
    Car* base = first;
    if (!base->light) base->light = true;

    int candidate = 1;
    Car* pos = nullptr;

    while (true) {
        candidate++;
        pos = base;

        for (int i = 0; i < candidate; ++i) {
            pos = pos->next;
            countOp++;
        }

        bool wasOff = !pos->light;
        if (wasOff) {
            pos->light = true;
        }

        for (int i = 0; i < candidate; ++i) {
            pos = pos->prev;
            countOp++;
        }

        if (!wasOff) {
            return candidate;
        }
    }
}
