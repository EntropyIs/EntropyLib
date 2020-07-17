#pragma once

#include "../../Vector3.h"

namespace Entropy
{
	namespace Graphics
	{
		struct __declspec(dllexport) DirectionalLight
		{
			Math::Vector3 Direction;

			Math::Vector3 Ambient;
			Math::Vector3 Diffuse;
			Math::Vector3 Specular;

			DirectionalLight(const Math::Vector3& direction, const Math::Vector3& Ambient, const Math::Vector3& diffuse, const Math::Vector3& specular) : Direction(direction), Ambient(Ambient), Diffuse(diffuse), Specular(specular) {};
			DirectionalLight(float i, float j, float k, float aI, float aJ, float aK, float dI, float dJ, float dK, float sI, float sJ, float sK) : Direction(i, j, k), Ambient(aI, aJ, aK), Diffuse(dI, dJ, dK), Specular(sI, sJ, sK) {};
			DirectionalLight(float i, float j, float k, float ambient, float diffuse, float specular) :Direction(i, j, k), Ambient(ambient, ambient, ambient), Diffuse(diffuse, diffuse, diffuse), Specular(specular, specular, specular) {};
		};

		struct __declspec(dllexport) PointLight
		{
			Math::Vector3 Position;

			float Constant;
			float Linear;
			float Quadratic;

			Math::Vector3 Ambient;
			Math::Vector3 Diffuse;
			Math::Vector3 Specular;

			PointLight(const Math::Vector3& position, float constant, float linear, float quadratic, const Math::Vector3& Ambient, const Math::Vector3& diffuse, const Math::Vector3& specular) : Position(position), Constant(constant), Linear(linear), Quadratic(quadratic), Ambient(Ambient), Diffuse(diffuse), Specular(specular) {};
			PointLight(float i, float j, float k, float constant, float linear, float quadratic, float aI, float aJ, float aK, float dI, float dJ, float dK, float sI, float sJ, float sK) : Position(i, j, k), Constant(constant), Linear(linear), Quadratic(quadratic), Ambient(aI, aJ, aK), Diffuse(dI, dJ, dK), Specular(sI, sJ, sK) {};
			PointLight(float i, float j, float k, float constant, float linear, float quadratic, float ambient, float diffuse, float specular) : Position(i, j, k), Constant(constant), Linear(linear), Quadratic(quadratic), Ambient(ambient, ambient, ambient), Diffuse(diffuse, diffuse, diffuse), Specular(specular, specular, specular) {};
		};

		struct __declspec(dllexport) SpotLight
		{
			Math::Vector3 Position;
			Math::Vector3 Direction;

			float InnerCutOff;
			float OuterCutOff;

			Math::Vector3 Ambient;
			Math::Vector3 Diffuse;
			Math::Vector3 Specular;

			SpotLight(const Math::Vector3& position, const Math::Vector3& direction, float innerCutOff, float outerCutOff, const Math::Vector3& Ambient, const Math::Vector3& diffuse, const Math::Vector3& specular) : Position(position), Direction(direction), InnerCutOff(innerCutOff), OuterCutOff(outerCutOff), Ambient(Ambient), Diffuse(diffuse), Specular(specular) {};
			SpotLight(float i, float j, float k, float dirI, float dirJ, float dirK, float innerCutOff, float outerCutOff, float aI, float aJ, float aK, float dI, float dJ, float dK, float sI, float sJ, float sK) : Position(i, j, k), Direction(dirI, dirJ, dirK), InnerCutOff(innerCutOff), OuterCutOff(outerCutOff), Ambient(aI, aJ, aK), Diffuse(dI, dJ, dK), Specular(sI, sJ, sK) {};
			SpotLight(float i, float j, float k, float dirI, float dirJ, float dirK, float innerCutOff, float outerCutOff, float ambient, float diffuse, float specular) : Position(i, j, k), Direction(dirI, dirJ, dirK), InnerCutOff(innerCutOff), OuterCutOff(outerCutOff), Ambient(ambient, ambient, ambient), Diffuse(diffuse, diffuse, diffuse), Specular(specular, specular, specular) {};
		};
	}
}