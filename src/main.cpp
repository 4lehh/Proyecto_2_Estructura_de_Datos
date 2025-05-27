#include "../include/definiciones.hpp"
#include "../include/sorts.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <functional>
#include <algorithm>

/**
 * @brief Función para verificar si un vector está ordenado.
 * 
 * @param arr El vector a verificar.
 * @return true Si el vector está ordenado.
 * @return false Si el vector no está ordenado.
 */
bool isSorted(const vc &vector) {
    return std::is_sorted(vector.begin(), vector.end());
}

void testeo(
        const std::string &nombre_archivo, 
        const std::function<void(std::vector<int>&)> &sortFunction,
        const std::string &algoritmo
    ){

    std::ifstream archivo(nombre_archivo, std::ios::in | std::ios::binary);
    if(!archivo) throw std::runtime_error(ROJO "No se pudo abrir el archivo" RESET_COLOR);

    int numero_de_arreglos, largo_de_arreglos;
    archivo.read(reinterpret_cast<char*>(&numero_de_arreglos), sizeof(int));
    archivo.read(reinterpret_cast<char*>(&largo_de_arreglos), sizeof(int));

    std::vector<int> fila(largo_de_arreglos);
    double avg_time = 0.0;

    for (int i = 0; i < numero_de_arreglos; i++) {
        archivo.read(reinterpret_cast<char*>(fila.data()), largo_de_arreglos * sizeof(int));

        auto start = std::chrono::high_resolution_clock::now();
        
        sortFunction(fila);
        
        auto end = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double, std::milli> duration = end - start;

        avg_time += duration.count();

        if (!isSorted(fila)) {
            std::cerr << ROJO "Error: El arreglo no está ordenado correctamente.\n" 
                      << "Algoritmo: " << algoritmo << RESET_COLOR "\n";
            archivo.close();
            return;
        }
    }

    archivo.close();

    std::cout << VERDE "Tiempo de ejecucion promedio de " << algoritmo << ": "
              << avg_time / (double)numero_de_arreglos << RESET_COLOR "\n";
}

int main(){
    FunctionOptimization();

    std::vector<std::vector<int>> vector;

    std::string nombre_archivo = "arreglos.bin";

    // Vector de algoritmos a probar
    std::vector<std::pair<std::string, void(*)(vc&)>> algoritmos = {
        {"HeapSort", HeapSort::sort},
        {"InsertionSort", InsertionSort::sort},
        {"MergeSort", MergeSort::sort},
        {"QuickSort", QuickSort::sort}
    };

    for (const auto &[nombre, funcion] : algoritmos) {
        testeo(nombre_archivo, funcion, nombre);
    }

    /*
    compilar: g++ -I include main.cpp heapSort.cpp insertionSort.cpp mergeSort.cpp quickSort.cpp -o main.out -O2
    */
    return 0;
}
