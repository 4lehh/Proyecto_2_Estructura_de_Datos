#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

void randomGenerator(int numero_de_arreglos, int largo_de_arreglos, int dominio_numeros){
    
    std::ofstream archivo("arreglos.txt", std::ios::out | std::ios::trunc);

    if(!archivo){
        std::cout << "Error al abrir el archivo\n";
        return;
    }
    
    std::srand(std::time(0));

    for(int i = 0; i < numero_de_arreglos; i++){
        for(int j = 0 ; j < largo_de_arreglos; j++){
            archivo << rand() % dominio_numeros << " ";
        }
        archivo << "\n";
    }

    archivo.close();
}

void ascendingGenerator(int numero_de_arreglos, int largo_de_arreglos){
    
    std::ofstream archivo("arreglos.txt", std::ios::out | std::ios::trunc);

    if(!archivo){
        std::cout << "Error al abrir el archivo\n";
        return;
    }
    
    std::srand(std::time(0));

    for(int i = 0; i < numero_de_arreglos; i++){
        for(int j = 0 ; j < largo_de_arreglos; j++){
            archivo << j << " ";
        }
        archivo << "\n";
    }

    archivo.close();
}

void descendingGenerator(int numero_de_arreglos, int largo_de_arreglos){
    
    std::ofstream archivo("arreglos.txt", std::ios::out | std::ios::trunc);

    if(!archivo){
        std::cout << "Error al abrir el archivo\n";
        return;
    }
    
    std::srand(std::time(0));

    for(int i = 0; i < numero_de_arreglos; i++){
        for(int j = largo_de_arreglos ; j < 0; j--){
            archivo << j << " ";
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

    if(argc != 5){
        std::cout << argc << std::endl;
        std::cout << "Número de argumentos no valido.\n Deben ser 4 argumentos.\n";
        return 1;
    }

    int _numero_de_arreglos = std::stoi(argv[1]);
    int _largo_de_arreglos = std::stoi(argv[2]);
    int _dominio_numeros = std::stoi(argv[3]);
    int _forma_de_los_numeros = std::stoi(argv[4]);
     
    switch (_forma_de_los_numeros){
        case 1:
            randomGenerator(_numero_de_arreglos, _largo_de_arreglos, _dominio_numeros);
            break;
        case 2:
            ascendingGenerator(_numero_de_arreglos, _largo_de_arreglos);
            break;
        case 3:
            descendingGenerator(_numero_de_arreglos, _largo_de_arreglos);
            break;
        default:
            std::cerr << "Número de orden no valido\n";
            return 1;
    }

    return 0;
}
