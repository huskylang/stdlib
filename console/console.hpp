#ifndef CONSOLE_STDLIB_HPP
#define CONSOLE_STDLIB_HPP


namespace husky { namespace stdlib { namespace console {

    husky::datatypes::AbstractDataType *router(
        Parser *, std::string, std::string, husky::datatypes::AbstractDataType **, int
    );

}}}

#endif
