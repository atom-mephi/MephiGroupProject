// TestField.h
#include <cxxtest/TestSuite.h>

#include "../array.h"

class TestArray : public CxxTest::TestSuite
{
public:
    void testArray(void)
    {
        Array<int, 10> arr;

        TS_ASSERT_EQUALS(arr.size(), 10);
    }
};
