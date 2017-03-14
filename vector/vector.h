
#pragma once

#include <cstdlib>

namespace vec {

#ifndef DUMP
#define DUMP(START_dump_constants::END_STATE)					\
		dump(__PRETTY_FUNCTION__, START_dump_constants::END_STATE)
#endif

namespace dump_constants {
	const std::string DUMP_FILE_NAME = "dump_file.txt";
	const std::string START_STATE = "START";
	const std::string END_STATE = "END";
}


template <class T> 
class vector {
	private:
		using value_type = T;
		using size_type = size_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const iterator;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>; 

		T* data_;

		size_type current_size_;

		size_type capacity_;

		const int MULTIPLY_CONST = 2;

		/**
		 * increase capacity by MULTIPLY_CONST
		 */
		void grow() {
			if (capacity()) {
				data_ = (T*) realloc(data_, capacity() * MULTIPLY_CONST * sizeof(T));

				if (!data_) {
					throw std::bad_alloc();
				}

				capacity_ *= MULTIPLY_CONST;
			}	else {
				data_ = (T*) realloc(data_, sizeof(T));

				if (!data_) {
					throw std::bad_alloc();
				}

				capacity_ = 1;
			}
		}

		/**
		 * Operator new overloading for constructing at specific memory position. 
		 * @param  size Size of element.
		 * @param  mem  Pointer to a memory.
		 * @return      Pointer to a memory where element will be constructed.
		 */
		void* operator new (size_t size, void* mem) {
			return mem;
		}


		void dump(const std::string& function_description, const std::string& state) const {
			std::ofstream dump_out(dump_constants::DUMP_FILE_NAME.c_str(), std::ios::app);

			dump_out << std::endl << state << " function : " << function_description << std::endl;
			dump_out << "Current size: " << size() << std::endl << "Current capacity: " << capacity() << std::endl;

			for (size_t i = 0; i < size(); ++i) {
				dump_out << "[" << i << "]" << " = " << data_[i] << std::endl;
			}
			dump_out << std::endl;
		}

	public:

		/**
		 * Default constructor
		 */
		vector() : 
			data_(new T[0]), 
			current_size_(0), 
			capacity_(0)
			{} ;
		
		/**
		 * Construct vector of count elements.
		 * @param  count Number of elements to construct;
		 * @param  value Values to be filled.
		 */
		explicit vector(size_type count, const T& value = T() ) : 
			data_(new T[count]),
			current_size_(count),
			capacity_(count) {
		
				for (size_type i = 0; i < count; ++i) {
					data_[i] = value;
				}

		}

		/**
		 * Construct vector out of another vector.
		 */
		vector(const vector& other) :
			data_(new T[other.size()]),  
			current_size_(other.size()), 
			capacity_(other.size()) {

				std::copy(other.begin(), other.end(), begin());

		}

		/**
		 * Move constructor.
		 */
		vector(vector&& other) : 
			data_(other.data_), 
			current_size_(other.current_size_), 
			capacity_(other.capacity_) 
			{	
				other.data_ = nullptr;
				other.current_size_ = 0;
				other.capacity_ = 0;
			};

		/**
		 * Destructor.
		 */
		~vector() {
			delete[] data_;
			current_size_ = 0;
			capacity_ = 0;
		}

		/**
		 * Operator = overloading.
		 */
		vector& operator=(const vector& other) {

			if (&other == this) return *this;
			
			~vector();
			new (this) vector(other);
		
		};

		/**
		 * Move semantics for operator = overloading.
		 */
		vector& operator=(vector&& other) {
			
			data_ = other.data_;
			current_size_ = other.current_size_;
			capacity_ = other.capacity_;

			other.data_ = nullptr;
			current_size_ = 0;
			capacity_ = 0;
		} 


