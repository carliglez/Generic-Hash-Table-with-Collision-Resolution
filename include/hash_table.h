/**
 * @brief Declaración de la clase HashTable. Clase que permite crear una tabla hash para utilizar algoritmos
 * de búsqueda y técnicas de dispersión.
 * 
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <iostream>
#include <vector>
#include <list>

#include "dispersion_function.h"
#include "exploration_function.h"
#include "sequence.h"
#include "list.h"
#include "block.h"

/**
 * @class HashTable
 * 
 * @brief Clase para poder implementar una tabla hash para la utilización de algoritmos de búsquedas.
 * 
 * @tparam Key 
 */
template<class Key>
class HashTable {
  public:
    HashTable(int table_size, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe = nullptr, int block_size = 0);
    ~HashTable();
    
    // método para buscar un valor k en la tabla hash
    bool Search(const Key& k) const;

    // método para insertar el valor k en la tabla hash
    bool Insert(const Key& k);

    // método para imprimir la tabla
    void PrintTable();
    
  private:
    int table_size_;                     // tamaño de la tabla hash
    std::vector<Sequence<Key>*> table_;  // tabla
    DispersionFunction<Key> *fd_;        // puntero a la clase base dispersion_function<key>
    int block_size_;                     // tamaño de los bloques en la dispersión cerrada
    ExplorationFunction<Key> *fe_;       // fe_ puntero a la clase base exploration function<key>
};

template<class Key>
HashTable<Key>::HashTable(int table_size, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, int block_size) {
  table_size_ = table_size;
  fd_ = fd;
  fe_ = fe;
  block_size_ = block_size;
  
  for (int i = 0; i < table_size_; ++i) {
    Sequence<Key> *sequence;

    if (fe_ == nullptr) {
      sequence = new List<Key>;
    } else {
      sequence = new Block<Key>(block_size_);
    } 

    table_.push_back(sequence);
  }
} 

template<class Key>
HashTable<Key>::~HashTable() {}

/**
 * @brief Método para buscar un valor k en la tabla hash
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template<class Key>
bool HashTable<Key>::Search(const Key& k) const{
  int pos = fd_->operator()(k);
  
  if (fe_ == nullptr) {
    if (table_[pos]->Search(k)) {
      return true;
    } 
  } else {
    for (int i = 0; i < table_size_; ++i) {
      int exploration = (pos + fe_->operator()(k, i)) % table_size_;
      if (table_[exploration]->Search(k)) {
        return true;
      }
    }    
  }

  return false;
}

/**
 * @brief Método para insertar el valor k en la tabla hash
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template<class Key>
bool HashTable<Key>::Insert(const Key& k) {
  int pos = fd_->operator()(k);
  
  if (fe_ == nullptr) {
    if (table_[pos]->Search(k)) {
      std::cout << "La clave ya se encuentra en la tabla" << std::endl;
      return false;
    } 
    table_[pos]->Insert(k);
    std::cout << "La clave se ha insertado en la posición: " << pos << std::endl;
    return true;
  } else {
    for (int i = 0; i < table_size_; ++i) {     
      int exploration = (pos + fe_->operator()(k, i)) % table_size_;      
      if (table_[exploration]->Search(k)) {
        std::cout << "La clave ya se encuentra en la tabla" << std::endl;
        return false;
      }      
      if (table_[exploration]->Insert(k)) {
        std::cout << "La clave se ha insertado en la posición: " << exploration << std::endl;
        return true;
      }
    }    
  }
  
  return false;
}

/**
 * @brief Método para imprimir el contenido de la tabla hash. Se itera sobre cada elemento del vector table_ e imprime
 * el contenido usando el método Print() declarado en Sequence<Key> según el objeto apuntado por el elemento actual
 * 
 * @tparam Key
 */
template<class Key>
void HashTable<Key>::PrintTable() {
  for (int i = 0; i < table_size_; ++i) {
    std::cout << "Posición [" << i << "]: ";
    table_[i]->Print(); // considerando que Sequence<Key> tiene un método Print()
    std::cout << std::endl;
  }
}

#endif  // HASH_TABLE_H_