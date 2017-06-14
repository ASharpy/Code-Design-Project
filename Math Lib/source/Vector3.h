#pragma once
#include <math.h>
#include "Vector4.h"
#include "Vector2.h"
#include "DllExport.h"
#include "real.h"

class DLL Vector3
{
public:

	Vector3();
	Vector3(real newX, real newY , real newZ);
	Vector3(const Vector3& other);

	 ~Vector3();
	real & operator[] (const int &index);

	const real  operator[] (const int index) const;

	operator Vector2();
	operator Vector4();
	Vector3 operator+(Vector3 & other) const;
	Vector3 operator-(Vector3 & vector) const;
	Vector3 operator*(const real scalar);
	friend Vector3 operator*(real scalar, Vector3 &vector) { return vector * scalar; }
	real dot(Vector3 & other) const;
	Vector3 Vector3::cross(Vector3 & other) const;
	real magnitude();
	void normalise();
	const int  getSize() { return  2; };
	//************************************************************************************
	//                      OveLoadeded Cast operator
	//************************************************************************************
	operator real*() { return &V[0]; }
	//************************************************************************************
	//************************************************************************************
	
	union
	{
		struct { real x, y, z; };
		real V[3];
	};

#pragma region swizzle
	/*
	* GetXX
	*
	* swizzles vector to (x,x)
	*
	* @returns Vector2 - the swizzled vector
	*/
	Vector2 GetXX();

	/*
	* GetXY
	*
	* swizzles vector to (x,y)
	*
	* @returns Vector2 - the swizzled vector
	*/
	Vector2 GetXY();

	/*
	* GetXZ
	*
	* swizzles vector to (x,z)
	*
	* @returns Vector2 - the swizzled vector
	*/
	Vector2 GetXZ();

	/*
	* GetYX
	*
	* swizzles vector to (y,x)
	*
	* @returns Vector2 - the swizzled vector
	*/
	Vector2 GetYX();

	/*
	* GetYY
	*
	* swizzles vector to (y,y)
	*
	* @returns Vector2 - the swizzled vector
	*/
	Vector2 GetYY();

	/*
	* GetYZ
	*
	* swizzles vector to (y,z)
	*
	* @returns Vector2 - the swizzled vector
	*/
	Vector2 GetYZ();

	/*
	* GetZX
	*
	* swizzles vector to (z,x)
	*
	* @returns Vector2 - the swizzled vector
	*/
	Vector2 GetZX();

	/*
	* GetZY
	*
	* swizzles vector to (z,y)
	*
	* @returns Vector2 - the swizzled vector
	*/
	Vector2 GetZY();

	/*
	* GetZZ
	*
	* swizzles vector to (z,z)
	*
	* @returns Vector2 - the swizzled vector
	*/
	Vector2 GetZZ();

