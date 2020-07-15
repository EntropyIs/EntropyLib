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
			static Material Emerald = Material(0.0215, 0.1745, 0.0215, 0.07568, 0.61424, 0.07568, 0.633, 0.727811, 0.633, 0.6);
			static Material Jade = Material(0.135, 0.2225, 0.1575, 0.54, 0.89, 0.63, 0.316228, 0.316228, 0.316228, 0.1);
			static Material Obsidian = Material(0.05375, 0.05, 0.06625, 0.18275, 0.17, 0.22525, 0.332741, 0.328634, 0.346435, 0.3);
			static Material Pearl = Material(0.25, 0.20725, 0.20725, 1, 0.829, 0.829, 0.296648, 0.296648, 0.296648, 0.088);
			static Material Ruby = Material(0.1745, 0.01175, 0.01175, 0.61424, 0.04136, 0.04136, 0.727811, 0.626959, 0.626959, 0.6);
			static Material Turquoise = Material(0.1, 0.18725, 0.1745, 0.396, 0.74151, 0.69102, 0.297254, 0.30829, 0.306678, 0.1);
			static Material Brass = Material(0.329412, 0.223529, 0.027451, 0.780392, 0.568627, 0.113725, 0.992157, 0.941176, 0.807843, 0.21794872);
			static Material Bronze = Material(0.2125, 0.1275, 0.054, 0.714, 0.4284, 0.18144, 0.393548, 0.271906, 0.166721, 0.2);
			static Material Chrome = Material(0.25, 0.25, 0.25, 0.4, 0.4, 0.4, 0.774597, 0.774597, 0.774597, 0.6);
			static Material Copper = Material(0.19125, 0.0735, 0.0225, 0.7038, 0.27048, 0.0828, 0.256777, 0.137622, 0.086014, 0.1);
			static Material Gold = Material(0.24725, 0.1995, 0.0745, 0.75164, 0.60648, 0.22648, 0.628281, 0.555802, 0.366065, 0.4);
			static Material Silver = Material(0.19225, 0.19225, 0.19225, 0.50754, 0.50754, 0.50754, 0.508273, 0.508273, 0.508273, 0.4);
			static Material BlackPlastic = Material(0, 0, 0, 0.01, 0.01, 0.01, 0.5, 0.5, 0.5, 0.25);
			static Material CyanPlastic = Material(0, 0.1, 0.06, 0, 0.50980392, 0.50980392, 0.50196078, 0.50196078, 0.50196078, 0.25);
			static Material GreenPlastic = Material(0, 0, 0, 0.1, 0.35, 0.1, 0.45, 0.55, 0.45, 0.25);
			static Material RedPlastic = Material(0, 0, 0, 0.5, 0, 0, 0.7, 0.6, 0.6, 0.25);
			static Material WhitePlastic = Material(0, 0, 0, 0.55, 0.55, 0.55, 0.7, 0.7, 0.7, 0.25);
			static Material YellowPlastic = Material(0, 0, 0, 0.5, 0.5, 0, 0.6, 0.6, 0.5, 0.25);
			static Material BlackRubber = Material(0.02, 0.02, 0.02, 0.01, 0.01, 0.01, 0.4, 0.4, 0.4, 0.078125);
			static Material CyanRubber = Material(0, 0.05, 0.05, 0.4, 0.5, 0.5, 0.04, 0.7, 0.7, 0.078125);
			static Material GreenRubber = Material(0, 0.05, 0, 0.4, 0.5, 0.4, 0.04, 0.7, 0.04, 0.078125);
			static Material RedRubber = Material(0.05, 0, 0, 0.5, 0.4, 0.4, 0.7, 0.04, 0.04, 0.078125);
			static Material WhiteRubber = Material(0.05, 0.05, 0.05, 0.5, 0.5, 0.5, 0.7, 0.7, 0.7, 0.078125);
			static Material YellowRubber = Material(0.05, 0.05, 0, 0.5, 0.5, 0.4, 0.7, 0.7, 0.04, 0.078125);

		}
	}
}