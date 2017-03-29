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

    void testArrayInitWithInitialisationList(void)
    {
        // given
        const int expectedFirstValue = 5;
        const int expectedSecondValue = 6;
        const int expectedThirdValue = 7;
        atom::array<int, 3> arr = {{expectedFirstValue, expectedSecondValue, expectedThirdValue}};

        // when
        int firstValue = arr[0];
        int secondValue = arr[1];
        int thirdValue = arr[2];

        // then
        TS_ASSERT_EQUALS(firstValue, expectedFirstValue);
        TS_ASSERT_EQUALS(secondValue, expectedSecondValue);
        TS_ASSERT_EQUALS(thirdValue, expectedThirdValue);
    }

    void testRandomAccessOperator(void)
    {
        // given
        const int expectedFirstValue = 5;
        const int expectedSecondValue = 6;
        const int expectedThirdValue = 7;
        atom::array<int, 3> arr;

        // when
        arr[0] = expectedFirstValue;
        arr[1] = expectedSecondValue;
        arr[2] = expectedThirdValue;

        int firstValue = arr[0];
        int secondValue = arr[1];
        int thirdValue = arr[2];

        // then
        TS_ASSERT_EQUALS(firstValue, expectedFirstValue);
        TS_ASSERT_EQUALS(secondValue, expectedSecondValue);
        TS_ASSERT_EQUALS(thirdValue, expectedThirdValue);
    }
};
