#include "Matrix4Ext.h"

#include <cmath>

Entropy::Math::Vector4 Entropy::Math::operator*(const Matrix4& left, const Vector4& right)
{
	return Vector4(
		left.r0c0 * right.i + left.r0c1 * right.j + left.r0c2 * right.k + left.r0c3 * right.l,
		left.r1c0 * right.i + left.r1c1 * right.j + left.r1c2 * right.k + left.r1c3 * right.l,
		left.r2c0 * right.i + left.r2c1 * right.j + left.r2c2 * right.k + left.r2c3 * right.l,
		left.r3c0 * right.i + left.r3c1 * right.j + left.r3c2 * right.k + left.r3c3 * right.l
	);
}

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

Entropy::Math::Matrix4 Entropy::Math::RotationAboutAxisMatrix(const Vector4& axis, const float angle)
{
	const float k = 1.0f - cos(angle);
	const float s = sin(angle);
	const float c = cos(angle);
	Vector4 na = normalize(axis);
	return Matrix4(
		na.i * na.i * k + c, na.i * na.j * k - na.k * s, na.i * na.k * k + na.j * s, 0.0f,
		na.i * na.j * k + na.k * s, na.j * na.j * k + c, na.j * na.k * k - na.i * s, 0.0f,
		na.i * na.k * k - na.j * s, na.j * na.k * k + na.i * s, na.k * na.k * k + c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Matrix4 Entropy::Math::Ortho(float left, float right, float top, float bottom, float zNear, float zFar)
{
	return Matrix4(
		2.0f / (right - left), 0.0f, 0.0f, (right + left) / (right - left),
		0.0f, 2.0f / (top - bottom), 0.0f, (top + bottom) / (top - bottom),
		0.0f, 0.0f, 1.0f / (zFar - zNear), zNear / (zFar - zNear),
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Matrix4 Entropy::Math::Perspective(float fov, float aspectRatio, float zNear, float zFar)
{
	const float tanHalfFOV = tan(fov / 2.0f);
	return Matrix4(
		1.0f / (aspectRatio * tanHalfFOV), 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f / tanHalfFOV, 0.0f, 0.0f,
		0.0f, 0.0f, zFar / (zNear - zFar), -(zFar * zNear) / (zFar - zNear),
		0.0f, 0.0f, -1.0f, 0.0f
	);
}
