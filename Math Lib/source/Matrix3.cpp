#include "Matrix3.h"


Matrix3::Matrix3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				vec[i][j] = 1;
			}
			else
			{
				vec[i][j] = 0;
			}
		}
	}
}

Matrix3::Matrix3(real M11, real M12, real M13, real M21, real M22, real M23, real M31, real M32, real M33)
{
	vec[0][0] = M11;
	vec[0][1] = M12;
	vec[0][2] = M13;
	vec[1][0] = M21;
	vec[1][1] = M22;
	vec[1][2] = M23;
	vec[2][0] = M31;
	vec[2][1] = M32;
	vec[2][2] = M33;
}

Matrix3::Matrix3(Matrix3 & other)
{

	for (int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			vec[i][j] = other.vec[i][j];
		}
	}
}


Matrix3::~Matrix3()
{
}







Vector3 Matrix3::operator *(Vector3 & other)
{
	Vector3 temp;
	const int P = other.getSize();
	int M = MAX_COLS;
	int N = MAX_ROWS;
	//Vector2 vec2[2][P];


	for (int j = 0; j <= P; j++)
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

//double check with paper and pen
Vector2 Matrix3::operator *(Vector2 & other)
{
	Vector2 temp;
	const int P = other.getSize();
	int M = MAX_COLS;
	int N = MAX_ROWS;
	//Vector2 vec2[2][P];


	for (int j = 0; j <= P; j++)
	{
		real sum = 0;

		for (int k = 0; k < M; k++)
		{
			if (k == 2)
			{
				other[k] = 0;
			}

			sum += vec[k][j] * other[k];
		
		}
		temp[j] = sum;
	}
	return temp;
}


Matrix3 Matrix3::operator *(Matrix3 & other)
{
	Matrix3 temp;
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
				sum += vec[k][j] * other[i][k];
					
			}
			temp[i][j] = sum;
		}
	}
	return temp;
}

#pragma region rotations
void Matrix3::setRotateX(real radian)
{
	vec[0].x = 1;
	vec[0].y = 0;
	vec[0].z = 0;

	vec[1].x = 0;
	vec[1].y = (real)cos(radian);
	vec[1].z = (real)sin(radian);
	
	vec[2].x = 0;
	vec[2].y = (real)-sin(radian);
	vec[2].z = (real)cos(radian);
}
//(1,0,0,0,-0.668648f,-0.743579f,0,0.743579f,-0.668648f)
void Matrix3::setRotateY(real radian)
{
	vec[0].x = (real)cos(radian);
	vec[0].y = 0;
	vec[0].z = (real)-sin(radian);

	vec[1].x = 0;
	vec[1].y = 1;
	vec[1].z = 0;

	vec[2].x = (real)sin(radian);
	vec[2].y = 0;
	vec[2].z = (real)cos(radian);
}
//-0.188077f,0,-0.982154f,0,1,0,0.982154f,0,-0.188077f
void Matrix3::setRotateZ(real radian)
{
	vec[0].x = (real)cos(radian);
	vec[0].y = (real)sin(radian);
	vec[0].z = 0;

	vec[1].x = (real)-sin(radian);
	vec[1].y = (real)cos(radian);
	vec[1].z = 0;

	vec[2].x = 0;
	vec[2].y = 0;
	vec[2].z = 1;
}

Matrix3 Matrix3::setRotationZ(real radian)
{
	Matrix3 temp;

	temp.vec[0].x = (real)cos(radian);
	temp.vec[0].y = (real)sin(radian);
	temp.vec[0].z = 0;

	temp.vec[1].x = (real)-sin(radian);
	temp.vec[1].y = (real)cos(radian);
	temp.vec[1].z = 0;

	temp.vec[2].x = 0;
	temp.vec[2].y = 0;
	temp.vec[2].z = 1;

	return temp;


}

Matrix3 Matrix3::setRotationX(real radian)
{
	Matrix3 temp;
	temp.vec[0].x = 1;
	temp.vec[0].y = 0;
	temp.vec[0].z = 0;

	temp.vec[1].x = 0;
	temp.vec[1].y = (real)cos(radian);
	temp.vec[1].z = (real)sin(radian);

	temp.vec[2].x = 0;
	temp.vec[2].y = (real)-sin(radian);
	temp.vec[2].z = (real)cos(radian);

	return temp;


}



