/**
 * @brief Declaración de la clase fdPseudorandom. Clase que permite implementar la función de dispersión pseudo-aleatoria.
 * 
 */

#ifndef FD_PSEUDORANDOM_H_
#define FD_PSEUDORANDOM_H_

#include <iostream>

#include "dispersion_function.h"

/**
 * @class fdPseudorandom
 * 
 * @brief Clase para poder implementar la función de dispersión pseudo-aleatoria.
 * 
 * @tparam Key 
 */
template<class Key>
class fdPseudorandom : public DispersionFunction<Key> {
  public:
    fdPseudorandom(const unsigned n): table_size_(n) {}
    
    unsigned operator()(const Key& k) const override;

  private:
    unsigned table_size_;    
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de dispersión pseudo-aleatoria
 * 
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template<class Key>
unsigned fdPseudorandom<Key>::operator()(const Key& k) const {
  srand(k);
  return rand() % table_size_; 
} 

#endif  // FD_PSEUDORANDOM_H_