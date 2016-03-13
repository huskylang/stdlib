#include <string>

#include "../../parser/inc/parser.hpp"
#include "../../parser/datatypes/inc/abstract.hpp"
#include "../../parser/datatypes/inc/number.hpp"

#include "math.hpp"
#include <cmath>

using namespace husky;

/*
 * Router for console module
 *
 */
datatypes::AbstractDataType *stdlib::math::router(
    husky::Parser *parser, std::string funname, std::string modname, \
    datatypes::AbstractDataType **arglist, int len
)
{
    datatypes::AbstractDataType *retval; // trick with a compiler

    if (funname == "pow") { // pow function
        if (len != 2) {
            parser->outhandler->error(
                "(stdlib, math, pow)", "in module '" + modname + "'" + "no match for pow/" + std::to_string(len),
                parser->line, parser->linen, parser->linei
            );
        }


        return new datatypes::Number(parser, pow(arglist[0]->getIntValue(), arglist[1]->getIntValue()));
    } else {
        // throw function not found error

        parser->outhandler->error(
            "(stdlib, module finder)", "function '" + funname + "' not found in module '" + modname + "'",
            parser->line, parser->linen, parser->linei
        );

        return retval;
    }
}
