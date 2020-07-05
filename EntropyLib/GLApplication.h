#pragma once

namespace Entropy
{
	/**
	 * OpenGL Application Handler, handles OpenGL initalization and termination.
	 */
	class __declspec(dllexport) GLApplication
	{
	public:
		GLApplication();
		~GLApplication();

		void initializeGLFW();
		void initializeGLEW();
	};
}

