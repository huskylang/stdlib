#include <string>

#include "../parser/inc/parser.hpp"
#include "../parser/datatypes/inc/abstract.hpp"

#include "console/console.hpp"
#include "math/math.hpp"

#include "inc/router.hpp"

using namespace husky;

/*
 * Runs function from the stdlib
 *
 * @param len, length of the arglist
 *
 */
datatypes::AbstractDataType *stdlib::run(
    Parser *parser, std::string funexpr, datatypes::AbstractDataType **arglist, int len
)
{
    int delimiter = funexpr.find(":"); // find an index of ':' delimiter in function expression

    datatypes::AbstractDataType *retval; // trick with a compiler

    std::string modname = funexpr.substr(0, delimiter); // take substring from start to delimiter

    if (modname == "cs") { // console module
        return stdlib::console::router(
            parser, funexpr.substr(delimiter + 1, funexpr.length()), modname, arglist, len
        );
    } else if (modname == "math") {
        return stdlib::math::router(
            parser, funexpr.substr(delimiter + 1, funexpr.length()), modname, arglist, len
        );
    } else {
        // throw module not found error

        parser->error(
            "(stdlib, module finder)", "module '" + modname + "' not found"
        );

        return retval;
    }
}
