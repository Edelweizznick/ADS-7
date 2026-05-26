// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
    std::srand(std::time(nullptr));
    
    std::cout << "=== Вычислительный эксперимент: Circular Train ===\n\n";
    
    std::vector<int> sizes = {10, 50, 100, 150, 200, 250, 300, 400, 500};
    
    std::ofstream data("result/data.txt");
    if (data.is_open()) {
        data << "n AllOff AllOn Random\n";
    }
    
    std::cout << std::setw(6) << "n"
              << std::setw(12) << "All Off"
              << std::setw(12) << "All On"
              << std::setw(12) << "Random" << "\n";
    
    for (int n : sizes) {
        long long off = 0, on = 0, rnd = 0;
        
        // Все выключены
        {
            Train t;
            for (int i = 0; i < n; ++i) t.addCar(false);
            t.getLength();
            off = t.getOpCount();
        }
        
        // Все включены
        {
            Train t;
            for (int i = 0; i < n; ++i) t.addCar(true);
            t.getLength();
            on = t.getOpCount();
        }
        
        // Случайное состояние
        {
            Train t;
            for (int i = 0; i < n; ++i) t.addCar(rand() % 2);
            t.getLength();
            rnd = t.getOpCount();
        }
        
        std::cout << std::setw(6) << n
                  << std::setw(12) << off
                  << std::setw(12) << on
                  << std::setw(12) << rnd << "\n";
        
        if (data.is_open()) {
            data << n << " " << off << " " << on << " " << rnd << "\n";
        }
    }
    
    std::cout << "\nЭксперимент завершён!\n";
    std::cout << "Данные сохранены в result/data.txt\n";
    std::cout << "График сохранён в result/plot.png\n";
    
    return 0;
}
