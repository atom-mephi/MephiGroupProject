// TestField.h
#include <cxxtest/TestSuite.h>

#include "../array.h"

class TestArray : public CxxTest::TestSuite
{
public:
    void testArraySize(void)
    {
        // given
        const size_t expectedValue = 10;
        atom::array<int, expectedValue> arr;

        // when
        size_t arrSize = arr.size();

        // then
        TS_ASSERT_EQUALS(arrSize, expectedValue);
    }

    void testArrayInit(void)
    {
        atom::array<int, 3> arr = {{5, 6, 7}};

        TS_ASSERT_EQUALS(arr.size(), 3);
        TS_ASSERT_EQUALS(arr[0], 5);
        TS_ASSERT_EQUALS(arr[1], 6);
        TS_ASSERT_EQUALS(arr[2], 7);
    }
};
