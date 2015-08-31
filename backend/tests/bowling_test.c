#include "../unity/unity_fixture.h"
#include "../src/bowling_stats.h"

TEST_GROUP(BowlingTest);

TEST_GROUP_RUNNER(BowlingTest)
{
	RUN_TEST_CASE(BowlingTest, TestAllZeroes);	

}

TEST_SETUP(BowlingTest)
{
	inicijalizacija();
}

TEST_TEAR_DOWN(BowlingTest)
{
}

// Prvi test - promasena sva bacanja
TEST(BowlingTest, TestAllZeroes)
{
	int i;
	for (i = 0; i < MAX_BROJ_BACANJA; i++)
	srusi(0);
	TEST_ASSERT_EQUAL_HEX32(0, skor());
}
