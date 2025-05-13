#include "../include/heapSort.hpp"
#include <iostream>
#include <vector>
#include <chrono>

void HeapSort::heapsort(std::vector<int> &vector){
    for(int i = n / 2 + 1; i > 0; i--){
        
    }


};

void HeapSort::upheap(std::vector<int> &vector, int indice){
    while(indice > 0){
        int padre = (i - 1) / 2;
        if(vector[indice] < vector[padre]){
            swap(vector, indice, padre);
            indice = padre;
        }
    }
}

void HeapSort::downheap(std::vector<int> &vector, int tamaño, int indice){
    int hijo_izq = indice * 2, hijo_der = (indice * 2) + 1, largo = indice;

    if(hijo_izq > tamaño && vector[hijo_izq] < ) {
        std::cout << "Continuar\n";
    }
    
}

void InsertionSort::swap(std::vector<int> &vector, int indice_1, int indice_2){
    int aux = vector[indice_2];
    vector[indice_2] = vector[indice_1];
    vector[indice_1] = aux;
}
