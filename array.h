// array.h
#ifndef ATOM_ARRAY_H
#define ATOM_ARRAY_H

#include <exception>
#include "random_access_iterator.h"

namespace atom
{

template < class T, size_t N >
class array
{
    private:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const reference;
        using pointer = value_type*;
        using const_pointer = const pointer;
        using size_type = size_t;
        using iterator = random_access_iterator<T>;

    public:
        reference at( size_type pos )
        {
            if( !( pos < size() ) )
                throw std::out_of_range( std::string("get pos:") + std::to_string(pos) + " for size:" + std::to_string(N) );

            return _data[pos];
        }

        const_reference at( size_type pos ) const
        {
            if( !( pos < size() ) )
                throw std::out_of_range( std::string("get pos:") + std::to_string(pos) + " for size:" + std::to_string(N) );

            return _data[pos];
        }

        reference operator[]( size_type pos )
        {
            return _data[pos];
        }

        const_reference operator[]( size_type pos ) const
        {
            return _data[pos];
        }

        reference front()
        {
            return _data[0];
        }

        const_reference front() const
        {
            return _data[0];
        }

        reference back()
        {
            return _data[N-1];
        }

        const_reference back() const
        {
            return _data[N-1];
        }

        pointer data()
        {
            return _data;
        }

        const_pointer data() const
        {
            return _data;
        }

        iterator begin()
        {
            return _data;
        }

        iterator end()
        {
            return _data + N;
        }

        constexpr bool empty()
        {
            return !(N > 0);
        }

        size_type size()
        {
            return N;
        }

        constexpr size_type max_size()
        {
            return N;
        }

        void fill( const_reference value )
        {
            for( auto iter = begin(); iter != end(); ++iter )
                *iter = value;
        }

        void swap( array& other )
        {
            for( size_t i = 0; i < N; ++i )
            {
                auto tmp = other[i];
                other[i] = _data[i];
                _data[i] = tmp;
            }
        }

    public:
        T _data[N];
};

} // namespace atom

#include "array_bool.h"

#endif
