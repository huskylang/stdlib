#ifndef MATH_HPP
#define MATH_HPP

#include <string>

#include "../inc/module.hpp"

#include "../../parser/inc/parser.hpp"
#include "../inc/module_function.hpp"
#include "../../parser/datatypes/inc/abstract.hpp"

namespace husky { namespace stdlib { namespace math {

    class Pow : public lib::ModFunction
    {
        public:
            virtual husky::datatypes::AbstractDataType *run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len);
            virtual std::string getName() { return "pow"; };
    };

    class Math : public lib::Module
    {
        private:
            lib::ModFunction **funs;
            int funs_len = 1;

        public:
            Math() {
                this->funs = (lib::ModFunction**) malloc(sizeof(lib::ModFunction) * this->funs_len);

                this->funs[0] = new Pow();
            };

            virtual std::string getName() { return "math"; };
            virtual lib::ModFunction **getFuns() { return (lib::ModFunction**) this->funs; };

            virtual int getFunsLen() { return this->funs_len; };
    };

}}}

#endif
