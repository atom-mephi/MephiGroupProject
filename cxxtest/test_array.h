// TestField.h
#include <cxxtest/TestSuite.h>

#include "../array.h"

class TestArray : public CxxTest::TestSuite
{
public:
    void testArraySize(void)
    {
        Array<int, 10> arr;

        TS_ASSERT_EQUALS(arr.size(), 10);
    }

    void testArrayInit(void)
    {
        Array<int, 3> arr = {{5, 6, 7}};

        TS_ASSERT_EQUALS(arr.size(), 3);
        TS_ASSERT_EQUALS(arr[0], 5);
        TS_ASSERT_EQUALS(arr[1], 6);
        TS_ASSERT_EQUALS(arr[2], 7);
    }
};
