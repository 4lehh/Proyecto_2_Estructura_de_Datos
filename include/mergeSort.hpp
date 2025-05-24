#pragma once 
#include <vector>

/**
 * @file mergeSort.hpp
 * @brief Implementación del algoritmo MergeSort.
 * 
 * Este archivo contiene la implementación del algoritmo MergeSort, que es un algoritmo recursivo.
 * 
 * @note El algoritmo tiene una complejidad temporal de O(n²) en el peor caso.
 * @note La implementación utiliza un vector de enteros como entrada.
 */

class MergeSort{
    public:
        /**
         * @brief Función para ordenar un vector utilizando el algoritmo Merge Sort.
         * 
         * @param vector El vector a ordenar.
         */
        static void sort(std::vector<int>&);
    private:
        /**
         * @brief Función para ordenar un vector utilizando el algoritmo Merge Sort.
         * 
         * @param vector El vector a ordenar.
         * @param inicio El inicio del subvector o lado izquierdo.
         * @param fin El fin de subvector o lado derecho del subvector.
         */
        static void sort(std::vector<int>&,int,int);
        /**
         * @brief Funcion que se encarga de hacer el merge.
         * 
         * @param vector El vector a ordenar.
         * @param inicio El índice izquierdo del subvector.
         * @param medio El índice medio del subvector.
         * @param fin El índice derecho del subvector.
         */
        static void merge(std::vector<int>&,int,int,int);
};
