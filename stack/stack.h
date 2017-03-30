/**
 * @file stack.h
 * Implements a stack class
 * @author Givemetips, 2017
 */


#pragma once

#include <fstream>
#include <string>
#include <deque>

/**
 * Macro for check state of stack
 * @return [description]
 */

namespace stck {

#define DUMP(START_END_STATE) 					 	\
	dump(__PRETTY_FUNCTION__, START_END_STATE);  	\

/**
 * constants namespace
 */
namespace constants {
	const std::string DUMP_FILE_NAME = "dump_file.txt";
	const std::string START_STATE = "START";
	const std::string END_STATE = "END";
};

/**
 *  stack class
 */
template <class T, class Container = std::deque<T> > class stack {
private:
	/**
	 * container of elements
	 */
	Container container_;

	/**
	 * dump function to check stack's state
	 * @param function_type string recieved out of __PRETTY_FUNCTION__
	 * @param condition define whether dump was called before function or after;
	 */
	void dump(const std::string& function_type, const std::string& condition) const {
		std::ofstream dump_out(constants::DUMP_FILE_NAME.c_str(), std::ios::app);

		dump_out << std::endl << condition << " function: " << function_type << std::endl;
		dump_out << "CurrentSize: " << container_.size() << std::endl;

		for (size_t i = 0; i < container_.size(); ++i) {
			dump_out << "[" << i << "]" << " = " << container_[i] << std::endl;
		} 
		dump_out << std::endl;
	}

public:
	
	/**
	 * constructor
	 */
	stack() {
		container_.clear();

		std::ofstream dump_out(constants::DUMP_FILE_NAME.c_str(), std::ofstream::out | std::ofstream::trunc);
	}

	/**
	 * get the top element of stack
	 * @return last element in stack
	 */
	T top() const {
		DUMP(constants::START_STATE);

		if (empty()) {
			DUMP(constants::END_STATE);			
			T item;
			return item;
		} else {
			DUMP(constants::END_STATE);
			return container_.back();
		}

	}

	/**
	 * pop last element out of stack
	 */
	void pop() {
		DUMP(constants::START_STATE);

		if (container_.size() != 0) container_.pop_back();
			
		DUMP(constants::END_STATE);
	}

	/**
	 * push element in stack
	 * @param elem element to push
	 */
	void push(const T& elem) {
		DUMP(constants::START_STATE);

		container_.push_back(elem);
		
		DUMP(constants::END_STATE);
	}

	/**
	 * check if stack is empty
	 * @return True if size == 0, False otherwise
	 */
	bool empty() const {
		return container_.empty();
	}

	/**
	 * return current size of stack
	 * @return size_t 
	 */
	std::size_t size() const {
		return container_.size(0);
	}

};

}//stck namespace ended