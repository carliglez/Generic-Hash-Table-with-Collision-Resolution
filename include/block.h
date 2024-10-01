/**
 * @brief Declaración de la clase Block. Se trata de una clase para trabajar con dispersión cerrada.
 * 
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include <iostream>
#include <vector>

#include "sequence.h"

/**
 * @class Block
 * 
 * @brief Clase bloque necesaria para la implementación de la técnica de dispersión cerrada.
 * 
 * @tparam Key 
 */
template<class Key>
class Block : public Sequence<Key> {
  public:
    Block(const unsigned n): block_size_(n), fill_(0) {
      for (int i = 0; i < block_size_; ++i) {
        block_.push_back(-1);
      }
    }

    bool Search(const Key& k) const override;

    bool Insert(const Key& k) override;

    bool IsFull() const override;

    void Print() const override;

  private:
    unsigned block_size_;
    unsigned fill_;
    std::vector<Key> block_;    
};

/**
 * @brief Método para buscar el valor k  en la secuencia
 * 
 * @tparam Key 
 * @param k clave
 * @return true 
 * @return false 
 */
template<class Key>
bool Block<Key>::Search(const Key& k) const {
  for (int i = 0; i < block_size_; ++i) {
    if (block_[i] == k) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Método para insertar el valor k en la secuencia
 * 
 * @tparam Key 
 * @param k clave
 * @return true 
 * @return false 
 */
template<class Key>
bool Block<Key>::Insert(const Key& k) {
  if (IsFull()) {
    return false;
  }
  for (int i = 0; i < block_size_; ++i) {
    if (block_[i] == -1) {
      block_[i] = k;
      fill_++;
      return true;
    }
  }  
  return false;
}

/**
 * @brief Método para comprobar si la secuencia está llena
 * 
 * @tparam Key 
 * @return true 
 * @return false 
 */
template<class Key>
bool Block<Key>::IsFull() const {
  if (fill_ == block_size_) {
    return true;  
  }
  return false;
}

/**
 * @brief Método para imprimir el contenido de la secuencia
 * 
 * @tparam Key
 */
template <class Key>
void Block<Key>::Print() const {
  for (int i = 0; i < block_size_; ++i) {
    if (block_[i] != -1) {
      std::cout << block_[i] << " ";
    } else {
      std::cout << "- ";
    }
  }
}

#endif  // BLOCK_H_