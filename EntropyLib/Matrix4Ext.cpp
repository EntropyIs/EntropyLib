#include "Matrix4Ext.h"
#include "Entropy/Math/Vec3.h"

#include <cmath>

Entropy::Math::Vec4 Entropy::Math::operator*(const Mat4& left, const Vec4& right)
{
	return Vec4(
		left.R0C0 * right.I + left.R0C1 * right.J + left.R0C2 * right.K + left.R0C3 * right.L,
		left.R1C0 * right.I + left.R1C1 * right.J + left.R1C2 * right.K + left.R1C3 * right.L,
		left.R2C0 * right.I + left.R2C1 * right.J + left.R2C2 * right.K + left.R2C3 * right.L,
		left.R3C0 * right.I + left.R3C1 * right.J + left.R3C2 * right.K + left.R3C3 * right.L
	);
}

Entropy::Math::Mat4 Entropy::Math::ScaleMat4(const Vec4& scaleVector)
{
	return ScaleMat4(scaleVector.I, scaleVector.J, scaleVector.K);
}

Entropy::Math::Mat4 Entropy::Math::ScaleMat4(float sX, float sY)
{
	return ScaleMat4(sX, sY, 1.0f);
}

Entropy::Math::Mat4 Entropy::Math::ScaleMat4(float sX, float sY, float sZ)
{
	return Mat4(
		sX, 0.0f, 0.0f, 0.0f,
		0.0f, sY, 0.0f, 0.0f,
		0.0f, 0.0f, sZ, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::TranslationMatrix4(const Vec4& translationVevtor)
{
	return TranslationMatrix4(translationVevtor.I, translationVevtor.J, translationVevtor.K);
}

Entropy::Math::Mat4 Entropy::Math::TranslationMatrix4(float dX, float dY)
{
	return TranslationMatrix4(dX, dY, 0.0f);
}

Entropy::Math::Mat4 Entropy::Math::TranslationMatrix4(float dX, float dY, float dZ)
{
	return Mat4(
		1.0f, 0.0f, 0.0f, dX,
		0.0f, 1.0f, 0.0f, dY,
		0.0f, 0.0f, 1.0f, dZ,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::RotationAboutXYZMatrix4(const Vec4& rotationVector)
{
	return RotationAboutXYZMatrix4(rotationVector.I, rotationVector.J, rotationVector.K);
}

Entropy::Math::Mat4 Entropy::Math::RotationAboutXYZMatrix4(float rX, float rY, float rZ)
{
	return Mat4(
		cos(rY) * cos(rZ), -cos(rX) * sin(rZ) + sin(rX) * sin(rY) * cos(rZ), sin(rX) * sin(rY) + cos(rX) * sin(rY) * cos(rZ), 0.0f,
		cos(rY) * sin(rZ), cos(rY) * cos(rZ) + sin(rX) * sin(rY) * sin(rZ), -sin(rX) * cos(rY) + cos(rX) * sin(rY) * sin(rZ), 0.0f,
		-sin(rY), -sin(rX) * cos(rY), cos(rX) * cos(rY), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::RotationAboutXMatrix4(float rX)
{
	return Mat4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cos(rX), -sin(rX), 0.0f,
		0.0f, sin(rX), cos(rX), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::RotationAboutYMatrix4(float rY)
{
	return Mat4(
		cos(rY), 0.0f, sin(rY), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		-sin(rY), 0.0f, cos(rY), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::RotationAboutZMatrix4(float rZ)
{
	return Mat4(
		cos(rZ), -sin(rZ), 0.0f, 0.0f,
		sin(rZ), cos(rZ), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::RotationAboutAxisMatrix4(const Vec4& axis, const float angle)
{
	const float k = 1.0f - cos(angle);
	const float s = sin(angle);
	const float c = cos(angle);
	Vec4 na = normalize(axis);
	return Mat4(
		na.I * na.I * k + c, na.I * na.J * k - na.K * s, na.I * na.K * k + na.J * s, 0.0f,
		na.I * na.J * k + na.K * s, na.J * na.J * k + c, na.J * na.K * k - na.I * s, 0.0f,
		na.I * na.K * k - na.J * s, na.J * na.K * k + na.I * s, na.K * na.K * k + c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::Ortho(float left, float right, float top, float bottom, float zNear, float zFar)
{
	return Mat4(
		2.0f / (right - left), 0.0f, 0.0f, (right + left) / (right - left),
		0.0f, 2.0f / (top - bottom), 0.0f, (top + bottom) / (top - bottom),
		0.0f, 0.0f, 1.0f / (zFar - zNear), zNear / (zFar - zNear),
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::Perspective(float fov, float aspectRatio, float zNear, float zFar)
{
	const float tanHalfFOV = tan(fov / 2.0f);
	return Mat4(
		1.0f / (aspectRatio * tanHalfFOV), 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f / tanHalfFOV, 0.0f, 0.0f,
		0.0f, 0.0f, -(zFar + zNear) / (zFar - zNear), -(2.0f * zFar * zNear) / (zFar - zNear),
		0.0f, 0.0f, -1.0f, 0.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::LookAt(Vec3 cameraPos, Vec3 cameraTarget, Vec3 cameraUp)
{
	Vec3 cd = normalize(cameraPos - cameraTarget);
	Vec3 cr = normalize(cross(cd, cameraUp));
	Vec3 cu = cross(cr, cd);

	return Mat4(
		cr.I, cr.J, cr.K, -dot(cr, cameraPos),
		cu.I, cu.J, cu.K, -dot(cu, cameraPos),
		cd.I, cd.J, cd.K, -dot(cd, cameraPos),
		0.0f, 0.0f, 0.0f, 1.0f
	);
}
