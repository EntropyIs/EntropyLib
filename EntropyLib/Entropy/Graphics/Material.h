#pragma once

#include "../../Vector3.h"

namespace Entropy
{
	namespace Graphics
	{
		struct __declspec(dllexport) Material
		{
			Math::Vector3 Ambient;
			Math::Vector3 Diffuse;
			Math::Vector3 Specular;
			float Shininess;

			Material(Math::Vector3 ambient, Math::Vector3 diffuse, Math::Vector3 specular, float shininess) : Ambient(ambient), Diffuse(diffuse), Specular(specular), Shininess(shininess) {};
			Material(float aI, float aJ, float aK, float dI, float dJ, float dK, float sI, float sJ, float sK, float shininess) : Ambient(aI, aJ, aK), Diffuse(dI, dJ, dK), Specular(sI, sJ, sK), Shininess(shininess) {};
		};

		namespace Materials
		{
			static Material Emerald = Material(0.0215f, 0.1745f, 0.0215f, 0.07568f, 0.61424f, 0.07568f, 0.633f, 0.727811f, 0.633f, 0.6f);
			static Material Jade = Material(0.135f, 0.2225f, 0.1575f, 0.54f, 0.89f, 0.63f, 0.316228f, 0.316228f, 0.316228f, 0.1f);
			static Material Obsidian = Material(0.05375f, 0.05f, 0.06625f, 0.18275f, 0.17f, 0.22525f, 0.332741f, 0.328634f, 0.346435f, 0.3f);
			static Material Pearl = Material(0.25f, 0.20725f, 0.20725f, 1.0f, 0.829f, 0.829f, 0.296648f, 0.296648f, 0.296648f, 0.088f);
			static Material Ruby = Material(0.1745f, 0.01175f, 0.01175f, 0.61424f, 0.04136f, 0.04136f, 0.727811f, 0.626959f, 0.626959f, 0.6f);
			static Material Turquoise = Material(0.1f, 0.18725f, 0.1745f, 0.396f, 0.74151f, 0.69102f, 0.297254f, 0.30829f, 0.306678f, 0.1f);
			static Material Brass = Material(0.329412f, 0.223529f, 0.027451f, 0.780392f, 0.568627f, 0.113725f, 0.992157f, 0.941176f, 0.807843f, 0.21794872f);
			static Material Bronze = Material(0.2125f, 0.1275f, 0.054f, 0.714f, 0.4284f, 0.18144f, 0.393548f, 0.271906f, 0.166721f, 0.2f);
			static Material Chrome = Material(0.25f, 0.25f, 0.25f, 0.4f, 0.4f, 0.4f, 0.774597f, 0.774597f, 0.774597f, 0.6f);
			static Material Copper = Material(0.19125f, 0.0735f, 0.0225f, 0.7038f, 0.27048f, 0.0828f, 0.256777f, 0.137622f, 0.086014f, 0.1f);
			static Material Gold = Material(0.24725f, 0.1995f, 0.0745f, 0.75164f, 0.60648f, 0.22648f, 0.628281f, 0.555802f, 0.366065f, 0.4f);
			static Material Silver = Material(0.19225f, 0.19225f, 0.19225f, 0.50754f, 0.50754f, 0.50754f, 0.508273f, 0.508273f, 0.508273f, 0.4f);
			static Material BlackPlastic = Material(0.0f, 0.0f, 0.0f, 0.01f, 0.01f, 0.01f, 0.5f, 0.5f, 0.5f, 0.25f);
			static Material CyanPlastic = Material(0.0f, 0.1f, 0.06f, 0.0f, 0.50980392f, 0.50980392f, 0.50196078f, 0.50196078f, 0.50196078f, 0.25f);
			static Material GreenPlastic = Material(0.0f, 0.0f, 0.0f, 0.1f, 0.35f, 0.1f, 0.45f, 0.55f, 0.45f, 0.25f);
			static Material RedPlastic = Material(0.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.7f, 0.6f, 0.6f, 0.25);
			static Material WhitePlastic = Material(0.0f, 0.0f, 0.0f, 0.55f, 0.55f, 0.55f, 0.7f, 0.7f, 0.7f, 0.25f);
			static Material YellowPlastic = Material(0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.0f, 0.6f, 0.6f, 0.5f, 0.25f);
			static Material BlackRubber = Material(0.02f, 0.02f, 0.02f, 0.01f, 0.01f, 0.01f, 0.4f, 0.4f, 0.4f, 0.078125f);
			static Material CyanRubber = Material(0.0f, 0.05f, 0.05f, 0.4f, 0.5f, 0.5f, 0.04f, 0.7f, 0.7f, 0.078125f);
			static Material GreenRubber = Material(0.0f, 0.05f, 0.0f, 0.4f, 0.5f, 0.4f, 0.04f, 0.7f, 0.04f, 0.078125f);
			static Material RedRubber = Material(0.05f, 0.0f, 0.0f, 0.5f, 0.4f, 0.4f, 0.7f, 0.04f, 0.04f, 0.078125f);
			static Material WhiteRubber = Material(0.05f, 0.05f, 0.05f, 0.5f, 0.5f, 0.5f, 0.7f, 0.7f, 0.7f, 0.078125f);
			static Material YellowRubber = Material(0.05f, 0.05f, 0.0f, 0.5f, 0.5f, 0.4f, 0.7f, 0.7f, 0.04f, 0.078125f);

		}
	}
}