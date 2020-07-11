#include "Matrix4Ext.h"

#include <cmath>

Entropy::Math::Matrix4 Entropy::Math::ScaleMatrix(const Vector4& scaleVector)
{
	return ScaleMatrix(scaleVector.i, scaleVector.j, scaleVector.k);
}

Entropy::Math::Matrix4 Entropy::Math::ScaleMatrix(float sX, float sY)
{
	return ScaleMatrix(sX, sY, 1.0f);
}

Entropy::Math::Matrix4 Entropy::Math::ScaleMatrix(float sX, float sY, float sZ)
{
	return Matrix4(
		sX, 0.0f, 0.0f, 0.0f,
		0.0f, sY, 0.0f, 0.0f,
		0.0f, 0.0f, sZ, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Matrix4 Entropy::Math::TranslationMatrix(const Vector4& translationVevtor)
{
	return TranslationMatrix(translationVevtor.i, translationVevtor.j, translationVevtor.k);
}

Entropy::Math::Matrix4 Entropy::Math::TranslationMatrix(float dX, float dY, float dZ)
{
	return Matrix4(
		1.0f, 0.0f, 0.0f, dX,
		0.0f, 1.0f, 0.0f, dY,
		0.0f, 0.0f, 1.0f, dZ,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Matrix4 Entropy::Math::RotationAboutXYZMatrix(const Vector4& rotationVector)
{
	return RotationAboutXYZMatrix(rotationVector.i, rotationVector.j, rotationVector.k);
}

Entropy::Math::Matrix4 Entropy::Math::RotationAboutXYZMatrix(float rX, float rY, float rZ)
{
	return Matrix4(
		cos(rY) * cos(rZ), -cos(rX) * sin(rZ) + sin(rX) * sin(rY) * cos(rZ), sin(rX) * sin(rY) + cos(rX) * sin(rY) * cos(rZ), 0.0f,
		cos(rY) * sin(rZ), cos(rY) * cos(rZ) + sin(rX) * sin(rY) * sin(rZ), -sin(rX) * cos(rY) + cos(rX) * sin(rY) * sin(rZ), 0.0f,
		-sin(rY), -sin(rX) * cos(rY), cos(rX) * cos(rY), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Matrix4 Entropy::Math::RotationAboutXMatrix(float rX)
{
	return Matrix4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cos(rX), -sin(rX), 0.0f,
		0.0f, sin(rX), cos(rX), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Matrix4 Entropy::Math::RotationAboutYMatrix(float rY)
{
	return Matrix4(
		cos(rY), 0.0f, sin(rY), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		-sin(rY), 0.0f, cos(rY), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Matrix4 Entropy::Math::RotationAboutZMatrix(float rZ)
{
	return Matrix4(
		cos(rZ), -sin(rZ), 0.0f, 0.0f,
		sin(rZ), cos(rZ), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Matrix4 Entropy::Math::RotationAboutAxisMatrix(const Vector4& axis, float angle)
{
	return Matrix4(
		cos(angle) + (axis.i * axis.i) * (1 - cos(angle)), axis.i * axis.j * (1 - cos(angle)) - axis.k * sin(angle), axis.i * axis.k * (1 - cos(angle)) + axis.j * sin(angle), 0.0f,
		axis.j * axis.i * (1 - cos(angle)) + axis.k * sin(angle), cos(angle) + (axis.j * axis.j) * (1 - cos(angle)), axis.j * axis.k * (1 - cos(angle)) - axis.i * sin(angle), 0.0f,
		axis.k * axis.i * (1 - cos(angle)) - axis.j * sin(angle), axis.k * axis.j * (1 - cos(angle)) + axis.i * sin(angle), cos(angle) + (axis.k * axis.k) * (1 - cos(angle)), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}
