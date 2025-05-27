#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

std::ofstream abrir_archivo(const std::string nombre_archivo, int numero_de_arreglos, int largo_de_arreglos) {
    std::ofstream archivo(nombre_archivo, std::ios::out | std::ios::trunc | std::ios::binary);
    // std::ios::out indica que el archivo se abrirá para escritura.
    // std::ios::trunc indica que el archivo se truncará a cero bytes si ya existe.
    // std::ios::binary indica que el archivo se abrirá en modo binario.

    if(!archivo){
        throw "Error al abrir el archivo\n";
    }

    archivo.write(reinterpret_cast<char*>(&numero_de_arreglos), sizeof(int));
    archivo.write(reinterpret_cast<char*>(&largo_de_arreglos), sizeof(int));

    return archivo;
}

void randomGenerator(int numero_de_arreglos, int largo_de_arreglos, int dominio_numeros, std::string nombre_archivo) {
    std::ofstream archivo;

    try {
        archivo = abrir_archivo(nombre_archivo, numero_de_arreglos, largo_de_arreglos);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return;
    }
    
    std::srand(std::time(0));

    for (int i = 0; i < numero_de_arreglos; i++) {
        for (int j = 0; j < largo_de_arreglos; j++) {
            int numero = rand() % dominio_numeros;
            archivo.write(reinterpret_cast<char*>(&numero), sizeof(int));
        }
    }

    archivo.close();
}

void ascendingGenerator(int numero_de_arreglos, int largo_de_arreglos, int dominio_numeros, std::string nombre_archivo) {
    std::ofstream archivo;

    try {
        archivo = abrir_archivo(nombre_archivo, numero_de_arreglos, largo_de_arreglos);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return;
    }

    for(int i = 0; i < numero_de_arreglos; i++){
        for(int j = 0 ; j < largo_de_arreglos; j++){
            archivo << j % dominio_numeros << " ";
        }
        archivo << "\n";
    }

    archivo.close();
}

void descendingGenerator(int numero_de_arreglos, int largo_de_arreglos, int dominio_numeros, std::string nombre_archivo) {
    std::ofstream archivo;

    try {
        archivo = abrir_archivo(nombre_archivo, numero_de_arreglos, largo_de_arreglos);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return;
    }


    for(int i = 0; i < numero_de_arreglos; i++){
        for(int j = largo_de_arreglos ; j < 0; j--){
            archivo << j % dominio_numeros << " ";
        }
        archivo << "\n";
    }

    archivo.close();
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
        std::cout << "Dominio de los Numeros fuera de rango" << std::endl;
        return 1;
    }

    std::string nombre_archivo = "arreglos.bin";
     
    switch (_forma_de_los_numeros){
        case 1:
            randomGenerator(_numero_de_arreglos, _largo_de_arreglos, _dominio_numeros, nombre_archivo);
            break;
        case 2:
            ascendingGenerator(_numero_de_arreglos, _largo_de_arreglos, _dominio_numeros, nombre_archivo);
            break;
        case 3:
            descendingGenerator(_numero_de_arreglos, _largo_de_arreglos, _dominio_numeros, nombre_archivo);
            break;
        default:
            std::cerr << "Número de orden no valido\n";
            return 1;
    }

    return 0;
}

// Compilación:
// g++ src/arrayGenerator.cpp -o arrayGenerator.out -Wall -O2