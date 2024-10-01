/**
 * @brief Programa principal de la Práctica 4: Búsqueda por dispersión. Se ha implementado una tabla hash para
 * utilizar algoritmos de búsqueda y técnicas de dispersión.
 * 
 */

#include <iostream>
#include <unistd.h>
#include <fstream>

#include "../include/hash_table.h"
#include "../include/dispersion_function.h"
#include "../include/exploration_function.h"
#include "../include/fd_module.h"
#include "../include/fd_sum.h"
#include "../include/fd_pseudorandom.h"
#include "../include/fe_lineal.h"
#include "../include/fe_quadratic.h"
#include "../include/fe_double_dispersion.h"
#include "../include/fe_redispersion.h"

/**
 * @brief Programa principal con el que interactúa el/la usuario/a
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char * argv[]) {  
  int table_size = 0, block_size = 0, option = 0;
  DispersionFunction<long> *fd = nullptr;
  ExplorationFunction<long> *fe = nullptr;
  bool quit = false;

  std::cout << "Introduzca el tamaño de la tabla: ";
  std::cin >> table_size;
  
  // escoger función de dispersión
  std::cout << std::endl;
  std::cout << "Funciones de dispersión disponibles: " << std::endl;
  std::cout << "1. Función de dispersión módulo" << std::endl;
  std::cout << "2. Función de dispersión basada en la suma" << std::endl;
  std::cout << "3. Función de dispersión pseudoaleatoria" << std::endl;
  std::cout << "Seleccione una de las opciones: ";
  std::cin >> option;
  quit = false;
  while (!quit) {
    switch (option) {
      case 1:
        std::cout << "Se ha seleccionado la dispersión módulo" << std::endl; 
        quit = true;
        fd = new fdModule<long>(table_size);
        break;
      case 2:
        std::cout << "Se ha seleccionado la dispersión basada en la suma" << std::endl; 
        quit = true;
        fd = new fdSum<long>(table_size);
        break;
      case 3:
        std::cout << "Se ha seleccionado la dispersión pseudoaleatoria" << std::endl; 
        quit = true;
        fd = new fdPseudorandom<long>(table_size);
        break;
      default:
        std::cout << "La opción no es correcta, seleccione otra por favor: ";
        std::cin >> option;       
    }
  }

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Técnicas de dispersión disponibles: " << std::endl;
  std::cout << "1. Dispersión abierta" << std::endl;
  std::cout << "2. Dispersión cerrada" << std::endl;
  std::cout << "Seleccione una de las opciones: ";
  std::cin >> option;    
  quit = false;
  while (!quit) {
    if (option != 1 && option != 2)  {
      std::cout << "La opción no es correcta, seleccione otra por favor: ";
      std::cin >> option;    
    } else {
      quit = true;
    }
  }
  
  // en caso de escoger dispersión cerrada
  if (option == 2) {
    std::cout << std::endl;
    std::cout << "Debido a que se trata de dispersión cerrada, indique el tamaño de bloque por favor: ";
    std::cin >> block_size;
    
    // escoger función de exploración
    std::cout << std::endl;
    std::cout << "Funciones de exploración disponibles: " << std::endl;    
    std::cout << "1. Función de exploración lineal" << std::endl;
    std::cout << "2. Función de exploración cuadrática" << std::endl;
    std::cout << "3. Función de exploración de doble dispersión" << std::endl;
    std::cout << "4. Función de exploración de redispersión" << std::endl;
    std::cout << "Seleccione una de las opciones: ";
    std::cin >> option;
    quit = false;
    while (!quit) {
      switch (option) {
        case 1:
          std::cout << "Se ha seleccionado la exploración lineal" << std::endl; 
          quit = true;
          fe = new feLineal<long>;
          break;
        case 2:
          std::cout << "Se ha seleccionado la exploración cuadrática" << std::endl; 
          quit = true;
          fe = new feQuadratic<long>;
          break;
        case 3:
          std::cout << "Se ha seleccionado la exploración de doble dispersión" << std::endl; 
          quit = true;
          fe = new feDoubleDispersion<long>(fd);
          break;
        case 4:
          std::cout << "Se ha seleccionado la exploración redispersion" << std::endl; 
          quit = true;
          fe = new feRedispersion<long>;
          break;  
        default:
          std::cout << "La opción no es correcta, seleccione otra por favor: ";
          std::cin >> option;       
      }
    }
  }
  
  HashTable<long> hash_table(table_size, fd, fe, block_size);
  
  quit = false;
  while (!quit) {
    option = 0;
    long key = 0;
    std::cout << std::endl;
    std::cout << "Acciones a realizar disponibles: " << std::endl;
    std::cout << "1. Insertar un valor en la tabla hash" << std::endl;
    std::cout << "2. Buscar un valor en la tabla hash" << std::endl;
    std::cout << "3. Imprimir el contenido de la tabla hash" << std::endl;
    std::cout << "4. Salir del programa" << std::endl;
    std::cout << "Seleccione una de las opciones: ";  
    std::cin >> option;
    switch (option) {
      case 1:
        std::cout << "¿Qué clave quiere insertar?: ";
        std::cin >> key;
        if(hash_table.Insert(key)) {
          std::cout << "La clave se puede insertar en la tabla hash" << std::endl; 
        } else {
          std::cout << "La clave NO se puede insertar en la tabla hash" << std::endl; 
        }
        break;
      case 2:
        std::cout << "¿Qué clave quiere buscar?: ";
        std::cin >> key;
        if (hash_table.Search(key)) {
          std::cout << "La clave se encuentra en la tabla hash" << std::endl; 
        } else {
          std::cout << "La clave NO se encuentra en la tabla hash" << std::endl; 
        }
        break;
      case 3:
        std::cout << "\nEl contenido de la tabla es el siguiente: " << std::endl;
        hash_table.PrintTable();
        break; 
      case 4:
        std::cout << "Saliendo del programa..." << std::endl;
        quit = true;
        break;  
      default:
        std::cout << "La opción no es correcta, seleccione otra por favor" << std::endl;
        std::cin >> option;         
    }
  }
  
  hash_table.PrintTable();  // imprimir la tabla hash por pantalla
  delete fd;
  delete fe;
  std::cout << std::endl;
  std::cout << "Programa finalizado." << std::endl;
  return 0;
}