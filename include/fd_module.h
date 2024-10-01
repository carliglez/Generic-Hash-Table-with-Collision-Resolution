/**
 * @brief Declaración de la clase fdModule. Clase que permite implementar la función de dispersión módulo.
 * 
 */

#ifndef FD_MODULE_H_
#define FD_MODULE_H_

#include <iostream>

#include "dispersion_function.h"

/**
 * @class fdModule
 * 
 * @brief Clase para poder implementar la función de dispersión módulo.
 * 
 * @tparam Key 
 */
template<class Key>
class fdModule : public DispersionFunction<Key> {
  public:
    fdModule(const unsigned n): table_size_(n) {}
    
    unsigned operator()(const Key& k) const override;

  private:
    unsigned table_size_;    
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de dispersión módulo
 * 
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template<class Key>
unsigned fdModule<Key>::operator()(const Key& k) const {
  return k % table_size_; 
} 

#endif  // FD_MODULE_H_