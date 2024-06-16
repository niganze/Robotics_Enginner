#include <string.h>
#include "unity.h"
#include "administration.h"


void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTestFail(void)
{
    TEST_ASSERT_EQUAL(1, 0);
}
void test_EmptyTestPass(void)
{
    TEST_ASSERT_EQUAL(1, 1);
}


int main (void)
{
        
    UnityBegin();

    RUN_TEST(test_EmptyTestFail,1);
	RUN_TEST(test_EmptyTestPass,2);

    return UnityEnd();
}
