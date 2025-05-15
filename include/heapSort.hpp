//#pragma once
/**
 * @file heapSort.hpp
 * @brief Implementación del algoritmo HeapSort.
 * 
 * Este archivo contiene la implementación del algoritmo HeapSort, que es un algoritmo de ordenamiento basado en la estructura de datos heap (montículo).
 * 
 * @note El algoritmo tiene una complejidad temporal de O(n log n) en el peor caso.
 * @note La implementación utiliza un vector de enteros como entrada.
 */


#include "definiciones.hpp"

class HeapSort {
    public: 
        /**
         * @brief Función para ordenar un vector utilizando el algoritmo HeapSort.
         * 
         * @param v El vector a ordenar.
         */
        static void sort(vc &v);

    private:
        /**
         * @brief Función para convertir un subárbol en un heap.
         * 
         * @param v El vector a ordenar.
         * @param n El tamaño del heap. (Cuando se extraen elementos, el tamaño se reduce)
         * @param i El índice del subárbol.
         */
        static void heapify(vc &v, int n, int i);
};