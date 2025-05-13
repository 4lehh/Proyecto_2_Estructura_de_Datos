#include "../include/insertionSort.hpp"
#include <vector>
#include <iostream>
#include <chrono>

void InsertionSort::sort(std::vector<std::vector<int>> &vector){
    double avg_time = 0, cantidad_elementos = 0, tamaño;
    for(auto &fila : vector){
        tamaño = fila.size();
        
        auto start = std::chrono::high_resolution_clock::now();
        
        insertionSort(fila, tamaño);               
        
        auto end = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double, std::milli> duration = end - start;
        
        avg_time += duration.count(), cantidad_elementos++;
    }
    std::cout << "Tiempo de ejecucion promedio: " << avg_time / cantidad_elementos << "\n";
}

void InsertionSort::insertionSort(std::vector<int> &vector, int tamaño){
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

void InsertionSort::print(std::vector<std::vector<int>> &vector){
    for(const auto& fila : vector){
        for(int num : fila){
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}
