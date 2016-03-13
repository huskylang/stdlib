#ifndef MATH_HPP
#define MATH_HPP

namespace husky { namespace stdlib { namespace math {

    husky::datatypes::AbstractDataType *router(
        Parser *, std::string, std::string, husky::datatypes::AbstractDataType **, int
    );

}}}

#endif
