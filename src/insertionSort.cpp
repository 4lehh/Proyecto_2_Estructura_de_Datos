#include "../include/insertionSort.hpp"
#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>

void InsertionSort::sort(std::vector<int> &vector){
    int tamaño = vector.size();
    
    for(int i = 0; i < tamaño; i++){
        for(int j = i + 1; j < tamaño; j++){
            if(vector[i] > vector[j]) std::swap(vector[i], vector[j]);
        }
    }
}
