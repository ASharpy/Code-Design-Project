#include "Matrix2.h"

//initilise identity matrix in constructor 
//scale - rotate then translate
Matrix2::Matrix2()
{
	for ( int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			vec[i][j] = 0;
		}
	}
}

Matrix2::Matrix2(real M11 , real M12 , real M21 , real M22)
{
	vec[0][0] = M11;
	vec[0][1] = M12;
	vec[1][0] = M21;
	vec[1][1] = M22;
}

Matrix2::Matrix2(Matrix2 & other)
{

	for (int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			vec[i][j] = other.vec[i][j];
		}
	}
}



const int Matrix2::getSize()
{
	return 2;
}

Matrix2::~Matrix2()
{
}



Vector2 Matrix2::operator *(Vector2 & other) 
{
	Vector2 temp;
	const int P =  other.getSize();
	int M = MAX_COLS;
	int N = MAX_ROWS;
	//Vector2 vec2[2][P];


		for (int j  = 0; j <= P; j++)
		{
			real sum = 0;

			for (int k = 0; k < M; k++)
			{
				sum += vec[k][j] * other[k];
			}
			temp[j] = sum;
	}
	return temp;
}

Matrix2 Matrix2::operator *(Matrix2 & other)
{
	Matrix2 temp;
	const int P = other.getSize();
	int M = MAX_COLS;
	int N = MAX_ROWS;
	//Vector2 vec2[2][P];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < P; j++)
		{
			real sum = 0;

			for (int k = 0; k < M; k++)
			{
				sum += vec[i][k] * other[k][j];
			}
			temp[i][j] = sum;
		}
	}
	return temp;
}

void Matrix2::setRotate(real radian)
{
	vec[0].x = (real)cos(radian);
	vec[0].y = (real)sin(radian);

	vec[1].x = (real)-sin(radian);
	vec[1].y = (real)cos(radian);
}

Matrix2 Matrix2::setRotation(real radian)
{
	Matrix2 temp;

	temp.vec[0].x = (real)cos(radian);
	temp.vec[0].y = (real)sin(radian);

	temp.vec[1].x = (real)-sin(radian);
	temp.vec[1].y = (real)cos(radian);

	return temp;
}

real Matrix2::Determinant()
{
	
	return (vec[0].x * vec[1].y - vec[0].y * vec[1].x);
}

Matrix2 Matrix2::inverse()
{
	Matrix2 inverse;
	real det = 1/Determinant();

	inverse.vec[0][0] = det* vec[1][1];
	inverse.vec[0][1] = det* -vec[0][1];
	inverse.vec[1][0] = det* -vec[1][0];
	inverse.vec[1][1] = det* vec[0][0];

	return	 inverse;
}


Matrix2 Matrix2::operator*(real scalar)
{
	Matrix2 temp = *this;

	for (int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			temp.vec[i][j] *= scalar;
		}
	}
	return temp;
}


Matrix2 Matrix2::tranpose()
{
	Matrix2 trans;

	for (int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			trans.vec[j][i] = vec[i][j];
		}
	}
	return trans;
}


Vector2& Matrix2::operator[] (const int &index)
{
	return vec[index];
}


// Vector2 const Matrix2::operator[] (const int index)
//{
//	return vec[index];
//}