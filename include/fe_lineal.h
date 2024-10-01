/**
 * @brief Declaración de la clase feLineal. Clase que permite implementar la función de exploración lineal.
 * 
 */

#ifndef FE_LINEAL_H_
#define FE_LINEAL_H_

#include <iostream>

#include "exploration_function.h"

/**
 * @class feLineal
 * 
 * @brief Clase para poder implementar la función de exploración lineal.
 * 
 * @tparam Key 
 */
template<class Key>
class feLineal : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& k, unsigned i) const override;
};


/**
 * @brief Sobrecarga del operador () para aplicar la función de exploración lineal
 * 
 * @tparam Key 
 * @param k 
 * @param i 
 * @return unsigned 
 */
template<class Key>
unsigned feLineal<Key>::operator()(const Key& k, unsigned i) const {
  return i;
} 

#endif  // FE_LINEAL_H_