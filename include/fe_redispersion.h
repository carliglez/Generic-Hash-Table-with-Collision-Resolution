/**
 * @brief Declaración de la clase feRedispersion. Clase que permite implementar la función de exploración de redispersión.
 * 
 */

#ifndef FE_REDISPERSION_H_
#define FE_REDISPERSION_H_

#include <iostream>

#include "exploration_function.h"

/**
 * @class feRedispersion
 * 
 * @brief Clase para poder implementar la función de exploración de redispersión.
 * 
 * @tparam Key 
 */
template<class Key>
class feRedispersion : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& k, unsigned i) const override;
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de exploración de redispersión
 * 
 * @tparam Key 
 * @param k 
 * @param i 
 * @return unsigned 
 */
template<class Key>
unsigned feRedispersion<Key>::operator()(const Key& k, unsigned i) const {
  int value = 0;
  srand(k);
  for (int j = 0; j < i; ++j) {
    value = rand();
  }
  return value;
} 

#endif  // FE_REDISPERSION_H_