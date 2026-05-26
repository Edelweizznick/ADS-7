// Copyright 2026 NNTU-CS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
    std::srand(std::time(nullptr));
    std::ofstream outFile("result/data.csv");
    outFile << "n,ops_all_off,ops_all_on,ops_random" << std::endl;
    for (int n = 10; n <= 500; n += 10) {
        int ops_off, ops_on, ops_random;
        {
            Train train;
            for (int i = 0; i < n; i++) train.addCar(false);
            train.getLength();
            ops_off = train.getOpCount();
        }
        {
            Train train;
            for (int i = 0; i < n; i++) train.addCar(true);
            train.getLength();
            ops_on = train.getOpCount();
        }
        {
            Train train;
            for (int i = 0; i < n; i++)
                train.addCar(std::rand() % 2);
            train.getLength();
            ops_random = train.getOpCount();
        }
        outFile << n << "," << ops_off << ","
                << ops_on << "," << ops_random << std::endl;
    }
    outFile.close();
    return 0;
}
