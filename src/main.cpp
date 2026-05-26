#include "train.h"
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <iomanip>

int main() {
  std::ofstream csv("result/data.csv");
  if (csv.is_open()) {
    csv << "n,all_off,all_on,random\n";
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::bernoulli_distribution d(0.5);

  for(int len = 2; len <= 50; len += 2) {  // до 50, O(n^2) ~ 2500 ops max
    // All off
    Train t_off;
    for(int i = 0; i < len; ++i) t_off.addCar(false);
    t_off.getLength();
    int ops_off = t_off.getOpCount();

    // All on
    Train t_on;
    for(int i = 0; i < len; ++i) t_on.addCar(true);
    t_on.getLength();
    int ops_on = t_on.getOpCount();

    // Random
    Train t_rand;
    for(int i = 0; i < len; ++i) t_rand.addCar(d(gen));
    t_rand.getLength();
    int ops_rand = t_rand.getOpCount();

    std::cout << "n = " << std::setw(3) << len 
              << " | off: " << std::setw(6) << ops_off
              << " | on: " << std::setw(6) << ops_on
              << " | rand: " << std::setw(6) << ops_rand << std::endl;

    if (csv.is_open()) {
      csv << len << "," << ops_off << "," << ops_on << "," << ops_rand << "\n";
    }
  }

  std::cout << "\nДанные сохранены в result/data.csv\n";
  std::cout << "Теперь создай result/plot.png с помощью Python (matplotlib) или Excel:\n";
  std::cout << " - X: n\n";
  std::cout << " - Y: 3 кривых (all_off, all_on, random)\n";
  std::cout << " - Добавь линии тренда (полином 2-й степени)\n";
  std::cout << "Задание выполнено!\n";

  return 0;
}