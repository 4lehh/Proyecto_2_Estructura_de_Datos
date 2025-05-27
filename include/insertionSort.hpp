#pragma once

/**
 * @file insertionSort.hpp
 * @brief Implementación del algoritmo de ordenamiento por inserción.
 * 
 * Este archivo contiene la implementación del algoritmo de ordenamiento por inserción, eficiente para listas pequeñas.
 * 
 * @note El algoritmo tiene una complejidad temporal de O(n^2) en el peor caso.
 * @note La implementación utiliza un vector de enteros como entrada.
 */

#include "definiciones.hpp"

class InsertionSort{
    public:
        /**
         * @brief Función para ordenar un vector utilizando el algoritmo Insertion Sort.
         * 
         * @param vector El vector a ordenar.
         */
        static void sort(vc& vector);
};
