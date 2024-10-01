/**
 * @brief Declaración de la clase feQuadratic. Clase que permite implementar la función de exploración cuadrática.
 * 
 */

#ifndef FE_QUADRATIC_H_
#define FE_QUADRATIC_H_

#include <iostream>
#include <math.h>

#include "exploration_function.h"

/**
 * @class feQuadratic
 * 
 * @brief Clase para poder implementar la función de exploración cuadrática.
 * 
 * @tparam Key 
 */
template<class Key>
class feQuadratic : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& k, unsigned i) const override;
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de exploración cuadrática
 * 
 * @tparam Key 
 * @param k 
 * @param i 
 * @return unsigned 
 */
template<class Key>
unsigned feQuadratic<Key>::operator()(const Key& k, unsigned i) const {  
  return pow(i,2);
} 

#endif  // FE_QUADRATIC_H_