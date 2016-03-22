#include <string>

#include "inc/stdlib.hpp"

#include "console/console.hpp"
#include "math/math.hpp"

using namespace husky;


 /*
  * Returns a length of the module list
  *
  */
 int stdlib::modlist_len()
 {
     return 2;
 }

/*
 * Initializes a module list
 *
 */
lib::Module **stdlib::modlist()
{
    lib::Module **retval = (lib::Module **) malloc(sizeof(lib::Module) * stdlib::modlist_len());

    retval[0] = new stdlib::console::Console();
    retval[1] = new stdlib::math::Math();

    return retval;
}
