#include <string>

#include "../../parser/inc/parser.hpp"

#include "../../parser/datatypes/inc/abstract.hpp"
#include "../../parser/datatypes/inc/number.hpp"
#include "../../parser/datatypes/inc/atom.hpp"

#include "math.hpp"
#include <cmath>

using namespace husky::stdlib::math;

/*
 * Raises number to power
 *
 */
husky::datatypes::AbstractDataType *Pow::run(
    husky::Parser *parser,
    husky::datatypes::AbstractDataType **arglist,
    int len
)
{
    if (len != 2) {
        parser->error("(module manager)", "pow/2 takes 2 arguments");
        return new datatypes::Atom(parser, "bad");
    }

    return new datatypes::Number(
        parser,
        pow(arglist[0]->getIntValue(), arglist[1]->getIntValue())
    );
}
