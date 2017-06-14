#include "Matrix4.h"



Matrix4::Matrix4()
{
	for (int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			vec[i][j] = 0;
		}
	}
}

Matrix4::Matrix4(real M11, real M12, real M13, real M14, real M21, real M22, real M23, real M24, real M31, real M32, real M33, real M34, real M41, real M42, real M43, real M44)
{
	vec[0][0] = M11; 
	vec[0][1] = M12;
	vec[0][2] = M13;
	vec[0][3] = M14;
	
	vec[1][0] = M21;
	vec[1][1] = M22;
	vec[1][2] = M23;
	vec[1][3] = M24;
	
	vec[2][0] = M31;
	vec[2][1] = M32;
	vec[2][2] = M33;
	vec[2][3] = M34;
		
	vec[3][0] = M41;
	vec[3][1] = M42;
	vec[3][2] = M43;
	vec[3][3] = M44;
}

Matrix4::Matrix4(Matrix4 & other)
{

	for (int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			vec[i][j] = other.vec[i][j];
		}
	}
}


Matrix4::~Matrix4()
{
}



Vector4 Matrix4::operator *(Vector4 & other)
{
	Vector4 temp;
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

Vector3 Matrix4::operator *(Vector3 & other)
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
			if (k == 3)
			{
				other[k] = 0;
			}
			sum += vec[k][j] * other[k];
		}
		temp[j] = sum;
	}
	return temp;
}

Matrix4 Matrix4::setScale(Vector3 & other)
{
	Matrix4 temp;

temp.vec[0].x = other.x;
temp.vec[0].y = 0;
temp.vec[0].z = 0;
temp.vec[0].w = 0;

temp.vec[1].x = 0;
temp.vec[1].y = other.y;
temp.vec[1].z = 0;
temp.vec[1].w = 0;

temp.vec[2].x = 0;
temp.vec[2].y = 0;
temp.vec[2].z = other.z;
temp.vec[2].w = 0;

temp.vec[3].x = 0;
temp.vec[3].y = 0;
temp.vec[3].z = 0;
temp.vec[3].w = 1;

return temp;
}

Matrix4 Matrix4::setPosition(Vector3 & other)
{
	Matrix4 temp;

temp.vec[0].x = 1;
temp.vec[0].y = 0;
temp.vec[0].z = 0;
temp.vec[0].w = 0;

temp.vec[1].x = 0;
temp.vec[1].y = 1;
temp.vec[1].z = 0;
temp.vec[1].w = 0;

temp.vec[2].x = 0;
temp.vec[2].y = 0;
temp.vec[2].z = 1;
temp.vec[2].w = 0; 

temp.vec[1].x = other.x;
temp.vec[1].y = other.y;
temp.vec[1].z = other.z;
temp.vec[1].w = 1; 

return temp;
}

Matrix4 Matrix4::tranpose()
{
	Matrix4 trans;

	for (int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			trans.vec[j][i] = vec[i][j];
		}
	}
	return trans;
}

#pragma region Rotations
Matrix4 Matrix4::setRotationZ(real radian)
{
	Matrix4 temp;

temp.vec[0].x = (real)cos(radian);
temp.vec[0].y = (real)sin(radian);
temp.vec[0].z = 0;
temp.vec[0].w = 0;

temp.vec[1].x = (real)-sin(radian);
temp.vec[1].y = (real)cos(radian);
temp.vec[1].z = 0;
temp.vec[0].w = 0;

temp.vec[2].x = 0;
temp.vec[2].y = 0;
temp.vec[2].z = 1;
temp.vec[0].w = 0;

temp.vec[3].x = 0;
temp.vec[3].y = 0;
temp.vec[3].z = 0;
temp.vec[3].w = 1;

	return temp;


}

Matrix4 Matrix4::setRotationX(real radian)
{
	Matrix4 temp;

temp.vec[0].x = 1;
temp.vec[0].y = 0;
temp.vec[0].z = 0;
temp.vec[0].w = 0;

temp.vec[1].x = 0;
temp.vec[1].y = (real)cos(radian);
temp.vec[1].z = (real)sin(radian);
temp.vec[1].w = 0;

temp.vec[2].x = 0;
temp.vec[2].y = (real)-sin(radian);
temp.vec[2].z = (real)cos(radian);
temp.vec[0].w = 0;

temp.vec[3].x = 0;
temp.vec[3].y = 0;
temp.vec[3].z = 0;
temp.vec[3].w = 1;

	return temp;


}



