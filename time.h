//
// Created by Daniel Engman on 2023-05-04.
//

#ifndef DOALABB2_TIME_H
#define DOALABB2_TIME_H
#include <iostream>
#include <chrono>
#include <vector>
#include "Algoritmer.h"
#include "dataGen.h"

void timeAll(std::vector<int>* (*generateDataFunction)(int size), int start, int end, int increment);
void timeCalc(void(*sortingFunction)(std::vector<int>*), std::vector<int>* vectorToSort, std::string filename);
float time(void(*sortingFunction)(std::vector<int>*), std::vector<int>* vectorToSort);
void setHeader(std::vector<std::string> filename);



#endif //DOALABB2_TIME_H
