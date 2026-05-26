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
    base->light = true;

    int n = 1;
    while (true) {
        Car* p = base;
        for (int i = 0; i < n; ++i) {
            p = p->next;
            countOp++;
        }

        if (p->light) {
            return n;
        }

        p->light = true;

        for (int i = 0; i < n; ++i) {
            p = p->prev;
            countOp++;
        }
        n++;
    }
}
