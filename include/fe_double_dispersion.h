/**
 * @brief Declaración de la clase feDoubleDispersion. Clase que permite implementar la función de exploración de doble dispersión.
 * 
 */

#ifndef FE_DOUBLE_DISPERSION_H_
#define FE_DOUBLE_DISPERSION_H_

#include <iostream>

#include "exploration_function.h"
#include "dispersion_function.h"

/**
 * @class feDoubleDispersion
 * 
 * @brief Clase para poder implementar la función de exploración de doble dispersión.
 * 
 * @tparam Key 
 */
template<class Key>
class feDoubleDispersion : public ExplorationFunction<Key> {
  public:
    feDoubleDispersion(DispersionFunction<Key> *fd): fd_(fd){}

    unsigned operator()(const Key& k, unsigned i) const override;

  private:
    DispersionFunction<Key> *fd_; 

};

/**
 * @brief Sobrecarga del operador () para aplicar la función de exploración de doble dispersión
 * 
 * @tparam Key 
 * @param k 
 * @param i 
 * @return unsigned 
 */
template<class Key>
unsigned feDoubleDispersion<Key>::operator()(const Key& k, unsigned i) const {
  return fd_->operator()(k)* i;
} 

#endif  // FE_DOUBLE_DISPERSION_H_