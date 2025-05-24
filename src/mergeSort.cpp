#include "../include/mergeSort.hpp"
#include <iostream>
#include <vector>
#include <chrono>

void MergeSort::sort(std::vector<int>& vector) {
    if (vector.empty()) return;
    sort(vector, 0, vector.size() - 1);
}


void MergeSort::sort(std::vector<int> &vector, int inicio, int fin){
    if (inicio >= fin) return;

    int _medio = (inicio + fin) / 2;

    sort(vector, inicio, _medio);
    sort(vector, _medio + 1, fin);
    merge(vector, inicio, _medio, fin);
}

void MergeSort::merge(std::vector<int> &vector, int inicio, int medio, int fin){
    std::vector<int> _array_1(medio - inicio + 1), _array_2(fin - medio);
    
    // copias
    for(int i = 0; i < medio - inicio + 1; i++) _array_1[i] = vector[inicio + i];
    for(int i = 0; i < fin - medio; i++) _array_2[i] = vector[medio + 1 + i];
    
    // Comparacion 
    int _i = 0, _j = 0, _k = inicio;
    while(_i < medio - inicio + 1 && _j < fin - medio){
        if(_array_1[_i] <= _array_2[_j]) vector[_k] = _array_1[_i++];
        else vector[_k] = _array_2[_j++];
        _k++;
    }
    
    // Elementos sobrantes
    while(_i < medio - inicio + 1) vector[_k++] = _array_1[_i++];
    while(_j < fin - medio) vector[_k++] = _array_2[_j++];
}
