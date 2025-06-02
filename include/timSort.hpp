#pragma once
#include "definiciones.hpp"

class TimSort{
    public:
        static void sort(vc& vector);
    private:
        static void timsort(vc& vector, int inicio, int fin);
        static void merge(vc& vector, int inicio, int medio, int fin);
        static void insertionsort(vc& vector, int inicio, int fin);


};
