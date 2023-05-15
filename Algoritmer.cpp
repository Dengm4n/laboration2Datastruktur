
#include "algoritmer.h"
#include <iostream>
#include <chrono>
int medianPivot(int low, std::vector<int>* vector, int high) {
    //Get middle index
    int mid = (low + high) / 2;
    if (vector->at(mid) < vector->at(low))
        std::swap(vector->at(low), vector->at(mid));
    if (vector->at(high) < vector->at(low))
        std::swap(vector->at(low), vector->at(high));
    if (vector->at(mid) < vector->at(high))
        std::swap(vector->at(mid), vector->at(high));
    //This swaps the median to list[high] which we then use to pivot
    return vector->at(high);
}
void insertionSort(std::vector<int>* vector)
{
    int index, key;
    for (int i = 1; i < vector->size(); i++)
    {
        key = vector->at(i);
        index = i - 1;

        //If value at index is bigger than key
        //set next index value to current index value
        while (index >= 0 && vector->at(index) > key)
        {
            vector->at(index+1.0) = vector->at(index);
            index = index - 1;
        }
        //Set the previous index to key value
        vector->at(index+1.0) = key;
    }
}
void quickSort(std::vector<int>* vector, int low, int high, bool median)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(vector, low, high, median);

        // Separately sort elements before
        // partition and after partition
        quickSort(vector, low, pi - 1, median);
        quickSort(vector, pi + 1, high, median);
    }
}
int partition(std::vector<int>* vector, int low, int high, bool median)
{
    int pivot;
    if (median)
        pivot = medianPivot(low, vector, high); // median-of-three pivot
    else
        pivot = vector->at(high); // right side pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (vector->at(j) < pivot)
        {
            i++; // increment index of smaller element
            std::swap(vector->at(i), vector->at(j));
        }
    }
    std::swap(vector->at(i+1.0), vector->at(high));
    return (i + 1);
}
void selectionSort(std::vector<int>* vector)
{
    int min_index;
    int compareindex;
    for (int i = 0; i < vector->size() - 1; i++)
    {
        min_index = i;
        for (compareindex = i + 1; compareindex < vector->size(); compareindex++)
        {
            //If compare value is smaller than min, set min to compare value
            if (vector->at(compareindex) < vector->at(min_index))
            {
                min_index = compareindex;
            }
        }
        //swap current index with min index, so min index is leftmost element
        std::swap(vector->at(i), vector->at(min_index));
    }
}