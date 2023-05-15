//
// Created by Daniel Engman on 2023-04-16.
//

#include "dataGen.h"
#include <vector>
#include <algorithm>
#include <cstdlib>  // for rand, srand
#include <ctime>    // for time
#include <climits>  // for INT_MAX

std::vector<int> *randomValues(int numberOfValues) {
    std::vector<int> *randomValues = new std::vector<int>;
    for (int i = 0; i < numberOfValues; i++) {
        randomValues->push_back(rand());
    }
    return randomValues;
}

std::vector<int>* monotonicIncreasingValues(int numberOfValues) {
    std::vector<int>* monotonicIncreasingValues = new std::vector<int>;
    monotonicIncreasingValues->push_back(0);
    for (int i = 1; i < numberOfValues; i++) {
        monotonicIncreasingValues->push_back(rand() % 10 + monotonicIncreasingValues->at(i - 1));
    }
    return monotonicIncreasingValues;
}

std::vector<int>* monotonicDecreasingValues(int numberOfValues)
{
    std::vector<int>* monotonicDecreasing = new std::vector<int>;
    monotonicDecreasing->push_back(INT_MAX);
    for (int i = 1; i < numberOfValues; i++) {
        monotonicDecreasing->push_back(monotonicDecreasing->at(i-1) - (rand() % 10));
    }
    return monotonicDecreasing;
}

std::vector<int>* constantValue(int numberOfValues) {
    std::vector<int> *constantValue = new std::vector<int>;
    int value = rand();
    for (int i = 0; i < numberOfValues; i++) {
        constantValue->push_back(value);
    }
    return constantValue;
}