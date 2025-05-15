#pragma once
#include <vector>

class InsertionSort{
    private:
        static void swap(std::vector<int>&,int,int);
        static void insertionSort(std::vector<int>&,int);
        
    public:
        static void sort(std::vector<std::vector<int>>&);
        static void print(std::vector<std::vector<int>>&);
};
