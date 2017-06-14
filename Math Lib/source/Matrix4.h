#pragma once
#include "Vector4.h"
#include "Vector3.h"
#include "DllExport.h"
#include "real.h"
#include "Matrix3.h"
class DLL Matrix4
{
public:
	static const int MAX_ROWS = 4;
	static const int MAX_COLS = 4;

	Vector4 vec[MAX_ROWS];

	Vector4& operator [] (const int &index);
	//Vector3 const operator [] (const int index);

	Matrix4(Matrix4 & other);
	Matrix4();

	Matrix4(real M11, real M12, real M13, real M14, real M21, real M22, real M23, real M24, real M31, real M32, real M33, real M34, real M41, real M42, real M43, real M44);
	Vector4 Matrix4::operator *(Vector4 & other);
	Matrix4 Matrix4::operator *(Matrix4 & other);
	Vector3 Matrix4::operator *(Vector3 & other);
	operator real*() { return &vec[0][0]; }
	
	void setRotateX(real radian);
	void setRotateY(real radian);
	void setRotateZ(real radian);
	Matrix4 setRotationZ(real radian);
	Matrix4 setRotationX(real radian);
	Matrix4 setRotationY(real radian);
	Matrix4 setScale(Vector3 & other);
	Matrix4 setPosition(Vector3 & other);
	Matrix4 tranpose();
	real Determinant();
	Matrix4 inverse();
	Matrix4 operator *(real scalar);
	void operator *= (real scalar) { *this = *this * scalar; }
	const int  getSize() { return  4; };
	~Matrix4();
};

