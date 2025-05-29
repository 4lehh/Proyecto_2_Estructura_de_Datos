#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <filesystem>   // Para manejar carpetas

#define NOMBRE_CARPETA "test/arrays"

void randomGenerator(const int numero_de_arreglos, const int largo_de_arreglos, const int dominio_numeros) {
    std::srand(std::time(0));

    std::string nombre_archivo_base = NOMBRE_CARPETA + std::string("/1_") + std::to_string(std::time(0));

    for(int i = 0; i < numero_de_arreglos; i++){
        std::string nombre_archivo = nombre_archivo_base + std::to_string(i) + ".bin";
        std::ofstream archivo(nombre_archivo, std::ios::out | std::ios::trunc | std::ios::binary);

        if(!archivo) throw "Error al abrir el archivo\n";

        for (int j = 0; j < largo_de_arreglos; j++) {
            int numero = rand() % dominio_numeros;
            archivo.write(reinterpret_cast<char*>(&numero), sizeof(int));
        }
        archivo.close();
    }
}

void ascendingGenerator(const int numero_de_arreglos, const int largo_de_arreglos, const int dominio_numeros) {
    std::string nombre_archivo_base = NOMBRE_CARPETA + std::string("/2_") + std::to_string(std::time(0));

    for(int i = 0; i < numero_de_arreglos; i++){
        std::string nombre_archivo = nombre_archivo_base + std::to_string(i) + ".bin";
        std::ofstream archivo(nombre_archivo, std::ios::out | std::ios::trunc | std::ios::binary);

        if(!archivo) throw "Error al abrir el archivo\n";

        for(int j = 0 ; j < largo_de_arreglos; j++) {
            int numero = j % dominio_numeros;
            archivo.write(reinterpret_cast<char*>(&numero), sizeof(int));
        }

        archivo.close();
    }

}

void descendingGenerator(const int numero_de_arreglos, const int largo_de_arreglos, const int dominio_numeros) {
    std::string nombre_archivo_base = NOMBRE_CARPETA + std::string("/3_") + std::to_string(std::time(0));
    
    for(int i = 0; i < numero_de_arreglos; i++){
        std::string nombre_archivo = nombre_archivo_base + std::to_string(i) + ".bin";
        std::ofstream archivo(nombre_archivo, std::ios::out | std::ios::trunc | std::ios::binary);

        if(!archivo) throw "Error al abrir el archivo\n";

        for(int j = largo_de_arreglos - 1 ; j >= 0; j--) {
            int numero = j % dominio_numeros;
            archivo.write(reinterpret_cast<char*>(&numero), sizeof(int));
        }

        archivo.close();
    }
}

int main(int argc, char* argv[]){
    
    /*
        Parametros son:
            1) número de arreglos
            2) largo de los arreglos
            3) dominio de los números
            4) forma de los números (random = 1, ascendente = 2, descendente = 3)
    */

    if (argc == 1) {
        std::cout << "Parametros son:\n\t1) número de arreglos\n\t2) largo de los arreglos\n\t3) dominio de los números\n\t4) forma de los números (random = 1, ascendente = 2, descendente = 3)" << std::endl;
        return 0;
    }

    if (argc != 5){
        std::cout << argc << std::endl;
        std::cout << "Número de argumentos no valido.\n Deben ser 4 argumentos.\n";
        return 1;
    }

    int _numero_de_arreglos = std::stoi(argv[1]);
    int _largo_de_arreglos = std::stoi(argv[2]);
    int _dominio_numeros = std::stoi(argv[3]);
    int _forma_de_los_numeros = std::stoi(argv[4]);

    if(_dominio_numeros <= 0) {
        std::cout << "Dominio de los Numeros fuera de rango." << std::endl;
        return 1;
    }

    if (!std::filesystem::exists(NOMBRE_CARPETA)) {
        if (std::filesystem::is_directory(NOMBRE_CARPETA)) {
            std::cout << "Ya existe un archivo que se llama: " << NOMBRE_CARPETA << std::endl;
            return 0;
        }
        else {
            if (!std::filesystem::create_directories(NOMBRE_CARPETA)) {
                std::cout << "No se pudo crear la carpeta..." << std::endl;
                return 1;
            }
        }
    }


    std::cout << _numero_de_arreglos << std::endl;

    switch (_forma_de_los_numeros){
        case 1:
            randomGenerator(_numero_de_arreglos, _largo_de_arreglos, _dominio_numeros);
            break;
        case 2:
            ascendingGenerator(_numero_de_arreglos, _largo_de_arreglos, _dominio_numeros);
            break;
        case 3:
            descendingGenerator(_numero_de_arreglos, _largo_de_arreglos, _dominio_numeros);
            break;
        default:
            std::cerr << "Número de orden no valido\n";
    }

    return 0;
}

// Compilación:
// g++ src/arrayGenerator.cpp -o arrayGenerator.out -Wall -O2
