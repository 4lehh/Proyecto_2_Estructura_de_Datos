#include "../include/mergeSort.hpp"
#include "../include/insertionSort.hpp"
#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void functionOptimization(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
}

void pasarArreglos(std::vector<std::vector<int>> &vector){
    std::ifstream archivo("arreglos.txt");

    if(!archivo){
        std::cout << "Error al abrir el archivo";
        return;
    }

    std::string linea;
    while(std::getline(archivo, linea)){
        std::istringstream ss(linea);
        std::vector<int> fila;
        int numero;
        
        while(ss >> numero) fila.push_back(numero);
        vector.push_back(fila);
    }
}

int main(){
    functionOptimization();

    std::vector<std::vector<int>> vector;
    int tamaño = static_cast<int>(vector.size());
    pasarArreglos(vector);

    MergeSort m;
    m.sort(vector);
    InsertionSort i;
    pasarArreglos(vector);
    i.sort(vector);
}
