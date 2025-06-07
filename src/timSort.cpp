#include "../include/timSort.hpp"
#include <algorithm>

#define MIN_SIZE_TIMSORT 32 

void TimSort::sort(vc& vector){
    if(vector.size() == 0) return;
    timsort(vector, 0, vector.size() - 1);
}

void TimSort::timsort(vc& vector, int inicio, int fin){
    if(fin - inicio <= MIN_SIZE_TIMSORT){
        insertionsort(vector, inicio, fin);
        return;
    }

    int medio = (inicio + fin) / 2;
    timsort(vector, inicio, medio);
    timsort(vector, medio + 1, fin);
    merge(vector, inicio, medio, fin);
}

void TimSort::insertionsort(vc& vector, int min, int max) {
    for (int i = min + 1; i <= max; i++) {
        int nuevo_elemento = vector[i];
        int j = i - 1;

        while (j >= min && vector[j] > nuevo_elemento) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = nuevo_elemento;
    }
}

void TimSort::merge(vc& vector, int inicio, int medio, int fin){
    vc vc_left(medio - inicio + 1), vc_right(fin - medio);
    
    // copias
    for(int i = 0; i < (medio - inicio + 1); i++) vc_left[i] = vector[inicio + i];
    for(int i = 0; i < (fin - medio); i++) vc_right[i] = vector[medio + 1 + i];
    
    // Comparacion 
    int _i = 0, _j = 0, _k = inicio;
    while(_i < medio - inicio + 1 && _j < fin - medio){
        if(vc_left[_i] <= vc_right[_j]) vector[_k] = vc_left[_i++];
        else vector[_k] = vc_right[_j++];
        _k++;
    }
    
    // Elementos sobrantes
    while(_i < medio - inicio + 1) vector[_k++] = vc_left[_i++];
    while (_j < fin - medio) vector[_k++] = vc_right[_j++];
}