Matrix4 Matrix4::setRotationY(real radian)
{
	Matrix4 temp;

temp.vec[0].x = (real)cos(radian);
temp.vec[0].y = 0;
temp.vec[0].z = (real)-sin(radian);
temp.vec[0].w = 0;

temp.vec[1].x = 0;
temp.vec[1].y = 1;
temp.vec[1].z = 0;
temp.vec[0].w = 0;

temp.vec[2].x = (real)sin(radian);
temp.vec[2].y = 0;
temp.vec[2].z = (real)cos(radian);
temp.vec[0].w = 0;

temp.vec[3].x = 0;
temp.vec[3].y = 0;
temp.vec[3].z = 0;
temp.vec[3].w = 1;

	return temp;


}


void Matrix4::setRotateX(real radian)
{
	vec[0].x = 1;
	vec[0].y = 0;
	vec[0].z = 0;
	vec[0].w = 0;

	vec[1].x = 0;
	vec[1].y = (real)cos(radian);
	vec[1].z = (real)sin(radian);
	vec[1].w = 0;

	vec[2].x = 0;
	vec[2].y = (real)-sin(radian);
	vec[2].z = (real)cos(radian);
	vec[0].w = 0;


	vec[3].x = 0;
	vec[3].y = 0;
	vec[3].z = 0;
	vec[3].w = 1;

}
//(1,0,0,0,-0.668648f,-0.743579f,0,0.743579f,-0.668648f)
void Matrix4::setRotateY(real radian)
{
	vec[0].x = (real)cos(radian);
	vec[0].y = 0;
	vec[0].z = (real)-sin(radian);
	vec[0].w = 0;

	vec[1].x = 0;
	vec[1].y = 1;
	vec[1].z = 0;
	vec[0].w = 0;

	vec[2].x = (real)sin(radian);
	vec[2].y = 0;
	vec[2].z = (real)cos(radian);
	vec[0].w = 0;

	vec[3].x = 0;
	vec[3].y = 0;
	vec[3].z = 0;
	vec[3].w = 1;

}

//-0.188077f,0,-0.982154f,0,1,0,0.982154f,0,-0.188077f
void Matrix4::setRotateZ(real radian)
{
	vec[0].x = (real)cos(radian);
	vec[0].y = (real)sin(radian);
	vec[0].z = 0;
	vec[0].w = 0;

	vec[1].x = (real)-sin(radian);
	vec[1].y = (real)cos(radian);
	vec[1].z = 0;
	vec[0].w = 0;

	vec[2].x = 0;
	vec[2].y = 0;
	vec[2].z = 1;
	vec[0].w = 0;

	vec[3].x = 0;
	vec[3].y = 0;
	vec[3].z = 0;
	vec[3].w = 1;

}

#pragma endregion 

