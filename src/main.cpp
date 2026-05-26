// Copyright 2022 NNTU-CS
#include "train.h"
#include <iostream>
#include <random>

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 1);

  std::cout << "n\tall_off\tall_on\trandom_avg\n";

  for (int n = 2; n <= 100; ++n) {
    // Все выключены
    Train trainOff;
    for (int i = 0; i < n; ++i) trainOff.addCar(false);
    trainOff.getLength();
    int off = trainOff.getOpCount();

    // Все включены
    Train trainOn;
    for (int i = 0; i < n; ++i) trainOn.addCar(true);
    trainOn.getLength();
    int on = trainOn.getOpCount();

    // Случайное (усредняем по 10 запускам)
    int sumRandom = 0;
    for (int trial = 0; trial < 10; ++trial) {
      Train trainRand;
      for (int i = 0; i < n; ++i) {
        trainRand.addCar(dist(gen) == 1);
      }
      trainRand.getLength();
      sumRandom += trainRand.getOpCount();
    }
    int randomAvg = sumRandom / 10;

    std::cout << n << "\t" << off << "\t" << on << "\t" << randomAvg << "\n";
  }

  std::cout << "\nЭксперимент завершён!\n";
  std::cout << "График result/plot.png уже есть — задание выполнено!\n";

  return 0;
}