Matrix3 Matrix3::setRotationY(real radian)
{
	Matrix3 temp;

	temp.vec[0].x = (real)cos(radian);
	temp.vec[0].y = 0;
	temp.vec[0].z = (real)-sin(radian);

	temp.vec[1].x = 0;
	temp.vec[1].y = 1;
	temp.vec[1].z = 0;

	temp.vec[2].x = (real)sin(radian);
	temp.vec[2].y = 0;
	temp.vec[2].z = (real)cos(radian);

	return temp;


}

#pragma endregion both return a matrix and change the base matrix



Matrix3 Matrix3::setScale(Vector2 & other)
{
	Matrix3 temp;

	temp.vec[0].x = other.x;
	temp.vec[0].y = 0;
	temp.vec[0].z = 0;

	temp.vec[1].x = 0;
	temp.vec[1].y = other.y;
	temp.vec[1].z = 0;

	temp.vec[2].x = 0;
	temp.vec[2].y = 0;
	temp.vec[2].z = 1;

	return temp;
}

Matrix3 Matrix3::setPosition(Vector2 & other)
{
	Matrix3 temp;

		temp.vec[0].x = 1;
		temp.vec[0].y = 0;
		temp.vec[0].z = 0;

		temp.vec[1].x = 0;
		temp.vec[1].y = 1;
		temp.vec[1].z = 0;

		temp.vec[2].x = other.x;
		temp.vec[2].y = other.y;
	    temp.vec[2].z = 1;
		return temp;
}



//            a  b  c  d  e  f  g   h  i
//Matrix3 mat(3, 4, 5, 6, 7, 8, 9, 10, 11);
real Matrix3::Determinant()
{
	return (vec[0].x *(vec[1].y * vec[2].z - vec[1].z * vec[2].y) - vec[0].y * (vec[1].x * vec[2].z - vec[1].z * vec[2].x) + vec[0].z *(vec[1].x * vec[2].y - vec[1].y * vec[2].x));
	      
}

Matrix3 Matrix3::tranpose()
{
      	Matrix3 trans;

		for (int i = 0; i < MAX_COLS; i++)
		{
			for (int j = 0; j < MAX_ROWS; j++)
			{
				trans.vec[j][i] = vec[i][j];
			}
		}
		return trans;
	
}


//inverse of a matrix is the transpose of a cofactor / determanant 
Matrix3 Matrix3::inverse()
{
	real det = Determinant();

	Matrix3 co;

	real *ca = &co.vec[0][0];
	real *cb = &co.vec[0][1];
	real *cc = &co.vec[0][2];
	real *cd = &co.vec[1][0];
	real *ce = &co.vec[1][1];
	real *cf = &co.vec[1][2];
	real *cg = &co.vec[2][0];
	real *ch = &co.vec[2][1];
	real *ci = &co.vec[2][2];

	real *a = &vec[0][0];
	real *b = &vec[0][1];
	real *c = &vec[0][2];
	real *d = &vec[1][0];
	real *e = &vec[1][1];
	real *f = &vec[1][2];
	real *g = &vec[2][0];
	real *h = &vec[2][1];
	real *i = &vec[2][2];




//  a b c
//  d e f
//  g h i

	*ca = Matrix2(*e, *f, *h, *i).Determinant();
	*cb = Matrix2(*d, *e, *g, *i).Determinant();
	*cc = Matrix2(*d, *e, *g, *h).Determinant();
	*cd = Matrix2(*b ,*c ,*h, *i).Determinant();
	*ce = Matrix2(*a, *c, *g, *i).Determinant();
	*cf = Matrix2(*a, *b, *g, *h).Determinant();
	*cg = Matrix2(*b, *c, *e, *f).Determinant();
	*ch = Matrix2(*a, *c, *d, *f).Determinant();
	*ci = Matrix2(*a, *b, *d, *e).Determinant();

	//b , d , f , h 
	*cb = -*cb;
	*cd = -*cd;
	*cf = -*cf;
	*ch = -*ch;

	co.tranpose();

	co *= 1.0f / det;
	return co;
}

void Matrix3::identity()
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				vec[i][j] = 1;
			}
			else
			{
				vec[i][j] = 0;
			}
		}
	}

}

Matrix3 Matrix3::operator*(real scalar)
{
	Matrix3 temp = *this;

	for (int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			temp.vec[i][j] *= scalar;
		}
	}
	return temp;
}



Vector3& Matrix3::operator[] (const int &index)
{
	return vec[index];
}
//
//Vector3 const Matrix3::operator[] (const int index)
//{
//	return vec[index];
//}