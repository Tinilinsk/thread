#include <iostream>
#include <random>
#include <thread>
#include "DataProcessor.h"

void generatorTabeli(std::vector<int> &k) {
    for (int i = 0; i < 1000000; i++) {
        int randomNum = rand() % 11;
        k.push_back(randomNum);
    }
}

int main()
{
    srand(time(0));
    std::vector<int> k;

    generatorTabeli(k);

    DataProcessor d1(k, 2, 1000);
    DataProcessor d2(k, 234, 2643);
    DataProcessor d3(k, 1, 100);
    DataProcessor d4(k, 6453, 100000);

    std::thread p1(&DataProcessor::process, &d1);
    std::thread p2(&DataProcessor::process, &d2);
    std::thread p3(&DataProcessor::process, &d3);
    std::thread p4(&DataProcessor::process, &d4);
    p1.join();
    p2.join();
    p3.join();
    p4.join();
    std::cout << "Total sum: " << d1.getResult()+ d2.getResult() + d3.getResult() + d4.getResult() << "\n";

    return 0;
}