		/**
		 * Assign count element to a specific value. Capacity and size will be set to count.
		 * @param count New capacity and size of the vector.
		 * @param value Value to be filled.
		 */
		void assign(size_type count, const T& value) {

			DUMP(dump_constants::START_STATE);

			data_ = (T*) realloc(data_, count * sizeof(T));

			if (!data_) {
				throw std::bad_alloc();
			}

			current_size_ = count;
			capacity_ = count;

			memset(data_, value, count);

			DUMP(dump_constants::END_STATE);
		}

		/**
		 * Safe realization of operator[]. Will throw std::out_of_range() exception if pos is invalid.
		 * @param  pos Index of the element to be accessed.
		 * @return     Reference to the elemet.
		 */
		reference at(size_type pos) {
			if (pos >= 0 && pos <= current_size_) return data_[pos];
			else {
				throw std::out_of_range("Index is out of range");
			}
		}

		/**
		 * Safe realization of operator[]. Will throw std::out_of_range() exception if pos is invalid.
		 * @param  pos Index of the element to be accessed.
		 * @return     Const reference to the elemet.
		 */
		const_reference at(size_type pos) const {
			if (pos >= 0 && pos <= current_size_) return data_[pos];
			else {
				throw std::out_of_range("Index is out of range");
			}
		}

		/**
		 * Operator[] overloading. Does not throw any exception if pos is invalid.
		 * @param  pos Index of the element to be accessed.
		 * @return     Reference to the elemet.
		 */
		reference operator[](size_type pos) {
			return data_[pos];
		}

		/**
		 * Operator[] overloading. Does not throw any exception if pos is invalid.
		 * @param  pos Index of the element to be accessed.
		 * @return     Const reference to the elemet.
		 */
		const_reference operator[](size_type pos) const {
			return data_[pos];
		}

		/**
		 * Accessing first element of the vector.
		 * @return Reference to the first element of the vector.
		 */
		reference front() {
			if (data_ && current_size_) return data_[0];
			else throw std::out_of_range("Can't access front element of empty vector");
		}

		/**
		 * Accessing first element of the vector.
		 * @return Const reference to the first element of the vector.
		 */
		const_reference front() const {
			if (data_ && current_size_) return data_[0];
			else throw std::out_of_range("Can't access front element of empty vector");
		}

		/**
		 * Accessing last element of the vector.
		 * @return Reference to the last element of the vector.
		 */
		reference back() {
			if (data_ && current_size_) return data_[current_size_ - 1];
			else throw std::out_of_range("Can't access back element of empty vector");
		}

		/**
		 * Accessing last element of the vector.
		 * @return Const reference to the last element of the vector.
		 */
		const_reference back() const {
			if (data_ && current_size_) return data_[current_size_ - 1];
			else throw std::out_of_range("Can't access back element of empty vector");
		}

		/**
		 * Check whether vector is empty.
		 * @return True if size == 0, Else otherwise.
		 */
		bool empty() const {
			return current_size_ == 0;
		}

		/**
		 * Get current size of the vector.
		 * @return Size of the vector.
		 */
		size_type size() const {
			return current_size_;
		}

		/**
		 * Get current capacity of the vector.
		 * @return Capacity of the vector.
		 */
		size_type capacity() const {
			return capacity_;
		}

		/**
		 * Reserve memory for new_capacity elements. Does nothing if new_capacity is less than old capacity,
		 * otherwise reserves memory for new_capacity elements.
		 * @param new_capacity New capacity of the vector.
		 */
		void reserve(const size_type& new_capacity) {

			DUMP(dump_constants::START_STATE);

			if (new_capacity <= capacity()) return;
			data_ = (T*) realloc(data_, new_capacity * sizeof(T));

			if (!data_) {
				throw std::bad_alloc();
			}

			capacity_ = new_capacity;
		
			DUMP(dump_constants::END_STATE);
		}

