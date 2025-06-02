import numpy as np
from scipy.interpolate import make_interp_spline
import os
import json
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from pathlib import Path
from collections import defaultdict
import re

directorio = Path("./test/json/")

def analisisPorJson(ruta: str = None) -> None:
    if(ruta == None): return
    
    # Cargar el archivo JSON
    with open(ruta, "r") as f:
        data = json.load(f)

    # Extraemos las claves (archivos) y los algoritmos
    files = list(data.keys())
    algorithms = list(next(iter(data.values())).keys())

    # Armar los tiempos por algoritmo
    tiempos = {alg: [data[archivo][alg] for archivo in files] for alg in algorithms}

    # Crear gráfico
    plt.figure(figsize=(8, 5))

    for algoritmo in algorithms:
        plt.plot(tiempos[algoritmo], label=algoritmo)

    # Estética básica
    plt.title("Tiempos de ejecución por algoritmo de ordenamiento")
    plt.xlabel("Índice de archivo")
    plt.ylabel("Tiempo (milisegundos)")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()


# Función para obtener el número del archivo
def obtenerNumeroJson(archivo: Path, patron_num: re.Pattern) -> int:
    match = patron_num.search(str(archivo))
    if match:
        return int(match.group(1))
    return -1  # en caso que no encuentre número (opcional)

def promediosGenerales(ruta: str = None) -> list:
    if(ruta == None): return
    
    mergesort = 0.0
    quicksort = 0.0
    insertionsort = 0.0
    heapsort = 0.0
    stdsort = 0.0

    with open(ruta, "r") as f:
        data = json.load(f)

    for archivo, resultados in data.items():
        mergesort += resultados["MergeSort"]
        quicksort += resultados["QuickSort"]
        insertionsort += resultados["InsertionSort"]
        heapsort += resultados["HeapSort"]
        stdsort += resultados["Sort C++"]
    
    datos = []
    datos.append(mergesort/1000)
    datos.append(quicksort/1000)
    datos.append(insertionsort/1000)
    datos.append(heapsort/1000)
    datos.append(stdsort/1000)
    
    return datos

def grafica(promedios: list, tamanos: list, orden: str) -> None:
    algoritmos = list(zip(*promedios))
    nombres_algoritmos = ["MergeSort", "QuickSort", "InsertionSort", "HeapSort", "Sort C++"]

    plt.figure(figsize=(10, 6))

    for nombre, tiempos in zip(nombres_algoritmos, algoritmos):
        x = np.array(tamanos)
        y = np.array(tiempos)

        if len(x) >= 4:  # El spline cúbico necesita al menos 4 puntos
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
    plt.title(f"Comparación de algoritmos de ordenamiento con elementos {orden}")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

def grafica1(promedios: list, numeros: list, orden: str) -> None:
    algoritmos = list(zip(*promedios))

    nombres_algoritmos = ["MergeSort", "QuickSort", "InsertionSort", "HeapSort", "Sort C++"]

    # Crear la gráfica
    plt.figure(figsize=(10, 6))

    # Dibujar la curva de cada algoritmo
    for nombre, tiempos in zip(nombres_algoritmos, algoritmos):
        plt.plot(tamanos, tiempos, label=nombre, marker='o')

    plt.xscale("log", base=2)  # Escala logarítmica base 2 para tamaños
    plt.xlabel("Tamaño del arreglo")
    plt.ylabel("Tiempo promedio (ms)")
    plt.title(f"Comparación de algoritmos de ordenamiento con elementos {orden}")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

def obtenerPromedio(nombre_archivo: str, numero_archivo: str) -> list:
    global directorio
    promedio = []
    archivos = list(directorio.glob(nombre_archivo))
    patron_num = re.compile(numero_archivo)

    archivos_ordenados = sorted(archivos, key=lambda f: obtenerNumeroJson(f, patron_num))
    
    for archivo in archivos_ordenados:
        promedio.append(promediosGenerales(archivo))
    
    return promedio

tamanos = [8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144]
promedio_random = obtenerPromedio("resultados_random_*.json", r"resultados_random_(\d+)\.json")                         # Promedio de los json randoms
promedio_ascendente = obtenerPromedio("resultados_ascending*.json", r"resultados_ascending_(\d+)\.json")                 # Promedio de los json ascendentes
promedio_descendente = obtenerPromedio("resultados_descending*.json", r"resultados_descending_(\d+)\.json")             # Promedio de los json descendentes

grafica(promedio_random, tamanos, "random")
grafica(promedio_ascendente, tamanos, "ascendentes")
grafica(promedio_descendente, tamanos, "descendentes")

