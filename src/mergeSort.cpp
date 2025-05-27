#include "../include/mergeSort.hpp"

void MergeSort::sort(vc& vector) {
    if (vector.empty()) return;
    sort(vector, 0, vector.size() - 1);
}

void MergeSort::sort(vc& vector, int inicio, int fin){
    if (inicio >= fin) return;

    int _medio = (inicio + fin) / 2;

    sort(vector, inicio, _medio);
    sort(vector, _medio + 1, fin);
    merge(vector, inicio, _medio, fin);
}

void MergeSort::merge(vc& vector, int inicio, int medio, int fin){
    vc vc_left(medio - inicio + 1), vc_right(fin - medio);
    
    // copias
    for(int i = 0; i < medio - inicio + 1; i++) vc_left[i] = vector[inicio + i];
    for(int i = 0; i < fin - medio; i++) vc_right[i] = vector[medio + 1 + i];
    
    // Comparacion 
    int _i = 0, _j = 0, _k = inicio;
    while(_i < medio - inicio + 1 && _j < fin - medio){
        if(vc_left[_i] <= vc_right[_j]) vector[_k] = vc_left[_i++];
        else vector[_k] = vc_right[_j++];
        _k++;
    }
    
    // Elementos sobrantes
    while(_i < medio - inicio + 1) vector[_k++] = vc_left[_i++];
    
    // Los elementos restantes del subvector derecho no necesitan ser copiados
    // porque ya están en su lugar en el vector original
}
