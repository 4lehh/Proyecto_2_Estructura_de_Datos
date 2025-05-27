# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS_BASE = -I ./include -Wall
CXXFLAGS_WARNINGS = -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wfloat-equal
CXXFLAGS_OPTIMIZATIONS = -O2 -march=native -mtune=native
CXXFLAGS_DEBUGGING = -g -ggdb

CXXFLAGS_RELEASE = $(CXXFLAGS_BASE) $(CXXFLAGS_OPTIMIZATIONS)
CXXFLAGS_DEBUG = $(CXXFLAGS_BASE) $(CXXFLAGS_DEBUGGING)

CXXFLAGS = $(CXXFLAGS_RELEASE)

OBJ_DIR = build
TARGET = main.out

SOURCES = src/main.cpp src/heapSort.cpp src/quickSort.cpp src/mergeSort.cpp src/insertionSort.cpp
OBJECTS = $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

.PHONY: all clean run debug memoria

# Regla por defecto
all: $(TARGET)

# Regla para compilar el programa
$(TARGET): $(OBJECTS)
	@echo "Compilando el programa..."
	@$(CXX) $(OBJECTS) -o $(TARGET) $(CXXFLAGS)

# Regla para compilar archivos objeto
$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	@echo "Compilando $<..."
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

# Crear el directorio obj si no existe
$(OBJ_DIR):
	@mkdir -p $@

# Regla para ejecutar el programa
run: $(TARGET)
	@if [ -f $(TARGET) ]; then \
		echo "Ejecutando el programa...\n"; \
		./$(TARGET); \
	else \
		echo "Error: El programa no se compiló correctamente."; \
	fi

# Regla para depurar
debug: $(TARGET)
	@gdb ./$(TARGET)

# Regla para verificar fugas de memoria
memoria: $(TARGET)
	@valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# Regla para limpiar
clean:
	@rm -rf $(OBJ_DIR) $(TARGET)
