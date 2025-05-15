#include "../include/definiciones.hpp"
#include "../include/sorts.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void pasarArreglos(std::vector<std::vector<int>> &vector){
    std::ifstream archivo("arreglos.txt");

    if(!archivo) throw std::runtime_error("No se pudo abrir el archivo");

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
    FunctionOptimization();

    std::vector<std::vector<int>> vector;

    try {
        pasarArreglos(vector);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    MergeSort::sort(vector);

    try {
        pasarArreglos(vector);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    InsertionSort::sort(vector);

    /*
    Falta adaptar el main para que pase los vectores uno por uno a cada algoritmo,
    los que hay que modificar son los que estan sin comentar.

    pasarArreglos(vector);
    HeapSort::sort(vector);

    pasarArreglos(vector);
    QuickSort::sort(vector);
    */

    return 0;
}
