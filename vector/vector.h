
#pragma once

#include <cstdlib>

namespace vec {


template <class T> 
class vector {
	private:
		using value_type = T;
		using size_type = size_t;
		using reference = value_type&;
		using const_reference = value_type&;
		using iterator = T*;
		using const_iterator = const iterator;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>; 

		T* data_;

		size_type current_size_;

		size_type capacity_;

	public:
		vector() : 
			data_(new T[0]), 
			current_size_(0), 
			capacity_(0)
			{} ;
		
		explicit vector(size_type count, const T& value = T() ) : 
			data_(new T[count]),
			current_size_(count),
			capacity_(count) {
		
					for (size_type i = 0; i < count; ++i) {
						data_[i] = value;
				}

		}

		vector(const vector& other) : 
			data_(new T[other.size()]), 
			current_size_(other.size()), 
			capacity_(other.size()) {

				for (size_t i = 0; i < other.size(); ++i) {
					data_[i] = other.data_[i];
				}

		}

		vector(vector&& other) : 
			data_(std::move(other.data_)), 
			current_size_(std::move(other.current_size_)), 
			capacity_(std::move(other.capacity_)) 
			{};

		~vector() {
			delete[] data_;
			current_size_ = 0;
			capacity_ = 0;
		}

		vector& operator=(const vector& other) {

			data_ = new T[other.size()];
			current_size_ = other.size();
			capacity_ = other.size();

			for (size_t i = 0; i < other.size(); ++i) {
				data_[i] = other.data_[i];
			}

		};

		vector& operator=(vector&& other) {
			data_ = std::move(other.data_);
			current_size_ = std::move(other.current_size_);
			capacity_ = std::move(other.capacity_);
		} 

		void assign(size_type count, const T& value) {
			data_ = (T*) realloc(data_, count * sizeof(T));
			current_size_ = count;
			capacity_ = count;

			for (size_type i = 0; i < count; ++i) {
				data_[i] = value;
			}

		}

		reference at(size_type pos) {
			if (pos >= 0 && pos <= current_size_) return data_[pos];
			else {
				throw std::out_of_range("Index is out of range");
			}
		}

		const_reference at(size_type pos) const {
			if (pos >= 0 && pos <= current_size_) return data_[pos];
			else {
				throw std::out_of_range("Index is out of range");
			}
		}

		reference operator[](size_type pos) {
			if (pos >= 0 && pos <= current_size_) return data_[pos];
			else {
				throw std::out_of_range("Index is out of range");
			}
		}

		const_reference operator[](size_type pos) const {
			if (pos >= 0 && pos <= current_size_) return data_[pos];
			else {
				throw std::out_of_range("Index is out of range");
			}
		}

		reference front() {
			if (data_ && current_size_) return data_[0];
			else throw std::out_of_range("Can't access front element of empty vector");
		}

		const_reference front() const {
			if (data_ && current_size_) return data_[0];
			else throw std::out_of_range("Can't access front element of empty vector");
		}

		reference back() {
			if (data_ && current_size_) return data_[current_size_ - 1];
			else throw std::out_of_range("Can't access back element of empty vector");
		}

		const_reference back() const {
			if (data_ && current_size_) return data_[current_size_ - 1];
			else throw std::out_of_range("Can't access back element of empty vector");
		}

		bool empty() const {
			return current_size_ == 0;
		}

		size_type size() const {
			return current_size_;
		}

		size_type capacity() const {
			return capacity_;
		}

		void reserve(size_type new_capacity) {
			if (new_capacity <= capacity()) return;
			data_ = (T*) realloc(data_, new_capacity * sizeof(T));
			capacity_ = new_capacity;
		}

		void shrink_to_fit() {
			if (capacity() == size()) return;
			data_ = (T*) realloc(data_, size() * sizeof(T));
			capacity_ = size();
		}

		void clear() {
			T item;
			assign(capacity(), item);
			current_size_ = 0;
		}

		void push_back(const T& value) {
			if (size() == capacity()) {
				data_ = (T*) realloc(data_, capacity() * 2 * sizeof(T));
				data_[size()] = value;
				++current_size_;
				if (!capacity()) capacity_ = 1;
				else capacity_ *= 2;
				return;
			}

			data_[size()] = value;
			++current_size_;
		}

		void pop_back() {
			if (data_ && size()) {
				--current_size_;
			} else {
				throw std::out_of_range("Cant pop last element of empty vector");
			}
		}

		void resize(size_type count) {

			if (size() >= count) {
				data_ = (T*) realloc(data_, count * sizeof(T));
				current_size_ = count;
				capacity_ = count;
			} else {
				data_ = (T*) realloc(data_, count * sizeof(T));
				
				for (size_t i = size(); i < count; ++i) {
					data_[i] = T();
				}

				current_size_ = count;
				capacity_ = count;
			}

		}

		void resize(size_type count, const value_type& value) {
			
			if (size() >= count) {
				data_ = (T*) realloc(data_, count * sizeof(T));
				current_size_ = count;
				capacity_ = count;
			} else {
				data_ = (T*) realloc(data_, count * sizeof(T));

				for (size_t i = size(); i < count; ++i) {
					data_[i] = value;
				}

				current_size_ = count;
				capacity_ = count;
			}
		
		}	

		iterator begin() {
			return data_;
		}

		const_iterator begin() const {
			return data_;
		}

		const_iterator cbegin() const {
			return data_;
		}

		iterator end() {
			return (data_ + size());
		}

		const_iterator end() const {
			return (data_ + size());
		}

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