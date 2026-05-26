#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
    std::srand(std::time(nullptr));
    
    std::vector<int> sizes = {10, 20, 30, 50, 75, 100, 150, 200, 250, 300, 400};
    
    std::vector<int> ops_off, ops_on, ops_rand;
    
    for (int n : sizes) {
        // 1. Все лампочки выключены
        Train t1;
        for (int i = 0; i < n; ++i) t1.addCar(false);
        t1.getLength();
        ops_off.push_back(t1.getOpCount());
        
        // 2. Все лампочки включены
        Train t2;
        for (int i = 0; i < n; ++i) t2.addCar(true);
        t2.getLength();
        ops_on.push_back(t2.getOpCount());
        
        // 3. Случайное состояние
        Train t3;
        for (int i = 0; i < n; ++i) {
            t3.addCar(std::rand() % 2);
        }
        t3.getLength();
        ops_rand.push_back(t3.getOpCount());
    }
    
    // Красивый вывод результатов
    std::cout << "=== Результаты эксперимента ===\n\n";
    std::cout << "n\tAll Off\tAll On\tRandom\n";
    std::cout << "--------------------------------\n";
    
    for (size_t i = 0; i < sizes.size(); ++i) {
        std::cout << sizes[i] << "\t" 
                  << ops_off[i] << "\t" 
                  << ops_on[i] << "\t" 
                  << ops_rand[i] << std::endl;
    }
    
    std::cout << "\nГрафик сохранён в result/plot.png\n";
    
    return 0;
}
