#include "Transform3D.h"

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

Entropy::Math::Mat4 Entropy::Math::Scale(float scale)
{
	return Scale(scale, scale, scale);
}

Entropy::Math::Mat4 Entropy::Math::Scale(const Vec4& scale)
{
	return Scale(scale.I, scale.J, scale.K);
}

Entropy::Math::Mat4 Entropy::Math::Scale(const Vec3& scale)
{
	return Scale(scale.I, scale.J, scale.K);
}

Entropy::Math::Mat4 Entropy::Math::Scale(float sX, float sY, float sZ)
{
	return Mat4(
		sX, 0.0f, 0.0f, 0.0f,
		0.0f, sY, 0.0f, 0.0f,
		0.0f, 0.0f, sZ, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::Translate(const Vec4& translation)
{
	return Translate(translation.I, translation.J, translation.K);
}

Entropy::Math::Mat4 Entropy::Math::Translate(const Vec3& translation)
{
	return Translate(translation.I, translation.J, translation.K);
}

Entropy::Math::Mat4 Entropy::Math::Translate(float dX, float dY, float dZ)
{
	return Mat4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		dX, dY, dZ, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::RotateX(float angle)
{
	return Mat4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cos(angle), sin(angle), 0.0f,
		0.0f, -sin(angle), cos(angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::RotateY(float angle)
{
	return Mat4(
		cos(angle), 0.0f, -sin(angle), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		sin(angle), 0.0f, cos(angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::RotateZ(float angle)
{
	return Mat4(
		cos(angle), sin(angle), 0.0f, 0.0f,
		-sin(angle), cos(angle), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::Rotate(const Vec3& axis, float angle)
{
	const float k = 1.0f - cos(angle);
	const float s = sin(angle);
	const float c = cos(angle);
	Vec3 na = normalize(axis);
	return Mat4(
		na.I * na.I * k + c, na.I * na.J * k + na.K * s, na.I * na.K * k - na.J * s, 0.0f,
		na.I * na.J * k - na.K * s, na.J * na.J * k + c, na.J * na.K * k + na.I * s, 0.0f,
		na.I * na.K * k + na.J * s, na.J * na.K * k - na.I * s, na.K * na.K * k + c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::Ortho(float left, float right, float top, float bottom, float near, float far)
{
	return Mat4(
		2.0f / (right - left), 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f / (far - near), 0.0f,
		(right + left) / (right - left), (top + bottom) / (top - bottom), near / (far - near), 1.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::Perspective(float fov, float aspectRatio, float near, float far)
{
	const float tanHalfFOV = tan(fov / 2.0f);
	return Mat4(
		1.0f / (aspectRatio * tanHalfFOV), 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f / tanHalfFOV, 0.0f, 0.0f,
		0.0f, 0.0f, -(far + near) / (far - near), -1.0f,
		0.0f, 0.0f, -(2.0f * far * near) / (far - near), 0.0f
	);
}

Entropy::Math::Mat4 Entropy::Math::Look(Vec3 cameraPos, Vec3 cameraTarget, Vec3 cameraUp)
{
	Vec3 cd = normalize(cameraPos - cameraTarget);
	Vec3 cr = normalize(cross(cd, cameraUp));
	Vec3 cu = cross(cr, cd);

	return Mat4(
		cr.I, cu.I, cd.I, 0.0f,
		cr.J, cu.J, cd.J, 0.0f,
		cr.K, cu.K, cd.K, 0.0f,
		-dot(cr, cameraPos), -dot(cu, cameraPos), -dot(cd, cameraPos), 1.0f
	);
}
