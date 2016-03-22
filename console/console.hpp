#ifndef CONSOLE_STDLIB_HPP
#define CONSOLE_STDLIB_HPP

#include <string>

#include "../inc/module.hpp"

#include "../../parser/inc/parser.hpp"
#include "../inc/module_function.hpp"
#include "../../parser/datatypes/inc/abstract.hpp"

namespace husky { namespace stdlib { namespace console {

    class Inl : public lib::ModFunction
    {
        public:
            virtual husky::datatypes::AbstractDataType *run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len);
            virtual std::string getName() { return "inl"; };
    };

    class Out : public lib::ModFunction
    {
        public:
            virtual husky::datatypes::AbstractDataType *run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len);
            virtual std::string getName() { return "out"; };
    };

    class Outl : public lib::ModFunction
    {
        public:
            virtual husky::datatypes::AbstractDataType *run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len);
            virtual std::string getName() { return "outl"; };
    };

    class Console : public lib::Module
    {
        private:
            lib::ModFunction **funs;
            int funs_len = 3;

        public:
            Console() {
                this->funs = (lib::ModFunction**) malloc(sizeof(lib::ModFunction) * this->funs_len);

                this->funs[0] = new Inl();
                this->funs[1] = new Out();
                this->funs[2] = new Outl();
            };

            virtual std::string getName() { return "cs"; };
            virtual lib::ModFunction **getFuns() { return (lib::ModFunction**) this->funs; };

            virtual int getFunsLen() { return this->funs_len; };
    };

}}}

#endif
