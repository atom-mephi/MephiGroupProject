// test_random_access_iterator.h
#include <cxxtest/TestSuite.h>

#include "../random_access_iterator.h"

class TestRandomAccessIterator : public CxxTest::TestSuite
{
public:
    void testValue(void)
    {
        // given
        const size_t expectedValue = 10;
        int arr[5] = {expectedValue, 5, 6, 4, 2};
        atom::random_access_iterator<int> iter(arr);

        // when
        int value = *iter;

        // then
        TS_ASSERT_EQUALS(value, expectedValue);
    }

    void testIncrement(void)
    {
        // given
        const size_t expectedValue = 7;
        int arr[5] = {5, expectedValue, 6, 4, 2};
        atom::random_access_iterator<int> iter(arr);

        // when
        int value = *++iter;

        // then
        TS_ASSERT_EQUALS(value, expectedValue);
    }

    void testPostIncrement(void)
    {
        // given
        const size_t expectedValue = 7;
        const size_t expectedAfterValue = 4;
        int arr[5] = {expectedValue, expectedAfterValue, 6, 4, 2};
        atom::random_access_iterator<int> iter(arr);

        // when
        int value = *iter++;
        int valueAfter = *iter;

        // then
        TS_ASSERT_EQUALS(value, expectedValue);
        TS_ASSERT_EQUALS(valueAfter, expectedAfterValue);
    }

    void testEqOperator(void)
    {
        // given
        const size_t expectedValue = 7;
        int arr[5] = {5, expectedValue, 6, 4, 2};

        atom::random_access_iterator<int> iter1(arr);
        atom::random_access_iterator<int> iter2(arr);

        // when
        iter1++;
        ++iter2;

        // then
        TS_ASSERT(iter1 == iter2);
    }

    void testDecrement(void)
    {
        // given
        const size_t expectedValue = 7;
        int arr[5] = {5, expectedValue, 6, 4, 2};
        atom::random_access_iterator<int> iter(arr);

        // when
        ++iter;
        ++iter;
        int value = *--iter;

        // then
        TS_ASSERT_EQUALS(value, expectedValue);
    }

    void testPostDecrement(void)
    {
        // given
        const size_t expectedValue = 7;
        const size_t expectedAfterValue = 4;
        int arr[5] = {expectedAfterValue, expectedValue, 6, 4, 2};
        atom::random_access_iterator<int> iter(arr);

        // when
        iter++;
        int value = *iter--;
        int valueAfter = *iter;

        // then
        TS_ASSERT_EQUALS(value, expectedValue);
        TS_ASSERT_EQUALS(valueAfter, expectedAfterValue);
    }

    void testAddDifference(void)
    {
        // given
        const size_t expectedValue = 7;
        int arr[5] = {5, 4, 6, expectedValue, 2};
        atom::random_access_iterator<int> iter(arr);

        // when
        iter += 3;
        int value = *iter;

        // then
        TS_ASSERT_EQUALS(value, expectedValue);
    }

    void testPlus(void)
    {
        // given
        const size_t expectedValue = 8;
        const size_t startExpectedValue = 2;
        int arr[5] = {startExpectedValue, 4, 6, expectedValue, 2};
        atom::random_access_iterator<int> iter(arr);

        // when
        int value = *(iter + 3);
        int startValue = *iter;

        // then
        TS_ASSERT_EQUALS(value, expectedValue);
        TS_ASSERT_EQUALS(startValue, startExpectedValue);
    }

    void testRemoveDifference(void)
    {
        // given
        const size_t expectedValue = 7;
        int arr[5] = {5, expectedValue, 6, 4, 2};
        atom::random_access_iterator<int> iter(arr);

        // when
        iter += 3;
        iter -= 2;
        int value = *iter;

        // then
        TS_ASSERT_EQUALS(value, expectedValue);
    }

    void testMinus(void)
    {
        // given
        const size_t expectedValue = 8;
        const size_t startExpectedValue = 2;
        int arr[5] = {expectedValue, 4, 6, startExpectedValue, 2};
        atom::random_access_iterator<int> iter(arr);
        iter += 3;

        // when
        int value = *(iter - 3);
        int startValue = *iter;

        // then
        TS_ASSERT_EQUALS(value, expectedValue);
        TS_ASSERT_EQUALS(startValue, startExpectedValue);
    }
};
