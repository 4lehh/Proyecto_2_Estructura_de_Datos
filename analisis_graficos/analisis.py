import numpy as np
from scipy.interpolate import make_interp_spline
import json
import matplotlib.pyplot as plt
from pathlib import Path
import re


directorio_todo = Path("../test/json/")

class Analisis:

    @staticmethod
    def obtenerNumeroJson(archivo: Path, patron_num: re.Pattern) -> int:
        """
        Esta función se encarga de extraer los numeros de los archivos JSON para luego generar el orden de los archivos.
        
        Args:
            archivo: Path del archivo JSON.
            patron_num: Patrón de expresión regular para encontrar el número en el nombre del archivo.
        Return: 
            Devuelve el número encontrado en el nombre del archivo, o -1 si no se encuentra.
        Example:
            'resultados_random_128.json' -> 128
        """

        match = patron_num.search(str(archivo))
        if match:
            return int(match.group(1))
        return -1  # en caso que no encuentre número (opcional)

    @staticmethod
    def promediosGenerales(ruta: str = None) -> list:
        """
        Esta función se encarga de calcular los promedios generales de los algoritmos de ordenamiento.
        Args:
            ruta: Ruta del archivo JSON que contiene los resultados de los algoritmos.
        Return:
            Devuelve una lista con los promedios de cada algoritmo.
        Example:
            promediosGenerales("resultados_random_128.json") -> [0.5, 0.3, 0.2, 0.4, 0.1, 0.6]
        """

        if(ruta == None): return

        mergesort = quicksort = insertionsort = heapsort = stdsort = timsort = 0.0

        with open(ruta, "r") as f:
            data = json.load(f)
        
        for archivo, resultados in data.items():
            mergesort += resultados["MergeSort"]
            quicksort += resultados["QuickSort"]
            insertionsort += resultados["InsertionSort"]
            heapsort += resultados["HeapSort"]
            stdsort += resultados["Sort C++"]
            timsort += resultados["TimSort"]

        datos = []
        datos.append(mergesort/100), datos.append(quicksort/100), datos.append(insertionsort/100), datos.append(heapsort/100), datos.append(stdsort/100), datos.append(timsort/100)
        return datos

    @staticmethod
    def graficaSpline(promedios: list, tamanos: list, orden: str) -> None:
        """
        Esta función se encarga de graficar los promedios de los algoritmos de ordenamiento utilizando un spline cúbico.
        Args:
            promedios: Lista de promedios de los algoritmos de ordenamiento correspondiente a cada tamaño.
            tamanos: Lista de tamaños de los arreglos.
            orden: Tipo de ordenamiento (random, ascendente, descendente).
        Return:
            No devuelve nada, solo muestra la gráfica.
        """

        algoritmos = list(zip(*promedios))
        nombres_algoritmos = ["MergeSort", "QuickSort", "InsertionSort", "HeapSort", "Sort C++", "TimSort"]

        plt.figure(figsize=(10, 6))

        for nombre, tiempos in zip(nombres_algoritmos, algoritmos):
            x = np.array(tamanos)
            y = np.array(tiempos)

            if len(x) >= 4:  
                # El spline cúbico necesita al menos 4 puntos
                x_suave = np.linspace(x.min(), x.max(), 300)
                spl = make_interp_spline(x, y, k=3)
                y_suave = spl(x_suave)
                plt.plot(x_suave, y_suave, label=nombre)
            else:
                # Si hay muy pocos puntos, graficamos normal
                plt.plot(x, y, label=nombre, marker='o')

            # Opcional: muestra los puntos reales con marcadores
            plt.scatter(x, y)

        plt.xscale("log", base=2)
        plt.xlabel("Tamaño del arreglo")
        plt.ylabel("Tiempo promedio (ms)")
        plt.title(f"Ordenamiento con elementos {orden}")
        plt.legend()
        plt.grid(True)
        plt.tight_layout()
        plt.show()

    @staticmethod
    def graficaLineal(promedios: list, tamanos: list, orden: str) -> None:
        """
        Esta función se encarga de graficar los promedios de los algoritmos de ordenamiento utilizando una gráfica lineal.
        Args:
            promedios: Lista de promedios de los algoritmos de ordenamiento correspondiente a cada tamaño.
            tamanos: Lista de tamaños de los arreglos.
            orden: Tipo de ordenamiento (random, ascendente, descendente).
        Return:
            No devuelve nada, solo muestra la gráfica.
        """

        algoritmos = list(zip(*promedios))

        nombres_algoritmos = ["MergeSort", "QuickSort", "InsertionSort", "HeapSort", "TimSort", "Sort C++"]

        # Crear la gráfica
        plt.figure(figsize=(10, 6))

        # Dibujar la curva de cada algoritmo
        for nombre, tiempos in zip(nombres_algoritmos, algoritmos):
            plt.plot(tamanos, tiempos, label=nombre, marker='o')

        plt.xscale("log", base=2)  # Escala logarítmica base 2 para tamaños
        plt.xlabel("Tamaño del arreglo")
        plt.ylabel("Tiempo promedio (ms)")
        plt.title(f"Ordenamiento con elementos {orden}")
        plt.legend()
        plt.grid(True)
        plt.tight_layout()
        plt.show()

    @staticmethod
    def obtenerPromedio(nombre_archivo: str, numero_archivo: str) -> list:
        r"""
        Esta función se encarga de obtener el promedio de los resultados de los archivos JSON.
        
        Args:
            nombre_archivo: Nombre del archivo JSON que contiene los resultados de los algoritmos.
            numero_archivo: Patrón de expresión regular para encontrar el número en el nombre del archivo.
        
        Return:
            Devuelve una lista con los promedios de cada algoritmo.
        
        Example:
            >>> obtenerPromedio("resultados_random_*.json", r'resultados_random_(\d+)\.json')
            [0.5, 0.3, 0.2, 0.4, 0.1, 0.6]
        """

        global directorio_todo
        promedio = []
        archivos = list(directorio_todo.glob(nombre_archivo))
        patron_num = re.compile(numero_archivo)

        # Obtenemos los numeros de los archivos y los ordenamos
        archivos_ordenados = sorted(archivos, key=lambda f: Analisis.obtenerNumeroJson(f, patron_num))
        
        for archivo in archivos_ordenados:
            promedio.append(Analisis.promediosGenerales(archivo))
        return promedio



tamanos_random = tamanos_descendente = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144]
tamanos_ascendente = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432]
promedio_random = Analisis.obtenerPromedio("resultados_random_*.json", r"resultados_random_(\d+)\.json")                         # Promedio de los json randoms
promedio_ascendente = Analisis.obtenerPromedio("resultados_ascending*.json", r"resultados_ascending_(\d+)\.json")                # Promedio de los json ascendentes
promedio_descendente = Analisis.obtenerPromedio("resultados_descending*.json", r"resultados_descending_(\d+)\.json")             # Promedio de los json descendentes

Analisis.graficaSpline(promedio_random, tamanos_random, "random")
Analisis.graficaSpline(promedio_ascendente, tamanos_ascendente, "ascendentes")
Analisis.graficaSpline(promedio_descendente, tamanos_descendente, "descendentes")


