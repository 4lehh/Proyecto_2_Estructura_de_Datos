#include "../include/insertionSort.hpp"

void InsertionSort::sort(vc& vector){
    int tamaño = vector.size();
    
    for(int i = 0; i < tamaño; i++){
        for(int j = i + 1; j < tamaño; j++){
            if(vector[i] > vector[j]) std::swap(vector[i], vector[j]);
        }
    }
}
