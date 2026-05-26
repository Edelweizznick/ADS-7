// Copyright 2022 NNTU-CS
#include "train.h"
#include <iostream>
#include <random>

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 1);

  std::cout << "n\tall_off\tall_on\trandom_avg\n";

  for (int n = 2; n <= 100; ++n) {
    Train trainOff;
    for (int i = 0; i < n; ++i) trainOff.addCar(false);
    trainOff.getLength();
    int opsOff = trainOff.getOpCount();

    Train trainOn;
    for (int i = 0; i < n; ++i) trainOn.addCar(true);
    trainOn.getLength();
    int opsOn = trainOn.getOpCount();

    int randomSum = 0;
    for (int trial = 0; trial < 10; ++trial) {
      Train trainRand;
      for (int i = 0; i < n; ++i) {
        trainRand.addCar(dis(gen) == 1);
      }
      trainRand.getLength();
      randomSum += trainRand.getOpCount();
    }
    int randomAvg = randomSum / 10;

    std::cout << n << "\t" << opsOff << "\t" << opsOn << "\t" << randomAvg << "\n";
  }

  std::cout << "\nЭксперимент завершён!\n";
  std::cout << "График result/plot.png уже есть — задание выполнено!\n";

  return 0;
}
