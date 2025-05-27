#include "../include/insertionSort.hpp"
#include <algorithm> // Para std::upper_bound

void InsertionSort::sort(vc& vector){
    int tamaño = vector.size();
    
    for(int i = 1; i < tamaño; i++){
        int nuevo_elemento = vector[i];

        int poscicion_insercion = std::upper_bound(vector.begin(), vector.begin() + i, nuevo_elemento) - vector.begin();

        // Desplazar elementos hacia la derecha
        for (int j = i; j > poscicion_insercion; j--) vector[j] = vector[j - 1];

        vector[poscicion_insercion] = nuevo_elemento;
    }
}
