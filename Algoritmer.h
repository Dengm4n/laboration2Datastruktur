//
// Created by Daniel Engman on 2023-04-16.
//

#ifndef DOALABB2_ALGORITMER_H
#define DOALABB2_ALGORITMER_H


#include <iostream>
#include <vector>
#include <algorithm>

void insertionSort(std::vector<int>* vector);


void selectionSort(std::vector<int>* vector);


void quickSort(std::vector<int>* vector, int low, int high, bool median);


int partition(std::vector<int>* vector, int low, int high, bool median);


int medianPivot(int low, std::vector<int>* vector, int high);

#endif //DOALABB2_ALGORITMER_H
