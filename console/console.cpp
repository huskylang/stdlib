#include <string>

#include "../../parser/inc/parser.hpp"

#include "../../parser/datatypes/inc/abstract.hpp"
#include "../../parser/datatypes/inc/string.hpp"
#include "../../parser/datatypes/inc/atom.hpp"

#include "console.hpp"

using namespace husky::stdlib::console;

/*
 * Prints the args to the stdout
 *
 */
husky::datatypes::AbstractDataType *Out::run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        parser->outhandler->print(arglist[i]->getStrValue());
    }

    return new husky::datatypes::Atom(parser, "good");
}


/*
 * Prints args with the endline character to the stdout
 *
 */
husky::datatypes::AbstractDataType *Outl::run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        parser->outhandler->print(arglist[i]->getStrValue());
    }

    parser->outhandler->printline("");

    return new husky::datatypes::Atom(parser, "good");;
}

/*
 * Gets a line from the stdin
 *
 * @returns String datatype
 *
 */
husky::datatypes::AbstractDataType *Inl::run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len)
{
    return new husky::datatypes::String(parser, parser->inhandler->getLine());
}
