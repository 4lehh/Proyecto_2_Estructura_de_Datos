#include "../include/insertionSort.hpp"
#include <vector>
#include <iostream>
#include <chrono>

void InsertionSort::sort(std::vector<int> &vector){
    int tamaño = vector.size();
    
    for(int i = 0; i < tamaño; i++){
        for(int j = i + 1; j < tamaño; j++){
            if(vector[i] > vector[j]) swap(vector, i, j);
        }
    }
}

void InsertionSort::swap(std::vector<int> &vector, int indice_1, int indice_2){
    int aux = vector[indice_2];
    vector[indice_2] = vector[indice_1];
    vector[indice_1] = aux;
}