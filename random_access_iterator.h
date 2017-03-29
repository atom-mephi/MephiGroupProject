// random_access_iterator.h
#ifndef ATOM_RANDOM_ACCESS_ITERATOR_H
#define ATOM_RANDOM_ACCESS_ITERATOR_H

namespace atom
{

template<typename T>
class random_access_iterator
{
    private:
        using value_type = T;
        using difference_type = int;
        using reference = value_type&;
        using const_reference = const reference;
        using pointer = value_type*;

    public:
        random_access_iterator(pointer p)
            : _pointer(p)
        {}

        reference operator*()
        {
            return *_pointer;
        }

        random_access_iterator& operator++()
        {
            _pointer++;
            return *this;
        }

        random_access_iterator operator++(int)
        {
            auto tmp = *this;
            operator++();
            return tmp;
        }

        bool operator==(const random_access_iterator& that)
        {
            return _pointer == that._pointer;
        }

        pointer operator->()
        {
            return _pointer;
        }

        random_access_iterator& operator--()
        {
            _pointer--;
            return *this;
        }

        random_access_iterator operator--(int)
        {
            auto tmp = *this;
            operator--();
            return tmp;
        }

        random_access_iterator& operator+=(difference_type difference)
        {
            _pointer += difference;
            return *this;
        }

        random_access_iterator operator+(difference_type difference)
        {
            auto tmp = *this;
            return tmp += difference;
        }

        random_access_iterator& operator-=(difference_type difference)
        {
            operator+=(-difference);
            return *this;
        }

        random_access_iterator operator-(difference_type difference)
        {
            auto tmp = *this;
            return tmp -= difference;
        }

    private:
        pointer _pointer;
};

} // namespace atom

#endif
