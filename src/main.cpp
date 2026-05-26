// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <random>
#include "train.h"

int main() {
  std::ofstream dataFile("data.csv");
  dataFile << "n,all_off,all_on,random\n";

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 1);

  for (int n = 2; n <= 160; n += 2) {
    Train trainOff;
    for (int i = 0; i < n; i++) trainOff.addCar(false);
    trainOff.getLength();
    int opsOff = trainOff.getOpCount();

    Train trainOn;
    for (int i = 0; i < n; i++) trainOn.addCar(true);
    trainOn.getLength();
    int opsOn = trainOn.getOpCount();

    int randomSum = 0;
    const int trials = 12;
    for (int t = 0; t < trials; t++) {
      Train trainRand;
      for (int i = 0; i < n; i++) {
        trainRand.addCar(dis(gen) == 1);
      }
      trainRand.getLength();
      randomSum += trainRand.getOpCount();
    }
    int opsRandom = randomSum / trials;

    dataFile << n << "," << opsOff << "," << opsOn << "," << opsRandom << "\n";
  }

  dataFile.close();
  std::cout << "Эксперимент завершён. Данные сохранены в data.csv (в корне проекта)\n";
  return 0;
}
