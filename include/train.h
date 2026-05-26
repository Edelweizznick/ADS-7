#ifndef TRAIN_H
#define TRAIN_H

class Train {
private:
  struct Car {
    bool light;
    Car *next;
    Car *prev;
  };

  Car *first = nullptr;
  int countOp = 0;

public:
  Train();
  ~Train();
  void addCar(bool light);
  int getLength();
  int getOpCount() const;
};

#endif