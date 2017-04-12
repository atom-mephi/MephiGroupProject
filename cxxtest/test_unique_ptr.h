// test_unique_ptr.h
#include <cxxtest/TestSuite.h>

#include "../unique_ptr.h"

#include <memory>

class TestUniquePtr : public CxxTest::TestSuite
{
public:
    void testAccessors(void)
    {
        // given
        int* expectedValue = new int;
        *expectedValue = 20;

        // when
        atom::unique_ptr<int> ptr(expectedValue);

        //// then
        TS_ASSERT_EQUALS(ptr.get(), expectedValue);
        TS_ASSERT_EQUALS(*ptr, *expectedValue);
    }

    void testOperatorBool(void)
    {
        // when
        atom::unique_ptr<int> ptr(new int);
        atom::unique_ptr<int> ptr2(nullptr);

        // then
        TS_ASSERT(ptr == true);
        TS_ASSERT(ptr2 == false);
    }

    void testOperatorEq(void)
    {
        // given
        int* expectedValue = new int;
        *expectedValue = 20;
        atom::unique_ptr<int> ptr(expectedValue);

        // when
        atom::unique_ptr<int> ptr2(nullptr);
        ptr2 = std::move(ptr);

        //// then
        TS_ASSERT_EQUALS(ptr.get(), nullptr);
        TS_ASSERT_EQUALS(ptr2.get(), expectedValue);
        TS_ASSERT_EQUALS(*ptr2, *expectedValue);
    }

    void testRelease(void)
    {
        // given
        int expectedValue = 20;

        // when
        atom::unique_ptr<int> ptr(&expectedValue);
        int* value = ptr.release();

        //// then
        TS_ASSERT_EQUALS(ptr.get(), nullptr);
        TS_ASSERT_EQUALS(value, &expectedValue);
        TS_ASSERT_EQUALS(*value, expectedValue);
    }
};
