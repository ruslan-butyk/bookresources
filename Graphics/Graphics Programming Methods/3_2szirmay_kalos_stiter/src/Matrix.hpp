#pragma once

typedef float m3x3Type[3][3];

//! Simple matrix to support Triangle::getShadingNormal
class Matrix3x3 {
public:
	m3x3Type m;
	
	inline void Fill (float m00, float m01, float m02,
					float m10, float m11, float m12,
					float m20, float m21, float m22){
		m[0][0] = m00;
		m[0][1] = m01;
		m[0][2] = m02;

		m[1][0] = m10;
		m[1][1] = m11;
		m[1][2] = m12;

		m[2][0] = m20;
		m[2][1] = m21;
		m[2][2] = m22;
	}

	inline void InvertMatrix3x3 (Matrix3x3& mA);
	inline void MultiplyMatrixLeft (const Vector* vIn, Vector* vOut);
};


void Matrix3x3::InvertMatrix3x3 (Matrix3x3& mA) 
{
	m3x3Type& A = mA.m;
	
	// generated by maple  C(A_inv,optimized);       
	float		t4 = A[0][0]*A[1][1];
	float 	    t6 = A[0][0]*A[1][2];
	float 	    t8 = A[0][1]*A[1][0];
	float 	    t10 = A[0][2]*A[1][0];
	float 	    t12 = A[0][1]*A[2][0];
	float 	    t14 = A[0][2]*A[2][0];
	float 	    t17 = 1/(t4*A[2][2]-t6*A[2][1]-t8*A[2][2]+t10*A[2][1]+t12*A[1][2]-t14*A[1][1]);
	
	m[0][0] = (A[1][1]*A[2][2]-A[1][2]*A[2][1])*t17;
	m[0][1] = -(A[0][1]*A[2][2]-A[0][2]*A[2][1])*t17;
	m[0][2] = -(-A[0][1]*A[1][2]+A[0][2]*A[1][1])*t17;
	m[1][0] = -(A[1][0]*A[2][2]-A[1][2]*A[2][0])*t17;
	m[1][1] = (A[0][0]*A[2][2]-t14)*t17;
	m[1][2] = -(t6-t10)*t17;
	m[2][0] = -(-A[1][0]*A[2][1]+A[1][1]*A[2][0])*t17;
	m[2][1] = -(A[0][0]*A[2][1]-t12)*t17;
	m[2][2] = (t4-t8)*t17;
}

//! vOut = Matrix * vIn,  matrix is on the left side
inline void Matrix3x3::MultiplyMatrixLeft (const Vector* vIn, Vector* vOut)
{
	vOut->x = vIn->x * m[0][0] + vIn->y * m[0][1] + vIn->z * m[0][2];
	vOut->y = vIn->x * m[1][0] + vIn->y * m[1][1] + vIn->z * m[1][2];
	vOut->z = vIn->x * m[2][0] + vIn->y * m[2][1] + vIn->z * m[2][2];
}