/**
 * @brief Declaración de la clase fdSum. Clase que permite implementar la función de dispersión basada en la suma.
 * 
 */

#ifndef FD_SUM_H_
#define FD_SUM_H_

#include <iostream>

#include "dispersion_function.h"

/**
 * @class fdSum
 * 
 * @brief Clase para poder implementar la función de dispersión basada en la suma.
 * 
 * @tparam Key 
 */
template<class Key>
class fdSum : public DispersionFunction<Key> {
  public:
    fdSum(const unsigned n): table_size_(n) {}
    
    unsigned operator()(const Key& k) const override;

  private:
    unsigned table_size_;    
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de dispersión basada en la suma
 * 
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template<class Key>
unsigned fdSum<Key>::operator()(const Key& k) const {
  unsigned d = 0;
  Key x = k;
  while (x > 0) {
    unsigned y = x % 10;
    d = d + y;
    x = x / 10;
  }
  return d % table_size_;  
} 

#endif  // FD_SUM_H_