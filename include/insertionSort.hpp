#pragma once
#include <vector>

class InsertionSort{
    private:
        /**
         * @brief Función para ordenar un vector utilizando el algoritmo Insertion Sort.
         * 
         * @param vector El vector a ordenar.
         * @param indice_1 El indice de los elementos que queremos hacer swap.
         * @param indice_2 El indice de los elementos que queremos hacer swap.
         */
        static void swap(std::vector<int>&,int,int);
        
    public:
        /**
         * @brief Función para ordenar un vector utilizando el algoritmo Insertion Sort.
         * 
         * @param vector El vector a ordenar.
         */
        static void sort(std::vector<int>&);
};