Matrix4 Matrix4::operator *(Matrix4 & other)
{
	Matrix4 temp;
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

Matrix4 Matrix4::operator*(real scalar)
{
	Matrix4 temp = *this;

	for (int i = 0; i < MAX_COLS; i++)
	{
		for (int j = 0; j < MAX_ROWS; j++)
		{
			temp.vec[i][j] *= scalar;
		}
	}
	return temp;
}


real Matrix4::Determinant()
{
	real det1 = vec[0].x * (vec[1].y *(vec[2].z * vec[3].w - vec[2].w * vec[3].z) - vec[1].z * (vec[2].y * vec[3].w - vec[2].w * vec[3].y) + vec[1].w *(vec[2].y * vec[3].z - vec[2].z * vec[3].y));
	real det2 = vec[0].y * (vec[1].x *(vec[2].z * vec[3].w - vec[2].w * vec[3].z) - vec[1].z * (vec[2].x * vec[3].w - vec[2].w * vec[3].x) + vec[1].w *(vec[2].x * vec[3].z - vec[2].z * vec[3].x));
	real det3 = vec[0].z * (vec[1].x *(vec[2].y * vec[3].w - vec[2].w * vec[3].y) - vec[1].y * (vec[2].x * vec[3].w - vec[2].w * vec[3].x) + vec[1].w *(vec[2].x * vec[3].y - vec[2].y * vec[3].x));
	real det4 = vec[0].w * (vec[1].x *(vec[2].y * vec[3].z - vec[2].z * vec[3].y) - vec[1].y * (vec[2].x * vec[3].z - vec[2].z * vec[3].x) + vec[1].z *(vec[2].x * vec[3].y - vec[2].y * vec[3].x));
	return det1 - det2 + det3 - det4 ;
}

Matrix4 Matrix4::inverse()
{
	real det = Determinant();


	Matrix4 cof;

	real *ca = &cof.vec[0][0];
	real *cb = &cof.vec[0][1];
	real *cc = &cof.vec[0][2];
	real *cd = &cof.vec[0][3];;

	real *ce = &cof.vec[1][0];
	real *cf = &cof.vec[1][1];
	real *cg = &cof.vec[1][2];
	real *ch = &cof.vec[1][3];

	real *ci = &cof.vec[2][0];
	real *cj = &cof.vec[2][1];
	real *ck = &cof.vec[2][2];
	real *cl = &cof.vec[2][3];
	
	real *cm = &cof.vec[3][0];
	real *cn = &cof.vec[3][1];
	real *co = &cof.vec[3][2];
	real *cp = &cof.vec[3][3];


	real *a = &vec[0][0];
	real *b = &vec[0][1];
	real *c = &vec[0][2];
	real *d = &vec[0][3];


	real *e = &vec[1][0];
	real *f = &vec[1][1];
	real *g = &vec[1][2];
	real *h = &vec[1][3];


	real *i = &vec[2][0];
	real *j = &vec[2][1];
	real *k = &vec[2][2];
	real *l = &vec[2][3];


	real *m = &vec[3][0];
	real *n = &vec[3][1];
	real *o = &vec[3][2];
	real *p = &vec[3][3];



	//  +a -b +c -d
	//  +e -f +g -h
	//  +i -j +k -l
	//  +m -n +o -p

	*ca = Matrix3(*f, *g, *h, *j, *k, *l, *n, *o, *p).Determinant();
	*cb = Matrix3(*e, *g, *h, *i, *k, *l, *m, *o, *p).Determinant();
	*cc = Matrix3(*e, *f, *h, *i, *j, *l, *m, *n, *p).Determinant();
	*cd = Matrix3(*e, *f, *g, *i, *j, *k, *m, *n, *o).Determinant();
	*ce = Matrix3(*b, *c, *d, *j, *k, *l, *n, *o, *p).Determinant();
	*cf = Matrix3(*e, *g, *h, *i, *k, *l, *m, *o, *p).Determinant();
	*cg = Matrix3(*e, *f, *h, *i, *j, *l, *m, *n, *p).Determinant();
	*ch = Matrix3(*f, *g, *h, *j, *k, *l, *n, *o, *p).Determinant();
	*ci = Matrix3(*b, *c, *d, *j, *k, *l, *n, *o, *p).Determinant();
	*cj = Matrix3(*a, *c, *d, *e, *g, *h, *m, *o, *p).Determinant();
	*ck = Matrix3(*a, *b, *d, *e, *f, *g, *m, *n, *o).Determinant();
	*cl = Matrix3(*a, *b, *c, *e, *f, *g, *m, *n, *o).Determinant();
	*cm = Matrix3(*b, *c, *d, *f, *g, *h, *j, *k, *l).Determinant();
	*cn = Matrix3(*a, *c, *d, *e, *g, *h, *i, *k, *l).Determinant();
	*co = Matrix3(*a, *b, *d, *e, *f, *h, *i, *j, *l).Determinant();
	*cp = Matrix3(*a, *b, *c, *e, *f, *g, *i, *j, *k).Determinant();
	
	//b , d , f , h , j, l ,n, p 
	
	*cb = -*cb;
	*cd = -*cd;
	*cf = -*cf;
	*ch = -*ch;
	*cj = -*cj;
	*cl = -*cl;
	*cn = -*cn;
	*cp = -*cp;

	cof.tranpose();

	cof *= 1.0f / det;
	return cof;
}

Vector4& Matrix4::operator[] (const int &index)
{
	return vec[index];
}
//
//Vector3 const Matrix3::operator[] (const int index)
//{
//	return vec[index];
//}