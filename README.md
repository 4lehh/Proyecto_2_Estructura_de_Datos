# Proyecto 2 Estructura de Datos
## Integrantes del grupo
- [Antonio Jesus Benavides Puentes](https://github.com/AntoCreed777) **(2023455954)**
- [Javier Alejandro Campos Contreras](https://github.com/huebitoo) **(2023432857)**

## Tecnologias utilizadas en el proyecto
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,github,vscode,neovim&perline=5" />
  </a>
</p>
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=cpp,python,bash&perline=5" />
  </a>
</p>

## Definición del problema

<details>
  <summary>Haz clic para expandir/contraer</summary>

  En este nuevo entregable vamos a buscar el mejor algoritmo de ordenamiento que puedan implementar o encontrar (de ahí el death-match). 
  
  Existen muchos algoritmos de ordenamiento y cada uno puede ser implementado de diversas maneras, incluso combinando varios algoritmos en uno. Es por ello que encontrar la mejor implementación no es una tarea trivial. 
  
  El objetivo de este entregable es que sean capaces de comparar experimentalmente diversas implementaciones y decidir, en base a evidencia recolectada en sus experimentos, cuál es la mejor solución.
  
  Adicionalmente, esta primera tarea permitirá a los estudiantes familiarizarse con herramientas de profiling y con la creación de códigos que les permitan medir tiempos de ejecución.

  En la comparación, como mínimo, deben considerar los siguientes algoritmos 

- Insertion sort
- Merge sort
- Quick sort
- Heap sort
- Función de sorting implementada en la biblioteca estándar de C++
- Otro algoritmo de ordenamiento que encuentren. Puede ser una fusión de los anteriores.


### Formato de Entrada
Todos los algoritmos implementados deben ordenar números enteros de 32 bits. Sobre los arreglos a ordenar, estos deberán ser leídos desde un archivo de entrada que tenga los valores serializados (es decir, que tenga guardados los 32 bits de cada número). En los experimentos deben probar con distintos tipos de arreglos, entre ellos:

- Arreglos completamente desordenados
- Arreglos ordenados de manera ascendente 
- Arreglos ordenados de manera descendente 
- Otros posibles casos que se les ocurran (ej. arreglos parcialmente ordenados)

### Salida Esperada

Para este entregable, se acordó que la salida consistirá en archivos en formato `json`, los cuales se almacenarán en la ruta `/test/json`. En estos archivos se registrarán los tiempos de ejecución de las pruebas realizadas con cada algoritmo, aplicados a los diferentes conjuntos de datos generados específicamente para las pruebas.

</details>

## ⚙ **Comandos de Compilacion con Make**
### Compilar todo 
```bash
make
```
Compila (si es necesario) todos los archivos fuente y genera el ejecutable ``main.out`` en el directorio raíz.

### Ejecutar el programa
```bash
make run
```
Compila (si es necesario) todos los archivos fuentes y genera el ejecutable ``main.out``, luego lo ejecuta.

### Ejecutar modo debug
```bash
make debug
```
Compila (si es necesario) el programa y abre el ejecutable ``main.out`` con ``gdb`` para depuración.

### Investigar fugas de memoria
```bash
make memoria
```
Compila (si es necesario) y ejecuta el programa usando ``valgrind`` para identificar posibles fugas de memoria. Muestra información detallada sobre las fugas y sus causas.

### Limpiar archivos generados
```bash
make clean
```
Elimina los archivos generados durante la compilación, incluyendo:

  - Todos los archivos objeto en ``build/``.

  - El ejecutable ``main.out``.

## Comandos de compilacion sin Make

### Compilar Todo
```bash
g++ -I ./include -Wall -O2 ./src/main.cpp ./src/heapSort.cpp ./src/quickSort.cpp ./src/mergeSort.cpp ./src/insertionSort.cpp ./src/timSort.cpp -o main.out
```
Compila todos los archivos fuente y genera el ejecutable ``main.out`` en el directorio raíz.

### Ejecutar el programa
```bash
./main.out
```
Ejecuta el programa (``main.out``).