		/**
		 * Shrinks vector's capacity to it's size.
		 */
		void shrink_to_fit() {

			DUMP(dump_constants::START_STATE);

			if (capacity() == size()) return;
			data_ = (T*) realloc(data_, size() * sizeof(T));

			if (!data_) {
				throw std::bad_alloc();
			}

			capacity_ = size();

			DUMP(dump_constants::END_STATE);
		}

		/**
		 * Clear vector's content. Capacity remains unchanged.
		 */
		void clear() {

			DUMP(dump_constants::START_STATE);

			T item;
			assign(capacity(), item);
			current_size_ = 0;

			DUMP(dump_constants::END_STATE);
		}

		/**
		 * Append value to the end of vector.
		 * @param value Value to be appended.
		 */
		void push_back(const T& value) {

			DUMP(dump_constants::START_STATE);

			if (size() == capacity()) {
				grow();
			}

			data_[size()] = value;
			++current_size_;

			DUMP(dump_constants::END_STATE);
		}

		/**
		 * Construct object with value at the end of vector.
		 * @param value Value to be constructed.
		 */
		void emplace_back(const T& value) {

			DUMP(dump_constants::START_STATE);

			if (size() == capacity()) {
				grow();

				new (end()) T(value);

				++current_size_;
			}

			DUMP(dump_constants::END_STATE);
		}

		/**
		 * Remove last element of the vector. Throws std::out_of_range exception if vector is empty. 
		 */
		void pop_back() {
			
			DUMP(dump_constants::START_STATE);

			if (data_ && size()) {
				--current_size_;
			} else {
				throw std::out_of_range("Cant pop last element of empty vector");
			}

			DUMP(dump_constants::END_STATE);
		}

		/**
		 * Set size and capacity of the vector to count. Fill it with the default T value.
		 * @param count New size and capacity of the vector.
		 */
		void resize(size_type count) {

			DUMP(dump_constants::START_STATE);

			data_ = (T*) realloc(data_, count * sizeof(T));

			if (!data_) {
				throw std::bad_alloc();
			}

			current_size_ = count;
			capacity_ = count;

			for (size_t i = size(); i < count; ++i) {
				data_[i] = T();
			}

			DUMP(dump_constants::END_STATE);
		}

		/**
		 * Set size and capacity of the vector to count. Fill it with given value.
		 * @param count New size and capacity of the vector.
		 * @param value Fill vector's content with given value.
		 */
		void resize(size_type count, const value_type& value) {
			
			DUMP(dump_constants::START_STATE);

			data_ = (T*) realloc(data_, count * sizeof(T));
			current_size_ = count;
			capacity_ = count;

			for (size_t i = size(); i < count; ++i) {
				data_[i] = value;
			}

			DUMP(dump_constants::END_STATE);
		}	

		/**
		 * Pointer to the first element.
		 * @return Pointer to the first element.
		 */
		iterator begin() {
			return data_;
		}

		/**
		 * Pointer to the first element/
		 * @return Const pointer.
		 */
		const_iterator begin() const {
			return data_;
		}

		/**
		 * Pointer to the first element/
		 * @return Const pointer.
		 */
		const_iterator cbegin() const {
			return data_;
		}

		/**
		 * Pointer to the next to last element.
		 * @return Pointer to the next to last element.
		 */
		iterator end() {
			return (data_ + size());
		}

		/**
		 * Pointer to the next to last element.
		 * @return Const pointer to the next to last element.
		 */
		const_iterator end() const {
			return (data_ + size());
		}

		/**
		 * Pointer to the next to last element.
		 * @return Const pointer to the next to last element.
		 */
		const_iterator cend() const {
			return (data_ + size());
		}

		reverse_iterator rend() {
			return reverse_iterator(data_);
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(data_);
		}

		const_reverse_iterator crend() const {
			return const_reverse_iterator(data_);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(data_ + size());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(data_ + size());
		}

		const_reverse_iterator crbegin() const {
			return const_reverse_iterator(data_ + size());
		}
};


}//namespace ended