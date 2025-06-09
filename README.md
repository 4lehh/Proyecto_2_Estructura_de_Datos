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
> [!NOTE]
> Antes de ejecutar el código, es necesario entender que la lectura de los datasets deben seguir una estructura. Para ello se recomienda seguir la siguiente plantilla
> ``resultados_<orden>_<num_elementos>.bin`` donde orden puede ser random, ascendente o descendente y num_elementos es un número que indica la cantidad de elementos que tiene el arreglo.
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
<details>
  <summary>Haz clic para expandir/contraer</summary>
  
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

</details>

## Creación de los datasets
<details>
  <summary>Haz clic para expandir/contraer</summary>
  
### Compilación del creador de datasets
```bash
g++ -o arrayGenerator.out ./src/arrayGenerator.cpp -O2
```
Compila el archivo fuente y genera el ejecutable ``arrayGenerator.out``

### Ejecutar el programa
```bash
./arrayGenerator.out <num_arreglos> <tamanio_arreglos> <dominio_numeros> <orden_arreglo>
```
Donde: 
- **<num_arreglos>** es la cantidad de arreglos que vamos a crear.
- **<tamanio_arreglos>** indica el largo de los arreglos que vamos a crear.
- **<dominio_numeros>** es el dominio de los numeros que puede manejar el arreglo que vamos a crear.
- **<orden_arreglo>** es el orden de los arreglos, ya sea random (1), ascendente (2) o descendente (3).
Ejecuta el programa (``arrayGenerator.out``).

</details>

## Comandos para ejecutar el analizador de los JSON obtenidos (Python)
> [!NOTE]
> **Para el correcto funcionamiento y evitar posibles conflictos, se recomienda la creación de un entorno virtual.**

> [!WARNING]
> **Para la ejecución del programa se requiere haber ejecutado el main con los datasets correspondientes.**

<details>
  <summary>Haz clic para expandir/contraer</summary>
  
### Instalar las dependencias
```bash
pip install -r ./analisis_graficos/requirements.txt
```
Descargará/Actualizará las dependencias necesarias para la visualización de los gráficos.

### Ejecución del programa
#### Linux
```bash
python ./analisis_graficos/analisis.py
```
o también 
```bash
python3 ./analisis_graficos/analisis.py
```
#### Windows
```cmd
python .\analisis_graficos\analisis.py
```
Ejecutará el programa y podrá visualizar los gráficos.

</details>
