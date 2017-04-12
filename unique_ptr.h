#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

namespace atom
{

template<typename T>
class unique_ptr
{
    private:
        using value_type = T;
        using pointer = value_type*;

    public:
        explicit unique_ptr(pointer ptr)
            : _pointer(ptr)
        {}

        ~unique_ptr()
        {
            delete_pointer();
        }

        unique_ptr& operator=(unique_ptr&& other)
        {
            delete_pointer();

            _pointer = other._pointer;
            other._pointer = nullptr;
        }

        pointer release()
        {
            pointer tmp = _pointer;
            _pointer = nullptr;

            return tmp;
        }

        void reset(pointer ptr)
        {
            delete_pointer();

            _pointer = ptr;
        }

        void swap(unique_ptr& other)
        {
            pointer tmp = _pointer;
            _pointer = other._pointer;
            other._pointer = tmp;
        }

        operator bool()
        {
            return _pointer != nullptr;
        }

        pointer get()
        {
            return _pointer;
        }

        T& operator*() const
        {
            return *_pointer;
        }

        pointer operator->() const
        {
            return _pointer;
        }

    private:
        inline void delete_pointer()
        {
            if( _pointer )
                delete _pointer;

            _pointer = nullptr;
        }

    private:
        pointer _pointer;
};

} // namespace atom

#endif
