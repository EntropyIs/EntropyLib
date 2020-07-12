#include "Profiler.h"

#include <fstream>
#include <cassert>

void Entropy::Debug::Profiler::addEntry(const char* categoryName, float time)
{
	assert(categoryIndex < MAX_PROFILE_CATEGORIES);
	Catergory& cat = categories[categoryIndex];

	if (firstFrame)
	{
		cat.name = categoryName;
		numUsedCategories++;
	}
	else
	{
		assert(categoryIndex < numUsedCategories);
		assert(cat.name == categoryName && categoryName != NULL);
	}
	cat.samples[frameIndex] = time;
	categoryIndex++;
}

void Entropy::Debug::Profiler::poll()
{
	if (!firstFrame)
		assert(categoryIndex == numUsedCategories);
	else if (frameIndex != 0)
		firstFrame = false;
	frameIndex++;

	if (frameIndex > MAX_PROFILE_SAMPLES)
		frameIndex = 0;

	categoryIndex = 0;
}

void Entropy::Debug::Profiler::initialize(const char* fileName)
{
	this->fileName = fileName;
	frameIndex = -1;
	categoryIndex = 0;
	numUsedCategories = 0;
	firstFrame = true;
}

void Entropy::Debug::Profiler::shutdown()
{
	std::ofstream file(fileName, std::ios::trunc);

	//WriteHeader
	for (unsigned int i = 0; i < numUsedCategories; i++)
	{
		file << categories[i].name;
		if (i + 1 < numUsedCategories)
			file << ',';
		else
			file << '\n';
	}

	//WriteSamples
	for (unsigned int i = 0; i <= frameIndex; i++)
	{
		for (unsigned int j = 0; j < numUsedCategories; j++)
		{
			file << categories[j].samples[i];
			if (j + 1 < numUsedCategories)
				file << ',';
			else
				file << '\n';
		}
	}
	file.close();
}
