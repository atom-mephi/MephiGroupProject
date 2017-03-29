// test_random_access_iterator.h
#include <cxxtest/TestSuite.h>

#include "../random_access_iterator.h"

class TestRandomAccessIterator : public CxxTest::TestSuite
{
public:
    void testConstructor(void)
    {
        int* a = new int;
        atom::random_access_iterator<int> iter(a);
    }
};
