// test_print.h
#include <cxxtest/TestSuite.h>

#include "../print.h"

class TestPrint : public CxxTest::TestSuite
{
public:
    void testPrintCStr(void)
    {
        atom::print("sdhfkjh");
    }

    void testPrintStdString(void)
    {
        std::string s = "dsjhkfah";

        atom::print(s);
    }

    void testPrintWithParams(void)
    {
        atom::print("a%b%c%d%e%f", 123, 12.3f, false, 't', "test");
    }

    void testPrintWithCStrParams(void)
    {
        atom::print("a%b%c%d%e%f", 123, "test1", 123, "test2", 123 );
    }
};
