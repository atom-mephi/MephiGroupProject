// test_array.h
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

    void testAccessOperatorWithRangeCheck(void)
    {
        // given
        const int expectedFirstValue = 5;
        const int expectedSecondValue = 6;
        const int expectedThirdValue = 7;
        atom::array<int, 3> arr = {{expectedFirstValue, expectedSecondValue, expectedThirdValue}};

        // when
        int firstValue = 0;
        int secondValue = 0;
        int thirdValue = 0;

        try
        {
            firstValue = arr.at(0);
            secondValue = arr.at(1);
            thirdValue = arr.at(2);
        }
        catch(...)
        {
            TS_ASSERT(!"expected exception");
        }

        // then
        TS_ASSERT_EQUALS(firstValue, expectedFirstValue);
        TS_ASSERT_EQUALS(secondValue, expectedSecondValue);
        TS_ASSERT_EQUALS(thirdValue, expectedThirdValue);
    }

    void testAccessOperatorWithRangeCheckThrowsException(void)
    {
        // given
        atom::array<int, 3> arr = {{5, 6, 7}};
        const bool expectedValue = true;

        bool catched = false;

        // when
        try
        {
            int tmp = arr.at(3);
        }
        catch(std::out_of_range e)
        {
            catched = expectedValue;
        }
        catch(...)
        {
            TS_ASSERT(!"expected exception");
        }

        // then
        TS_ASSERT_EQUALS(catched, expectedValue);
    }

    void testFront(void)
    {
        // given
        const int expectedValue = 8;
        atom::array<int, 3> arr = {{expectedValue, 6, 7}};

        // when
        int frontValue = arr.front();

        // then
        TS_ASSERT_EQUALS(frontValue, expectedValue);
    }

    void testBack(void)
    {
        // given
        const int expectedValue = 21;
        atom::array<int, 3> arr = {{17, 6, expectedValue}};

        // when
        int backValue = arr.back();

        // then
        TS_ASSERT_EQUALS(backValue, expectedValue);
    }

    void testRangeBasedFor(void)
    {
        // given
        atom::array<int, 5> arr = {{17, 6, 12, 20, 10}};

        // then
        int i = 0;
        for( auto& elem : arr )
            TS_ASSERT_EQUALS(elem, arr[i++]);
    }

    void testSize(void)
    {
        // given
        const int expectedValue = 10;
        atom::array<int, expectedValue> arr;

        // when
        int sizeValue = arr.size();

        // then
        TS_ASSERT_EQUALS(sizeValue, expectedValue);
    }

    void testBoolArraySize(void)
    {
        // given
        const size_t expectedValue = 10;
        atom::array<bool, expectedValue> arr;

        // when
        size_t arrSize = arr.size();

        // then
        TS_ASSERT_EQUALS(arrSize, expectedValue);
    }

    void testBoolArrayAccessor(void)
    {
        // given
        atom::array<bool, 10> arr;

        // when
        arr[3] = true;
        TS_ASSERT_EQUALS(arr[3], true);
        arr[3] = false;

        // then
        TS_ASSERT_EQUALS(arr[3], false);
    }
};
