#ifndef ROUTER_STDLIB_HPP
#define ROUTER_STDLIB_HPP

namespace husky { namespace stdlib {

    husky::datatypes::AbstractDataType *run(
        husky::Parser*, std::string, husky::datatypes::AbstractDataType**, int
    );

}}

#endif
