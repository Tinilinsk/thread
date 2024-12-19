#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include "DataProcessor.h"


void generatorTabeli(std::vector<int> &k) {
    for (int i = 0; i < 1000000; i++) {
        int randomNum = rand() % 11;
        k.push_back(randomNum);
    }
}

void inputRanges(std::vector<DataProcessor>& processors, const std::vector<int>& table, int numRanges) {
    for (int i = 0; i < numRanges; i++) {
        int start, end;
        /*std::cout << "Wprowadz poczatek i koniec zakresu strumienia " << i + 1 << ": ";
        std::cin >> start >> end;
        */

        start = rand() % 1000000;
        end = rand() % 1000000 + start;
        if (start < 0 || end >= table.size() || start > end) {
            std::cerr << "Blad: nieprawidlowy zakres! Sprobuj ponownie.\n";
            i--;
            continue;
        }

        processors.emplace_back(table, start, end);
    } 
}

void runThreads(std::vector<DataProcessor>& processors, std::vector<std::thread>& threads) {
    for (auto& processor : processors) {
        threads.emplace_back(&DataProcessor::process, &processor);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void joinThread(std::vector<std::thread>& thr) {
    for (auto& t : thr) {
        t.join();
    }
}

int calculateTotalSum(const std::vector<DataProcessor>& processors) {
    int totalSum = 0;
    for (const auto& processor : processors) {
        totalSum += processor.getResult();
    }
    return totalSum;
}

int main()
{
    srand(time(0));
    std::vector<int> k;
    int partsTabeli;
    generatorTabeli(k);

    std::cout << "Enter the number of ranges\n";
    std::cin >> partsTabeli;

    std::vector<DataProcessor> processors;
    std::vector<std::thread> readerThreads;

    inputRanges(processors, k, partsTabeli);

    runThreads(processors, readerThreads);
    
    joinThread(readerThreads);

    int totalSum = calculateTotalSum(processors);

    std::cout << "Summa: " << totalSum << "\n";

    return 0;
}

