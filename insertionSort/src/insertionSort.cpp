#include <iostream>
#include "../include/insertionSort.h"

InsertionSort::InsertionSort(int* _array, int _length){
    this->array = _array;
    this->length = _length;
}

void InsertionSort::showSort(){
    for(int i = 0; i < this->length; i++) std::cout << this->array[i] << " ";
    std::cout << "" << std::endl;
}

void InsertionSort::swap(int _index1, int _index2){
    int aux = this->array[_index1];
    this->array[_index1] = this->array[_index2];
    this->array[_index2] = aux;
}

void InsertionSort::sort(){
    for(int i = 0; i < this->length; i++){
        for(int j = i + 1; j < this->length; j++){
            if(this->array[i] > this->array[j]) swap(i, j);
        }
    }
}

int main(){
    int arr[] = {10, 7, 5, 2, 3, 8, 9, 1, 4, 6};
    InsertionSort sorting(arr, 10);
    sorting.sort();
    sorting.showSort();
}
