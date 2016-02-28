#include <string>

#include "../../src/parser/inc/parser.hpp"
#include "../../src/parser/datatypes/inc/abstract.hpp"
#include "../../src/parser/datatypes/inc/string.hpp"

#include "console.hpp"

using namespace husky;

/*
 * Prints the args to the stdout
 *
 */
datatypes::AbstractDataType *out(husky::Parser *parser, datatypes::AbstractDataType **arglist, int len)
{
    int i;

    datatypes::AbstractDataType *retval; // trick with a compiler


    for (i = 0; i < len; i++)
    {
        parser->outhandler->print(arglist[i]->getStrValue());
    }

    return retval;
}


/*
 * Prints args with the endline character to the stdout
 *
 */
datatypes::AbstractDataType *outl(husky::Parser *parser, datatypes::AbstractDataType **arglist, int len)
{
    datatypes::AbstractDataType *retval = out(parser, arglist, len);

    parser->outhandler->printline("");

    return retval;
}

/*
 * Gets a line from the stdin
 *
 * @returns String datatype
 *
 */
datatypes::AbstractDataType *inl(husky::Parser *parser, datatypes::AbstractDataType **arglist, int len)
{
    return new datatypes::String(parser, parser->inhandler->getLine());
}

/*
 * Router for console module
 *
 */
datatypes::AbstractDataType *stdlib::console::router(
    husky::Parser *parser, std::string funname, std::string modname, \
    datatypes::AbstractDataType **arglist, int len
)
{
    datatypes::AbstractDataType *retval; // trick with a compiler

    if (funname == "out") { // out function
        return out(parser, arglist, len);
    } else if (funname == "outl") {
        return outl(parser, arglist, len);
    } else if (funname == "inl") {
        return inl(parser, arglist, len);
    } else {
        // throw function not found error

        parser->outhandler->error(
            "(stdlib, module finder)", "function '" + funname + "' not found in module '" + modname + "'",
            parser->line, parser->linen, parser->linei
        );

        return retval;
    }
}