	/*
	* GetXXX
	*
	* swizzles vector to (x,x,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetXXX();

	/*
	* GetXXY
	*
	* swizzles vector to (x,x,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetXXY();

	/*
	* GetXXZ
	*
	* swizzles vector to (x,x,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetXXZ();

	/*
	* GetXYX
	*
	* swizzles vector to (x,y,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetXYX();

	/*
	* GetXYY
	*
	* swizzles vector to (x,y,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetXYY();

	/*
	* GetXZX
	*
	* swizzles vector to (x,z,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetXZX();

	/*
	* GetXZY
	*
	* swizzles vector to (x,z,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetXZY();

	/*
	* GetXZZ
	*
	* swizzles vector to (x,z,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetXZZ();

	/*
	* GetYXX
	*
	* swizzles vector to (y,x,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetYXX();

	/*
	* GetYXY
	*
	* swizzles vector to (y,x,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetYXY();

	/*
	* GetYXZ
	*
	* swizzles vector to (y,x,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetYXZ();

	/*
	* GetYYX
	*
	* swizzles vector to (y,y,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetYYX();

	/*
	* GetYYY
	*
	* swizzles vector to (y,y,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetYYY();

	/*
	* GetYYZ
	*
	* swizzles vector to (y,y,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetYYZ();

	/*
	* GetYZX
	*
	* swizzles vector to (y,z,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetYZX();

	/*
	* GetYZY
	*
	* swizzles vector to (y,z,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetYZY();

	/*
	* GetYZZ
	*
	* swizzles vector to (y,z,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetYZZ();

	/*
	* GetZXX
	*
	* swizzles vector to (z,x,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetZXX();

	/*
	* GetZXY
	*
	* swizzles vector to (z,x,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetZXY();

	/*
	* GetZXZ
	*
	* swizzles vector to (z,x,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetZXZ();

	/*
	* GetZYX
	*
	* swizzles vector to (z,y,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetZYX();

	/*
	* GetZYY
	*
	* swizzles vector to (z,y,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetZYY();

	/*
	* GetZYZ
	*
	* swizzles vector to (z,y,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetZYZ();

	/*
	* GetZZX
	*
	* swizzles vector to (z,z,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetZZX();

	/*
	* GetZZY
	*
	* swizzles vector to (z,z,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetZZY();

	/*
	* GetZZZ
	*
	* swizzles vector to (z,z,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	Vector3 GetZZZ();

	/*
	* GetXXXX
	*
	* swizzles vector to (x,x,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXXXX();

	/*
	* GetXXXY
	*
	* swizzles vector to (x,x,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXXXY();

	/*
	* GetXXXZ
	*
	* swizzles vector to (x,x,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXXXZ();

	/*
	* GetXXYX
	*
	* swizzles vector to (x,x,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXXYX();

	/*
	* GetXXYY
	*
	* swizzles vector to (x,x,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXXYY();

	/*
	* GetXXYZ
	*
	* swizzles vector to (x,x,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXXYZ();

	/*
	* GetXXZX
	*
	* swizzles vector to (x,x,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXXZX();

	/*
	* GetXXZY
	*
	* swizzles vector to (x,x,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXXZY();

	/*
	* GetXXZZ
	*
	* swizzles vector to (x,x,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXXZZ();

	/*
	* GetXYXX
	*
	* swizzles vector to (x,y,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXYXX();

	/*
	* GetXYXY
	*
	* swizzles vector to (x,y,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXYXY();

	/*
	* GetXYXZ
	*
	* swizzles vector to (x,y,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXYXZ();

	/*
	* GetXYYX
	*
	* swizzles vector to (x,y,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXYYX();

	/*
	* GetXYYY
	*
	* swizzles vector to (x,y,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXYYY();

	/*
	* GetXYYZ
	*
	* swizzles vector to (x,y,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXYYZ();

	/*
	* GetXYZX
	*
	* swizzles vector to (x,y,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXYZX();

	/*
	* GetXYZY
	*
	* swizzles vector to (x,y,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXYZY();

	/*
	* GetXYZZ
	*
	* swizzles vector to (x,y,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXYZZ();

	/*
	* GetXZXX
	*
	* swizzles vector to (x,z,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXZXX();

	/*
	* GetXZXY
	*
	* swizzles vector to (x,z,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXZXY();

	/*
	* GetXZXZ
	*
	* swizzles vector to (x,z,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXZXZ();

	/*
	* GetXZYX
	*
	* swizzles vector to (x,z,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXZYX();

	/*
	* GetXZYY
	*
	* swizzles vector to (x,z,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXZYY();

	/*
	* GetXZYZ
	*
	* swizzles vector to (x,z,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXZYZ();

	/*
	* GetXZZX
	*
	* swizzles vector to (x,z,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXZZX();

	/*
	* GetXZZY
	*
	* swizzles vector to (x,z,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXZZY();

	/*
	* GetXZZZ
	*
	* swizzles vector to (x,z,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetXZZZ();

	/*
	* GetYXXX
	*
	* swizzles vector to (y,x,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYXXX();

	/*
	* GetYXXY
	*
	* swizzles vector to (y,x,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYXXY();

	/*
	* GetYXXZ
	*
	* swizzles vector to (y,x,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYXXZ();

	/*
	* GetYXYX
	*
	* swizzles vector to (y,x,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYXYX();

	/*
	* GetYXYY
	*
	* swizzles vector to (y,x,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYXYY();

	/*
	* GetYXYZ
	*
	* swizzles vector to (y,x,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYXYZ();

	/*
	* GetYXZX
	*
	* swizzles vector to (y,x,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYXZX();

	/*
	* GetYXZY
	*
	* swizzles vector to (y,x,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYXZY();

	/*
	* GetYXZZ
	*
	* swizzles vector to (y,x,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYXZZ();

	/*
	* GetYYXX
	*
	* swizzles vector to (y,y,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYYXX();

	/*
	* GetYYXY
	*
	* swizzles vector to (y,y,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYYXY();

	/*
	* GetYYXZ
	*
	* swizzles vector to (y,y,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYYXZ();

	/*
	* GetYYYX
	*
	* swizzles vector to (y,y,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYYYX();

	/*
	* GetYYYY
	*
	* swizzles vector to (y,y,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYYYY();

	/*
	* GetYYYZ
	*
	* swizzles vector to (y,y,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYYYZ();

	/*
	* GetYYZX
	*
	* swizzles vector to (y,y,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYYZX();

	/*
	* GetYYZY
	*
	* swizzles vector to (y,y,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYYZY();

	/*
	* GetYYZZ
	*
	* swizzles vector to (y,y,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYYZZ();

	/*
	* GetYZXX
	*
	* swizzles vector to (y,z,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYZXX();

	/*
	* GetYZXY
	*
	* swizzles vector to (y,z,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYZXY();

	/*
	* GetYZXZ
	*
	* swizzles vector to (y,z,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYZXZ();

	/*
	* GetYZYX
	*
	* swizzles vector to (y,z,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYZYX();

	/*
	* GetYZYY
	*
	* swizzles vector to (y,z,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYZYY();

	/*
	* GetYZYZ
	*
	* swizzles vector to (y,z,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYZYZ();

	/*
	* GetYZZX
	*
	* swizzles vector to (y,z,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYZZX();

	/*
	* GetYZZY
	*
	* swizzles vector to (y,z,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYZZY();

	/*
	* GetYZZZ
	*
	* swizzles vector to (y,z,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetYZZZ();

	/*
	* GetZXXX
	*
	* swizzles vector to (z,x,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZXXX();

	/*
	* GetZXXY
	*
	* swizzles vector to (z,x,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZXXY();

	/*
	* GetZXXZ
	*
	* swizzles vector to (z,x,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZXXZ();

	/*
	* GetZXYX
	*
	* swizzles vector to (z,x,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZXYX();

	/*
	* GetZXYY
	*
	* swizzles vector to (z,x,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZXYY();

	/*
	* GetZXYZ
	*
	* swizzles vector to (z,x,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZXYZ();

	/*
	* GetZXZX
	*
	* swizzles vector to (z,x,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZXZX();

	/*
	* GetZXZY
	*
	* swizzles vector to (z,x,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZXZY();

	/*
	* GetZXZZ
	*
	* swizzles vector to (z,x,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZXZZ();

	/*
	* GetZYXX
	*
	* swizzles vector to (z,y,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZYXX();

	/*
	* GetZYXY
	*
	* swizzles vector to (z,y,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZYXY();

	/*
	* GetZYXZ
	*
	* swizzles vector to (z,y,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZYXZ();

	/*
	* GetZYYX
	*
	* swizzles vector to (z,y,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZYYX();

	/*
	* GetZYYY
	*
	* swizzles vector to (z,y,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZYYY();

	/*
	* GetZYYZ
	*
	* swizzles vector to (z,y,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZYYZ();

	/*
	* GetZYZX
	*
	* swizzles vector to (z,y,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZYZX();

	/*
	* GetZYZY
	*
	* swizzles vector to (z,y,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZYZY();

	/*
	* GetZYZZ
	*
	* swizzles vector to (z,y,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZYZZ();

	/*
	* GetZZXX
	*
	* swizzles vector to (z,z,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZZXX();

	/*
	* GetZZXY
	*
	* swizzles vector to (z,z,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZZXY();

	/*
	* GetZZXZ
	*
	* swizzles vector to (z,z,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZZXZ();

	/*
	* GetZZYX
	*
	* swizzles vector to (z,z,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZZYX();

	/*
	* GetZZYY
	*
	* swizzles vector to (z,z,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZZYY();

	/*
	* GetZZYZ
	*
	* swizzles vector to (z,z,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZZYZ();

	/*
	* GetZZZX
	*
	* swizzles vector to (z,z,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZZZX();

	/*
	* GetZZZY
	*
	* swizzles vector to (z,z,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZZZY();

	/*
	* GetZZZZ
	*
	* swizzles vector to (z,z,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	Vector4 GetZZZZ();


#pragma endregion swizzle

};

