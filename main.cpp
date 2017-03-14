#include "stack.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "vector.h"

#define TEST(condition) 										  \
	if (!(condition))   										  \
		std::cout << "Test FAILED: " << #condition << std::endl;  \

int main() {

	vec::vector<int> t;

	for (int i = 0; i < 10; ++i) t.push_back(i);

	t.resize(10);
	vec::vector<int> test = t;

	t.push_back(100);

	test.emplace_back(3);
	for (int i = 0; i < test.size(); ++i) {
		std::cout << test[i] << " ";
	} std::cout << std::endl;
	
	for (int i = 0; i < t.size(); ++i) {
		std::cout << t[i] << " ";
	} std::cout << std::endl;


	return 0;
}