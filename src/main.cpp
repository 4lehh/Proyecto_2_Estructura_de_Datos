#include "../include/definiciones.hpp"
#include "../include/sorts.hpp"
#include "../include/json.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <functional>
#include <algorithm>
#include <filesystem> // Para manejar las carpetas

#define NOMBRE_CARPETA_TESTS "test/arrays"
#define NOMBRE_CARPETA_JSON "test/json"

int numero_elementos_array = 0; // Ver el numero de elementos de un array

// Adaptador para std::sort
void adapterSort(std::vector<int>& vector){
    std::sort(vector.begin(), vector.end());
}

std::string obtenerNombreOrden(const std::string& nombre_archivo) {
    std::filesystem::path p(nombre_archivo);
    std::string nombre_archivo_nuevo = p.filename().string();

    size_t pos = nombre_archivo_nuevo.find('_');
    if (pos != std::string::npos) {
        return nombre_archivo_nuevo.substr(0, pos);
    } else {
        return nombre_archivo_nuevo; // No encontró '_', devuelve todo
    }
}


void guardarJson(nlohmann::json &resultados, std::string &orden){
    try {
        if (!std::filesystem::exists(NOMBRE_CARPETA_JSON)) {
            if(!std::filesystem::create_directory(NOMBRE_CARPETA_JSON)){
                throw std::runtime_error("La carpeta no pudo ser creada: " + std::string(NOMBRE_CARPETA_JSON));
            }
        }

        if (!std::filesystem::is_directory(NOMBRE_CARPETA_JSON)) {
            throw std::runtime_error("La ruta no es una carpeta: " + std::string(NOMBRE_CARPETA_JSON));
        }
        
        std::ostringstream nombre_archivo_test;
        nombre_archivo_test << NOMBRE_CARPETA_JSON << "/resultados_" << std::string(orden) << "_" << numero_elementos_array << ".json";

        // std::string nombre_archivo_test = std::format("{}{}{}{}", NOMBRE_CARPETA_JSON, "/resultados", resultados.size(), ".json");
        // std::string nombre_archivo_test = NOMBRE_CARPETA_JSON + std::string("/resultados") + std::string(tamaño) + std::string(".json");
        std::ofstream salida(nombre_archivo_test.str());
        
        if (!salida) {
            std::cerr << "Error al crear el archivo!" << std::endl;
            return;
        }

        salida << resultados.dump(4); // Guardamos el JSON con indentación
        salida.close();

    } catch(const std::exception &e){
        std::cerr << "Error al buscaar el archivos: " << e.what() << std::endl;
    }
}

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

double testeo(
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

    if(!numero_elementos_array) numero_elementos_array = numero_de_enteros;
    
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

    // std::cout << VERDE "Tiempo de ejecucion de " << algoritmo << ": "
    //          << duration.count()  << "ms\n"<<  RESET_COLOR;

    if (!isSorted(numeros)) {
        std::cerr << ROJO "Error: El arreglo no está ordenado correctamente.\n" 
                    << "Algoritmo: " << algoritmo << RESET_COLOR "\n";
    }

    return duration.count();
}

int main(){
    FunctionOptimization();

    
    // Vector de algoritmos a probar
    std::vector<std::pair<std::string, void(*)(vc&)>> algoritmos = {
        {"HeapSort", HeapSort::sort},
        {"InsertionSort", InsertionSort::sort},
        {"MergeSort", MergeSort::sort},
        {"QuickSort", QuickSort::sort},
        {"Sort C++", adapterSort}
    };

    std::vector<std::string> nombres_archivos = archivosEnCarpeta();
    
    nlohmann::json resultados;
    std::string orden = obtenerNombreOrden(nombres_archivos[0]);

    for (auto nombre_archivo : nombres_archivos) {
        // std::cout << "Testeando el archivo: " << nombre_archivo << std::endl;
        for (const auto &[nombre_funcion, funcion] : algoritmos) {
            try {
                // Almacenar los resultados
                resultados[nombre_archivo][nombre_funcion] = testeo(nombre_archivo, funcion, nombre_funcion);
            }
            catch(const std::exception& e) {
                std::cerr << e.what() << '\n';
                return 1;
            }
        }

        // std::cout << std::endl;
    }
    
    guardarJson(resultados, orden);
    /*
    compilar: g++ -I include main.cpp heapSort.cpp insertionSort.cpp mergeSort.cpp quickSort.cpp -o main.out -O2
    */
    return 0;
}
