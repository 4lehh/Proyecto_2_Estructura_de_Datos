#include "../include/mergeSort.hpp"
#include <iostream>
#include <vector>
#include <chrono>

// testeo
#define FR(arr,l) for(int i=0;i<l;i++) std::cout << arr[i] << " "; 

void MergeSort::sort(std::vector<std::vector<int>> &vector){
    double avg_time = 0, cantidad_elementos = 0;
    for(auto& fila : vector){ 
        int tamaño = static_cast<int>(fila.size());
        
        auto start = std::chrono::high_resolution_clock::now();
        
        mergesort(fila, 0, tamaño);
        
        auto end = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double, std::milli> duration = end - start;
        
        avg_time += duration.count(), cantidad_elementos++;
    }
    std::cout << "Tiempo promedio: " << avg_time / cantidad_elementos << "\n";
}

void MergeSort::mergesort(std::vector<int> &vector, int inicio, int fin){
    if (inicio >= fin) return;

    int _medio = (inicio + fin) / 2;

    mergesort(vector, inicio, _medio);
    mergesort(vector, _medio + 1, fin);
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

void MergeSort::print(std::vector<std::vector<int>> &vector){
    for(const auto& fila : vector){
        for(int i : fila) std::cout << i << " ";
        std::cout << "\n";
    }
}
