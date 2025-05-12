#pragma once 
#include <vector>

/**
 * @class MergeSort
 * @brief Representa la clase con el metodo de ordenamiento MergeSort
 */
class MergeSort{
    public:
        static void sort(std::vector<std::vector<int>>&);
        static void mergesort(std::vector<int>&,int,int);
        static void merge(std::vector<int>&,int,int,int);
        static void print(std::vector<std::vector<int>>&);
};
