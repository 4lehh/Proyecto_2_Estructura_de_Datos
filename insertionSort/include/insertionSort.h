#pragma once

class InsertionSort{
    private: 
        int* array;
        int length;
        void swap(int,int);
    public:
        InsertionSort(int*,int);
        void sort();
        void showSort();
};
