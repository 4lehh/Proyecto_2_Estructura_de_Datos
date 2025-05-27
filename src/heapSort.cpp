#include "../include/heapSort.hpp"

void HeapSort::sort(vc& vector) {
    int n = vector.size();

    // Construir el heap, itero desde el penultimo nivel hasta la raíz
    // El último nivel no necesita heapificación [n/2, n-1]
    for (int i = n / 2 - 1; i >= 0; i--) heapify(vector, n, i);

    // Esto es una forma alternativa de construir el heap que ya esta implementada en std
    ////////////////////// PREGUNTARLE AL PROFESOR SI ES QUE LA PODEMOS USAR //////////////////////
    //std::make_heap(v.begin(), v.end()); // Construir el heap

    // Extraer elementos del heap
    for (int i = n - 1; i > 0; i--) {
        std::swap(vector[0], vector[i]); // Mover la raíz actual al final

        //std::make_heap(v.begin(), v.begin() + i); // Reconstruir el heap reducido
        heapify(vector, i, 0); // Llamar a heapify en el heap reducido
    }
}

void HeapSort::heapify(vc& vector, int n, int i) {
    while (true) {
        int largest = i; // Posicion inicial como el más grande

        int left = 2 * i + 1; // Posicion hijo izquierdo
        int right = 2 * i + 2; // Posicion hijo derecho

        // Si el hijo izquierdo es mayor que la raíz
        if (left < n && vector[left] > vector[largest]) largest = left;

        // Si el hijo derecho es mayor que el más grande hasta ahora
        if (right < n && vector[right] > vector[largest]) largest = right;

        if (largest == i) break; // Si no hay cambios, salimos

        std::swap(vector[i], vector[largest]);
        i = largest; // Continuo con el subárbol afectado
    }
}