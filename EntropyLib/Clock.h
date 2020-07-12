#pragma once
#include <Windows.h>

namespace Entropy
{
	namespace Timing
	{
		class __declspec(dllexport) Clock
		{
		private:
			LARGE_INTEGER frequency;

			LARGE_INTEGER timeLast;
			LARGE_INTEGER timeCurrent;

			float deltaTime;

		public:
			void poll();

			bool initialize();
			bool shutdown();

			float timeElapsed() const;
			float currentTime() const;
		};
	}
}



