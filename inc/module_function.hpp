#ifndef MODULE_FUNCTION_HPP
#define MODULE_FUNCTION_HPP

#include <string>

#include "../../parser/datatypes/inc/abstract.hpp"
#include "../../parser/inc/parser.hpp"

/*
 * TODO: create constructor from normal function datatype
 *
 */

 namespace lib {

    class ModFunction
    {
        public:
            virtual husky::datatypes::AbstractDataType *run(husky::Parser *, husky::datatypes::AbstractDataType **, int) = 0;

            virtual std::string getName() = 0;
            // virtual bool checkArgs(AbstractDataType **) { return true; };
    };

}

#endif
