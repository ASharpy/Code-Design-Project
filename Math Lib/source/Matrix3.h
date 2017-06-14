#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include "DllExport.h"
#include "real.h"
#include "Matrix2.h"
class DLL Matrix3
{
public:

	static const int MAX_ROWS = 3;
	static const int MAX_COLS = 3;

	Vector3 vec[MAX_ROWS];

	Vector3& operator [] (const int &index);
	//Vector3 const operator [] (const int index);

	Matrix3(Matrix3 & other);
	Matrix3();

	Matrix3(real M11, real M12, real M13, real M21, real M22, real M23, real M31, real M32, real M33);
	Vector3 Matrix3::operator *(Vector3 & other);
	Matrix3 Matrix3::operator *(Matrix3 & other);
	Vector2 Matrix3::operator *(Vector2 & other);
	operator real*() { return &vec[0][0]; }
	void setRotateX(real radian);
	void setRotateY(real radian);
	void setRotateZ(real radian);
	Matrix3 setRotationZ(real radian);
	Matrix3 setRotationX(real radian);
	Matrix3 setRotationY(real radian);
	Matrix3 setScale(Vector2 & other);
	Matrix3 setPosition(Vector2 & other);
	real Determinant();
	Matrix3 tranpose();
	Matrix3 inverse();
	void identity();
	Matrix3 operator *(real scalar);
	void operator *= (real scalar) { *this = *this * scalar; }
	const int  getSize() { return  3; };
	 ~Matrix3();
};

