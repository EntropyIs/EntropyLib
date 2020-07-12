#include <gtest/gtest.h>

#include <Profiler.h>

#include <fstream>
#include <string>

using namespace Entropy::Debug;

std::string getNexToken(std::ifstream& file)
{
	char c;
	std::string result;

	while (file.good())
	{
		file >> std::noskipws;
		file >> c;
		if (c == ',' || c == '\n' || c == '\n\r' || c == '\r' || c == '\r\n')
			break;
		result += c;
	}

	return result;
}

TEST(Profiler, SimpleProfiles)
{
	const char* PROFILE_NAME = "profiles.csv";
	const char* CATEGORIES[] =
	{
		"Category0",
		"Category1",
		"Category2"
	};
	const unsigned int NUM_CATEGORIES = sizeof(CATEGORIES) / sizeof(*CATEGORIES);
	const unsigned int NUM_FRAMES = 5;

	Profiler profiler;
	profiler.initialize("profiles.csv");

	for (unsigned int i = 0; i < NUM_FRAMES; i++)
	{
		profiler.poll();
		for(unsigned j = 0; j < NUM_CATEGORIES; j++)
		{
			profiler.addEntry(CATEGORIES[j], i*NUM_CATEGORIES + j);
		}
	}

	profiler.shutdown();

	std::ifstream input(PROFILE_NAME);

	for (unsigned int i = 0; i < NUM_CATEGORIES; i++)
	{
		EXPECT_EQ(getNexToken(input), CATEGORIES[i]);
	}

	for (unsigned int i = 0; i < NUM_FRAMES * NUM_CATEGORIES; i++)
	{
		EXPECT_EQ(std::stoi(getNexToken(input)), i);
	}

	input.close();
}