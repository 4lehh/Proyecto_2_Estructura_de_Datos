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
#include <filesystem> // Para manejar las carpetas

#define NOMBRE_CARPETA_TESTS "test"

std::vector<std::string> archivosEnCarpeta() {
    std::vector<std::string> nombres_archivos;

    try {
        if (!std::filesystem::exists(NOMBRE_CARPETA_TESTS)) {
            throw std::runtime_error("La carpeta no existe: " + std::string(NOMBRE_CARPETA_TESTS));
        }

        if (!std::filesystem::is_directory(NOMBRE_CARPETA_TESTS)) {
            throw std::runtime_error("La ruta no es una carpeta: " + std::string(NOMBRE_CARPETA_TESTS));
        }

        for (const auto &entrada : std::filesystem::directory_iterator(NOMBRE_CARPETA_TESTS)) {
            if (std::filesystem::is_regular_file(entrada)) {
                if (entrada.path().extension() == ".bin") {
                    nombres_archivos.push_back(NOMBRE_CARPETA_TESTS + std::string("/") +  entrada.path().filename().string());
                }
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error al listar archivos: " << e.what() << std::endl;
        return {}; // Vector vacio
    }

    return nombres_archivos;
}

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
    std::ifstream archivo(nombre_archivo, std::ios::in | std::ios::binary); // Abrir en modo binario

    if(!archivo) throw std::runtime_error(ROJO "No se pudo abrir el archivo: " AMARILLO + nombre_archivo + RESET_COLOR);

    // Mover el puntero al final para determinar el tamaño del archivo
    archivo.seekg(0, std::ios::end);
    std::streamsize tamaño_archivo = archivo.tellg();
    archivo.seekg(0, std::ios::beg);

    if (tamaño_archivo % sizeof(int) != 0) throw std::runtime_error(ROJO "El archivo no parece contener enteros válidos." RESET_COLOR);

    size_t numero_de_enteros = tamaño_archivo / sizeof(int);
    std::vector<int> numeros(numero_de_enteros);

    // Leer todos los números
    archivo.read(reinterpret_cast<char*>(numeros.data()), tamaño_archivo);

    if (!archivo) throw std::runtime_error(ROJO "Error al leer el archivo completo." RESET_COLOR);

    archivo.close();

    // Ejecucion de Algoritmo
    auto start = std::chrono::high_resolution_clock::now();
    
    sortFunction(numeros);
    
    auto end = std::chrono::high_resolution_clock::now();

    // FIn Algoritmo
    
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << VERDE "Tiempo de ejecucion de " << algoritmo << ": "
              << duration.count()  << RESET_COLOR "\n";

    if (!isSorted(numeros)) {
        std::cerr << ROJO "Error: El arreglo no está ordenado correctamente.\n" 
                    << "Algoritmo: " << algoritmo << RESET_COLOR "\n";
    }
}

int main(){
    FunctionOptimization();

    
    // Vector de algoritmos a probar
    std::vector<std::pair<std::string, void(*)(vc&)>> algoritmos = {
        {"HeapSort", HeapSort::sort},
        {"InsertionSort", InsertionSort::sort},
        {"MergeSort", MergeSort::sort},
        {"QuickSort", QuickSort::sort}
    };

    std::vector<std::string> nombres_archivos = archivosEnCarpeta();

    for (auto nombre_archivo : nombres_archivos) {
        std::cout << "Testeando el archivo: " << nombre_archivo << std::endl;

        for (const auto &[nombre_funcion, funcion] : algoritmos) {
            try {
                testeo(nombre_archivo, funcion, nombre_funcion);
            }
            catch(const std::exception& e) {
                std::cerr << e.what() << '\n';
                return 1;
            }
        }

        std::cout << std::endl;
    }

    /*
    compilar: g++ -I include main.cpp heapSort.cpp insertionSort.cpp mergeSort.cpp quickSort.cpp -o main.out -O2
    */
    return 0;
}
