/**
 * @brief Declaración de la clase List. Se trata de una clase para trabajar con dispersión abierta.
 * 
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <vector>

#include "sequence.h"

/**
 * @class List
 * 
 * @brief Clase lista necesaria para la implementación de la técnica de dispersión abierta.
 * 
 * @tparam Key 
 */
template<class Key>
class List : public Sequence<Key> {
  public:
    bool Search(const Key& k) const override;

    bool Insert(const Key& k) override;

    bool IsFull() const override;

    void Print() const override;
  
  private:
    std::vector<Key> list_;    
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
bool List<Key>::Search(const Key& k) const {
  for (int i = 0; i < list_.size(); ++i) {
    if (list_[i] == k) {
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
bool List<Key>::Insert(const Key& k) {
  list_.push_back(k);
  return true;
}

/**
 * @brief Método para comprobar si la secuencia está llena
 * 
 * @tparam Key 
 * @return true 
 * @return false 
 */
template<class Key>
bool List<Key>::IsFull() const {
  return false;
}

/**
 * @brief Método para imprimir el contenido de la secuencia
 * 
 * @tparam Key
 */
template<class Key>
void List<Key>::Print() const {
  for (int i = 0; i < list_.size(); ++i) {
    std::cout << list_[i] << " ";
  }
  std::cout << std::endl;
}

#endif  // LIST_H_