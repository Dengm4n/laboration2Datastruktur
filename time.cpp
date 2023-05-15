//
// Created by Daniel Engman on 2023-05-04.
//

#include "time.h"
#include <fstream>

void timeAll(std::vector<int>* (*generateDataFunk)(int size), int start, int end, int increment){
    std::vector<std::string> filenames = {"insertionSort.data", "selectionSort.data", "quickSort.data", "quickSortMedian.data","stdSort.data"};
    setHeader(filenames);
    auto quickSorting = [](std::vector<int>* vectorToSort){quickSort(vectorToSort, 0, vectorToSort->size()-1,false);};
    auto quickSortingMedian = [](std::vector<int>* vectorToSort){quickSort(vectorToSort, 0, vectorToSort->size()-1,true);};
    auto stdSorting = [](std::vector<int>* vectorToSort){std::sort(vectorToSort->begin(), vectorToSort->end());};
    for (int i = start; i <= end; i+=increment) {
        std::vector<int>* vectorToSort = generateDataFunk(i);
        timeCalc(insertionSort, vectorToSort, filenames[0]);
        timeCalc(selectionSort, vectorToSort, filenames[1]);
        timeCalc(quickSorting, vectorToSort, filenames[2]);
        timeCalc(quickSortingMedian, vectorToSort, filenames[3]);
        timeCalc(stdSorting, vectorToSort, filenames[4]);
        delete vectorToSort;
    }
}

void timeCalc(void(*sortingFunction)(std::vector<int>*), std::vector<int>* vectorToSort, std::string filename){
    double samples = 5;
    double squareTime = 0;
    double totalTime = 0;
    double avgTime;
    double stdDev;
    double dif_time;

    for (int i = 0; i < samples; i++)
    {
        std::vector<int>* vectorToSortCopy = new std::vector<int>(*vectorToSort);
        auto current_time = time(sortingFunction, vectorToSortCopy);
        totalTime += current_time;
        squareTime += pow(current_time, 2);
        delete vectorToSortCopy;
    }

    avgTime = totalTime / samples;
    dif_time = pow(totalTime, 2) / samples;
    stdDev = sqrt((squareTime - dif_time) / (samples - 1));



    std::ofstream outfile(filename, std::ios_base::app);
    std::string output = std::to_string(vectorToSort->size()) + "\t" + std::to_string(avgTime) + "\t" + std::to_string(stdDev) + "\t#" + std::to_string(samples) + "\n";
    outfile << output;
    outfile.close();
}

float time(void(*sortingFunction)(std::vector<int>*), std::vector<int>* vectorToSort){
    std::chrono::duration<double, std::milli> time(0);


    auto start = std::chrono::steady_clock::now();
    sortingFunction(vectorToSort);
    auto end_time = std::chrono::steady_clock::now();

    time = end_time - start;
    return time.count();
}

void setHeader(std::vector<std::string> fileNames) {
    std::ofstream myfile;
    for (int i = 0; i < fileNames.size(); i++) {
        myfile.open(fileNames.at(i), std::ios::out | std::ios::trunc);
        if (myfile.is_open()) {
            myfile << "#"+fileNames.at(i).erase(fileNames.at(i).size()-5, 5) << "\n" << "#N\tT[ms]\t\tStdev[ms]\tSamples\n";
        }
        myfile.close();
    }
}
