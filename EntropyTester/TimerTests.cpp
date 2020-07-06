#include <gtest/gtest.h>

#include <Clock.h>
#include <thread>

using namespace Entropy::Timing;

bool QUICK_TEST = false;

TEST(TimerClock, Initialize)
{
	Clock clock;

	EXPECT_TRUE(clock.initialize());
	EXPECT_TRUE(clock.shutdown());
}

TEST(TimerClock, TimeMeasureing)
{
	Clock clock;
	EXPECT_TRUE(clock.initialize());
	EXPECT_FLOAT_EQ(0, clock.timeElapsed());
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	clock.poll();
	float timeElapsed = clock.timeElapsed();
	EXPECT_TRUE(0.9f < timeElapsed);
	EXPECT_TRUE(timeElapsed < 1.1f);

	clock.poll();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	clock.poll();
	timeElapsed = clock.timeElapsed();
	EXPECT_TRUE(0.4f < timeElapsed);
	EXPECT_TRUE(timeElapsed < 0.6f);

	if (!QUICK_TEST)
	{
		const int numTests = 10 + rand() % 100;
		const float threshold = 0.01f;
		for (int i = 0; i < numTests; i++)
		{
			int testTimeMillis = 1000 + rand() % 1000;
			float testTimeSeconds = testTimeMillis / 1000.0f;

			clock.poll();
			std::this_thread::sleep_for(std::chrono::milliseconds(testTimeMillis));
			clock.poll();
			float timeElapsed = clock.timeElapsed();
			EXPECT_TRUE((testTimeSeconds - threshold) < timeElapsed);
			EXPECT_TRUE(timeElapsed < (testTimeSeconds + threshold));
		}
	}

	EXPECT_TRUE(clock.shutdown());
}

