/**
 * @brief Declaración de la clase Sequence. Clase abstracta para implementar estructuras que almacenan valores de clave sinónimos.
 * 
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <iostream>

/**
 * @class Sequence
 * 
 * @brief Clase secuencia donde se almacenan los valores de clave sinónimos.
 * 
 * @tparam Key 
 */
template<class Key>
class Sequence {
  public:
    // método para buscar por el valor k en la secuencia
    virtual bool Search(const Key& k) const = 0;

    // método para insertar el valor k en la secuencia
    virtual bool Insert(const Key& k) = 0;

    // método para comprobar si la secuencia está llena
    virtual bool IsFull() const = 0;

    // método para imprimir el contenido de la secuencia
    virtual void Print() const = 0;
};

#endif  // SEQUENCE_H_