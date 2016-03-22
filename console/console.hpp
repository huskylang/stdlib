#ifndef CONSOLE_STDLIB_HPP
#define CONSOLE_STDLIB_HPP

#include <string>

#include "../inc/module.hpp"

#include "../../parser/inc/parser.hpp"
#include "../inc/module_function.hpp"
#include "../../parser/datatypes/inc/abstract.hpp"

namespace husky { namespace stdlib { namespace console {

    class Inl : public husky::lib::ModFunction
    {
        public:
            virtual husky::datatypes::AbstractDataType *run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len);
            virtual std::string getName() { return "inl"; };
    };

    class Out : public husky::lib::ModFunction
    {
        public:
            virtual husky::datatypes::AbstractDataType *run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len);
            virtual std::string getName() { return "out"; };
    };

    class Outl : public husky::lib::ModFunction
    {
        public:
            virtual husky::datatypes::AbstractDataType *run(husky::Parser *parser, husky::datatypes::AbstractDataType **arglist, int len);
            virtual std::string getName() { return "outl"; };
    };

    class Console : public husky::lib::Module
    {
        private:
            husky::lib::ModFunction **funs;
            int funs_len = 3;

        public:
            Console() {
                this->funs = (husky::lib::ModFunction**) malloc(sizeof(husky::lib::ModFunction) * this->funs_len);

                this->funs[0] = new Inl();
                this->funs[1] = new Out();
                this->funs[2] = new Outl();
            };

            virtual std::string getName() { return "cs"; };
            virtual husky::lib::ModFunction **getFuns() { return (husky::lib::ModFunction**) this->funs; };

            virtual int getFunsLen() { return this->funs_len; };
    };

}}}

#endif
