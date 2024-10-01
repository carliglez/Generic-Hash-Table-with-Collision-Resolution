/**
 * @brief Declaración de la clase DispersionFunction. Clase abstracta para implementar funciones de dispersión.
 * 
 */

#ifndef DISPERSION_FUNCTION_H_
#define DISPERSION_FUNCTION_H_

#include <iostream>

/**
 * @class DispersionFunction
 * 
 * @brief Clase abstracta para poder implementar funciones de dispersión con clases concretas.
 * 
 * @tparam Key 
 */
template<class Key>
class DispersionFunction {
  public:
    virtual unsigned operator()(const Key& k) const = 0;  
};

#endif  // DISPERSION_FUNCTION_H_