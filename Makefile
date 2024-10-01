# Compilar el código fuente y generar un ejecutable: make
# Limpiar ficheros .o y ejecutable: make clean
# Ejemplo de ejecución: ./main

# Variables
CC = g++
CFLAGS = -std=c++17

# Objetivo por defecto (se ejecuta al correr solo "make")
make: include/hash_table.h include/dispersion_function.h include/exploration_function.h \
			include/fd_module.h include/fd_sum.h include/fd_pseudorandom.h \
			include/fe_lineal.h include/fe_quadratic.h include/fe_double_dispersion.h include/fe_redispersion.h \
			src/main.cc
	$(CC) $(CFLAGS) -o main src/main.cc

# Limpiar los archivos binarios
clean:
	rm -f *.o main