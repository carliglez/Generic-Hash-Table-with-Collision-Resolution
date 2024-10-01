/**
 * @brief Declaración de la clase ExplorationFunction. Clase abstracta para implementar funciones de exploración.
 * 
 */

#ifndef EXPLORATION_FUNCTION_H_
#define EXPLORATION_FUNCTION_H_

#include <iostream>

/**
 * @class ExplorationFunction
 * 
 * @brief Clase abstracta para poder implementar funciones de exploración con clases concretas.
 * 
 * @tparam Key 
 */
template<class Key>
class ExplorationFunction {
  public:
    virtual unsigned operator()(const Key& k, unsigned i) const = 0;  
};

#endif  // EXPLORATION_FUNCTION_H_