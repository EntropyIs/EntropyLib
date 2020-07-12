#pragma once

namespace Entropy
{
	namespace Debug
	{
		class __declspec(dllexport) Profiler
		{
			const char* fileName;

			unsigned int frameIndex;
			unsigned int categoryIndex;
			unsigned int numUsedCategories;

			bool firstFrame;

			static const unsigned int MAX_PROFILE_SAMPLES = 512;
			static const unsigned int MAX_PROFILE_CATEGORIES = 20;

			struct Catergory
			{
				const char* name;
				float samples[MAX_PROFILE_SAMPLES];
			} categories[MAX_PROFILE_CATEGORIES];

		public:
			void initialize(const char* fileName);
			void shutdown();

			void addEntry(const char* catagory, float time);
			void poll();

			
		};
	}
}
