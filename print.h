// array.h
#ifndef ATOM_PRINT_H
#define ATOM_PRINT_H

#include <cstdio>

namespace atom
{


template<typename T>
void print( T arg )
{
    print( std::to_string(arg).c_str() );
}

template<>
void print( const char* str )
{
    while(*str)
        putchar(*str++);
}

template<>
inline void print( const std::string str )
{
    print(str.c_str());
}

template<typename T, typename ... U>
void print( const char* format, T arg, U ... args )
{
    while( *format && *format != '%' )
        putchar(*format++);

    if( *format == '%' )
    {
        print( arg );
        print( ++format, args ... );
    }
}

} // namespace atom

#endif
