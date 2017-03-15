// array.h
#ifndef ATOM_ARRAY_H
#define ATOM_ARRAY_H

template < class T, size_t N >
class Array
{
    public:
        Array();
        ~Array();

    private:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const reference;
        using pointer = value_type*;
        using const_pointer = const pointer;
};

#endif
