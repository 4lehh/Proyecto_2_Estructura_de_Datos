#include "../include/quickSort.hpp"

void QuickSort::sort(vc &arr) {
    int left = 0, right = arr.size() - 1;

    std::stack<par> stack;
    stack.push({left, right});

    while (!stack.empty()) {
        auto [l, r] = stack.top();
        stack.pop();

        if (l < r) {
            int pivot = partition(arr, l, r);
            if (pivot - l > r - pivot) { // Se ordena la parte más pequeña primero
                stack.push({l, pivot - 1});
                stack.push({pivot + 1, r});
            }
            else {
                stack.push({pivot + 1, r});
                stack.push({l, pivot - 1});
            }
        }
    }
}

int QuickSort::partition(vc &arr, int left, int right) {
    // Elegimos la mediana de entre el primer, medio y último elemento como pivote
    int index_pivote = medianaDeTres(arr, left, right);
    int pivot = arr[index_pivote];

    std::swap(arr[index_pivote], arr[right]); // Mover el pivote al final

    int indice_primer_elemento_mayor = left;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            std::swap(arr[indice_primer_elemento_mayor], arr[j]);
            indice_primer_elemento_mayor++;
        }
    }
    std::swap(arr[indice_primer_elemento_mayor], arr[right]); // Mover el pivote a su posición final
    return indice_primer_elemento_mayor; // Devolver el índice del pivote
}

int QuickSort::medianaDeTres(vc &v, int left, int right) {
    int mid = left + (right - left) / 2;
    if (v[left] > v[mid]) std::swap(v[left], v[mid]);
    if (v[left] > v[right]) std::swap(v[left], v[right]);
    if (v[mid] > v[right]) std::swap(v[mid], v[right]);
    return mid; // El elemento medio ahora es la mediana
}
