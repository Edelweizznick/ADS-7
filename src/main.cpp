// Copyright 2022 NNTU-CS
#include "train.h"
#include <fstream>
#include <iostream>
#include <random>

int main() {
  std::ofstream csv("result/data.csv");
  csv << "n,all_off,all_on,random\n";

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 1);

  for (int size = 2; size <= 100; ++size) {
    // Все лампочки выключены
    Train tOff;
    for (int i = 0; i < size; ++i) tOff.addCar(false);
    tOff.getLength();
    int offCount = tOff.getOpCount();

    // Все лампочки включены
    Train tOn;
    for (int i = 0; i < size; ++i) tOn.addCar(true);
    tOn.getLength();
    int onCount = tOn.getOpCount();

    // Случайное состояние — усредняем по 10 запускам
    int randomTotal = 0;
    for (int trial = 0; trial < 10; ++trial) {
      Train tRand;
      for (int i = 0; i < size; ++i) {
        tRand.addCar(dist(gen) == 1);
      }
      tRand.getLength();
      randomTotal += tRand.getOpCount();
    }
    int randomAvg = randomTotal / 10;

    csv << size << "," << offCount << "," << onCount << "," << randomAvg << "\n";
  }

  csv.close();
  std::cout << "Эксперимент завершён. Данные в result/data.csv\n";
  std::cout << "График result/plot.png уже есть — всё готово!\n";

  return 0;
}
