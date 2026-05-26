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

    if (!base->light) {
        base->light = true;
        countOp++;
    }

    int dist = 1;

    while (true) {
        Car* current = base;

        for (int i = 0; i < dist; ++i) {
            current = current->next;
            countOp++;
        }

        bool was_on = current->light;
        current->light = false;
        countOp++;

        for (int i = 0; i < dist; ++i) {
            current = current->prev;
            countOp++;
        }

        if (!base->light) {
            base->light = true;
            return dist;
        }

        if (was_on) {
            current->light = true;
        }

        dist++;
    }
}
