#ifndef LIB_MODULE_HPP
#define LIB_MODULE_HPP

#include "module_function.hpp"

 namespace husky { namespace lib {

    class Module
    {
        public:
            virtual ModFunction **getFuns() = 0;
            virtual int getFunsLen() = 0;
            virtual std::string getName() = 0;
    };

}}

#endif
