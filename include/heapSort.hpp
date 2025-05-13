#pragma once
#include <vector>

class HeapSort{
    private:
        static void downheap(std::vector<int>&,int,int);
        static void upheap(std::vector<int>&,int);
    public: 
        static void heapsort(std::vector<std::vector<int>>&);
        static void print(std::vector<std::vector<int>>&);
};
