#pragma once

/**
 * @file definiciones.hpp
 * @brief Definiciones y macros útiles para la implementación de algoritmos de ordenamiento.
 * 
 * Este archivo contiene definiciones y macros que facilitan la implementación de algoritmos de ordenamiento.
 * Incluye tipos de datos, macros para bucles y funciones de optimización de entrada/salida.
 * 
 * @note Se recomienda incluir este archivo en cada implementación de algoritmo de ordenamiento.
 */

#include <iostream>
#include <vector>
#include <utility> // Para std::pair
#include <limits>

typedef std::vector<int> vc;
typedef std::pair<int, int> par;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repx(i,x,n) for(int i=x;i<(int)n;i++)
#define invrep(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define imprimir(mensaje) std::cout << mensaje << std::endl

#define INF std::numeric_limits<int>::max()
#define NEG_INF std::numeric_limits<int>::min()

/**
 * @brief Función para optimizar la entrada/salida
 * 
 * Esta función desactiva la sincronización de C y C++ para mejorar la velocidad de entrada/salida.
 * Además, desactiva el uso de la función std::endl para evitar la sincronización innecesaria.
 * 
 * @note Se recomienda usar esta función al inicio del programa para optimizar el rendimiento.
 * @note En caso de estar testando el código, se recomienda comentar esta función.
 * @warning Esta función puede causar problemas si se mezcla con otras funciones de entrada/salida que dependen de la sincronización.
 */
void FunctionOptimization() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
}