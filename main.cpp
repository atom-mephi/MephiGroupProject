#include "stack.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "vector.h"

#define TEST(condition) 										  \
	if (!(condition))   										  \
		std::cout << "Test FAILED: " << #condition << std::endl;  \

int main() {

	stck::stack<int, vec::vector<int>> test_st;

	test_st.push(3);

	std::cout << test_st.top() << std::endl;

	return 0;
}