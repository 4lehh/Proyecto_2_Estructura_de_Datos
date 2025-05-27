#include "../include/quickSort.hpp"

void QuickSort::sort(vc& vector) {
    int left = 0, right = vector.size() - 1;

    std::stack<par> stack;
    stack.push({left, right});

    while (!stack.empty()) {
        auto [l, r] = stack.top();
        stack.pop();

        if (l < r) {
            int pivot = partition(vector, l, r);
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

int QuickSort::partition(vc& vector, int left, int right) {
    // Elegimos la mediana de entre el primer, medio y último elemento como pivote
    int index_pivote = medianaDeTres(vector, left, right);
    int pivot = vector[index_pivote];

    std::swap(vector[index_pivote], vector[right]); // Mover el pivote al final

    int indice_primer_elemento_mayor = left;
    for (int j = left; j < right; j++) {
        if (vector[j] <= pivot) {
            std::swap(vector[indice_primer_elemento_mayor], vector[j]);
            indice_primer_elemento_mayor++;
        }
    }
    std::swap(vector[indice_primer_elemento_mayor], vector[right]); // Mover el pivote a su posición final
    return indice_primer_elemento_mayor; // Devolver el índice del pivote
}

int QuickSort::medianaDeTres(vc& vector, int left, int right) {
    int mid = left + (right - left) / 2;
    if (vector[left] > vector[mid]) std::swap(vector[left], vector[mid]);
    if (vector[left] > vector[right]) std::swap(vector[left], vector[right]);
    if (vector[mid] > vector[right]) std::swap(vector[mid], vector[right]);
    return mid; // El elemento medio ahora es la mediana
}
