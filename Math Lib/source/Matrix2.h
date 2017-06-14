#pragma once
#include "Vector2.h"
#include "DllExport.h"
#include "real.h"

class DLL Matrix2
{
public:
static const int MAX_ROWS = 2;
static const int MAX_COLS = 2;

Vector2 vec[MAX_ROWS];

Vector2& operator [] (const int &index);
//Vector2 const operator [] (const int index);

Matrix2(Matrix2 & other);
Matrix2(real m11, real M12, real M21, real M22);
Matrix2();
Vector2 Matrix2::operator *(Vector2 & other);
Matrix2 Matrix2::operator *(Matrix2 & other);
operator real*() { return &vec[0][0]; }
void setRotate(real radian);
Matrix2 setRotation(real radian);
real Determinant();
Matrix2 inverse();
Matrix2 tranpose();
Matrix2 operator *(real scalar); 
void operator *= (real scalar) { *this = *this * scalar; }
const int  getSize() ;
~Matrix2();
};

