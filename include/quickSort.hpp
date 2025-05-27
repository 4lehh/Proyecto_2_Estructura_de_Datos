#pragma once

/**
 * @file quickSort.hpp
 * @brief Implementación del algoritmo Quick Sort.
 * 
 * Este archivo contiene la implementación del algoritmo Quick Sort, que es un algoritmo de ordenamiento basado en la técnica de divide y vencerás.
 * 
 * @note El algoritmo tiene una complejidad temporal de O(n log n) en el peor caso.
 * @note La implementación utiliza un vector de enteros como entrada.
 */

#include "definiciones.hpp"
#include <stack>

class QuickSort {
    public:
        /**
         * @brief Función para ordenar un vector utilizando el algoritmo Quick Sort.
         * 
         * @param vector El vector a ordenar.
         */
        static void sort(vc &vector);

    private:
        /**
         * @brief Función para particionar el vector.
         * 
         * @param vector El vector a ordenar.
         * @param left El índice izquierdo del subvector.
         * @param right El índice derecho del subvector.
         * @return El índice del pivote después de la partición.
         */
        static int partition(vc& vector, int left, int right);

        /**
         * @brief Función para encontrar la mediana de tres elementos.
         * 
         * @param vector El vector a ordenar.
         * @param left El índice izquierdo del subvector.
         * @param right El índice derecho del subvector.
         * @return El índice de la mediana de los tres elementos.
         */
        static int medianaDeTres(vc& vector, int left, int right);

};