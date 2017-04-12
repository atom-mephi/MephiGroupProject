// array_bool.h
#ifndef ATOM_ARRAY_BOOL_H
#define ATOM_ARRAY_BOOL_H

#include <exception>
#include "random_access_iterator.h"

namespace atom
{

template < size_t N >
class array<bool, N>
{
    private:
        using size_type = size_t;
        using host_type = char;

    public:
        class boolReference
        {
            public:
                boolReference(host_type* const data, size_t pos)
                    : _data(data)
                    , _pos(pos)
                {}

                bool operator=(bool value)
                {
                    setValue(value);
                    return value;
                }

                operator bool()
                {
                    return getValue();
                }

                bool operator*()
                {
                    return getValue();
                }

            private:
                void setValue( bool value)
                {
                    if( value )
                        *(_data + (_pos/sizeof(host_type))) |= 1 << _pos%sizeof(host_type);
                    else
                        *(_data + (_pos/sizeof(host_type))) &= 0 << _pos%sizeof(host_type);
                }

                bool getValue()
                {
                    host_type* iter = _data + (_pos/sizeof(host_type));
                    host_type elem = 1 << (_pos % sizeof(host_type));

                    return (bool)( *iter & elem );
                }

            private:
                host_type* const _data;
                size_t _pos;
        };

    private:
        using reference = boolReference;

    public:
        class bool_array_iterator
        {
            private:
                using reference = boolReference;
                using host_type = char;

            public:
                bool_array_iterator(host_type* const data, size_t pos)
                    : _data(data)
                    , _pos(pos)
                {}

                reference operator*()
                {
                    return boolReference(_data, _pos);
                }

                bool_array_iterator& operator++()
                {
                    _pos++;
                    return *this;
                }

                bool_array_iterator operator++(int)
                {
                    auto tmp = *this;
                    operator++();
                    return tmp;
                }

                bool operator==(const bool_array_iterator& that)
                {
                    return _data == that._data && _pos == that._pos;
                }

                bool operator!=(const bool_array_iterator& that)
                {
                    return !operator==(that);
                }

                bool_array_iterator& operator--()
                {
                    --_pos;
                    return *this;
                }

                bool_array_iterator operator--(int)
                {
                    auto tmp = *this;
                    operator--();
                    return tmp;
                }

            private:
                host_type* const _data;
                size_t _pos;
        };

    private:
        using iterator = bool_array_iterator;

    public:
        reference operator[]( size_type pos )
        {
            return boolReference(_data, pos);
        }

        reference front()
        {
            return boolReference(_data, 0);
        }

        reference back()
        {
            return boolReference(_data, N-1);
        }

        iterator begin()
        {
            return bool_array_iterator(_data, 0);
        }

        iterator end()
        {
            return bool_array_iterator(_data, N);
        }

        bool empty()
        {
            return !(N > 0);
        }

        size_type size()
        {
            return N;
        }

    public:
        host_type _data[N / sizeof(host_type) + ( N % sizeof(host_type) ? 0 : 1 )];
};

} // namespace atom

#endif
