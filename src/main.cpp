#include "../include/definiciones.hpp"
#include "../include/sorts.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <functional>

void pasarArreglos(std::vector<std::vector<int>> &vector){
    std::ifstream archivo("arreglos.bin", std::ios::in | std::ios::binary);

    if(!archivo) throw std::runtime_error("No se pudo abrir el archivo");

    int numero_de_arreglos, largo_de_arreglos;
    archivo.read(reinterpret_cast<char*>(&numero_de_arreglos), sizeof(int));
    archivo.read(reinterpret_cast<char*>(&largo_de_arreglos), sizeof(int));

    for (int i = 0; i < numero_de_arreglos; i++) {
        std::vector<int> fila(largo_de_arreglos);
        archivo.read(reinterpret_cast<char*>(fila.data()), largo_de_arreglos * sizeof(int));
        vector.push_back(fila);
    }

    archivo.close();
}

void testeo(std::vector<std::vector<int>> &vector, 
    const std::function<void(std::vector<int>&)> sortFunction,
    const std::string &algoritmo){

    // Obtenemos el vector de vectores
    try {
        pasarArreglos(vector);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    
    // Variables para cuantificar el tiempo promedio
    double avg_time = 0, cantidad_elementos = 0, tamaño;

    // Ordenar los elementos
    for(auto&fila : vector){
        
        auto start = std::chrono::high_resolution_clock::now();
        
        sortFunction(fila);               
        
        auto end = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double, std::milli> duration = end - start;
        
        avg_time += duration.count(), cantidad_elementos++;
    }

    std::cout << "Tiempo de ejecucion promedio de " << algoritmo << ": " << avg_time / cantidad_elementos << "\n";
}

int main(){
    FunctionOptimization();

    std::vector<std::vector<int>> vector;
    
    testeo(vector, [](std::vector<int>& v) {MergeSort::sort(v);}, "MergeSort");
    testeo(vector, [](std::vector<int>& v) {InsertionSort::sort(v);}, "InsertionSort");
    testeo(vector, [](std::vector<int>& v) {HeapSort::sort(v);}, "HeapSort");
    testeo(vector, [](std::vector<int>& v) {QuickSort::sort(v);}, "QuickSort");

    /*
    Falta adaptar el main para que pase los vectores uno por uno a cada algoritmo,
    los que hay que modificar son los que estan sin comentar.

    pasarArreglos(vector);
    HeapSort::sort(vector);

    pasarArreglos(vector);
    QuickSort::sort(vector);
    */

    /*
    
    compilar: g++ -std=c++17 -Iinclude main.cpp heapSort.cpp insertionSort.cpp mergeSort.cpp quickSort.cpp -o main.out -O2
    
    */
    return 0;
}
