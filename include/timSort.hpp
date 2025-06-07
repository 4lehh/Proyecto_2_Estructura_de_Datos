#pragma once
#include "definiciones.hpp"

 /**
 * @file timSort.hpp
 * @brief Implementación del algoritmo TimSort.
 * 
 * Este archivo contiene la implementación del algoritmo TimSort, que es un algoritmo hibrido entre MergeSort y InsertionSort.
 * 
 * @note El algoritmo tiene una complejidad temporal de O(n log n) en el peor caaso.
 * @note La implementación utiliza un vector de enteros como entrada.
 */
class TimSort{
    public:
        /**
         * @brief Función para ordenar un vector utilizando el algoritmo TimSort.
         * 
         * @param vector El vector a ordenar.
         */
        static void sort(vc& vector);
    private:
        /**
         * @brief Función que se encarga de la recursión y la toma de decisiones para cual algoritmo usar
         *
         * @param vector El vector a ordenar
         * @param inicio El indice de inicio 
         * @param fin El indice del final
         */
        static void timsort(vc& vector, int inicio, int fin);
        /**
         * @brief Función encargada de hacer merge a las ramas 
         *
         * @param vector El vector a ordenar
         * @param inicio El indice de inicio
         * @param medio El indice que marca la mitad
         * @param fin El indicie del final
         */
        static void merge(vc& vector, int inicio, int medio, int fin);
        /**
         * @brief Función encargada de ordenar los arreglos de tamaño minimo
         *
         * @param vector El vector a ordenar
         * @param inicio El indice del inicio
         * @param fin El indice del final
         */
        static void insertionsort(vc& vector, int inicio, int fin);
};
