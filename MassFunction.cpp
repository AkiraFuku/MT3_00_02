#include "MassFunction.h"
//
// 
// 
// 
// 

void MatrixScreenPrintf(int x, int y, const Matrix4x4& m, const char* label)
{
	Novice::ScreenPrintf(x, y, "%s", label);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){

			Novice::ScreenPrintf(x + kColumnWidth * (j), y + kRowHeight * (i+1), "%6.02f", m.m[i][j]);
		}
	}
}
//
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2){
		Matrix4x4 result={};
		for (int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				result.m[i][j]=m1.m[i][j]+m2.m[i][j];
			}
		}
		return result;
	}
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2){
		Matrix4x4 result={};
		for (int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				result.m[i][j]=m1.m[i][j]-m2.m[i][j];
			}
		}
		return result;
	}
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2){
		Matrix4x4 result={};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					result.m[i][j] += m1.m[i][k] * m2.m[k][j];
				}
			}
		}
		
		return result;
	}
	Matrix4x4 Inverse(const Matrix4x4& m){
			float det =
				(m.m[0][0]*m.m[1][1]*m.m[2][2]*m.m[3][3])+(m.m[0][0]*m.m[1][2]*m.m[2][3]*m.m[3][1])+(m.m[0][0]*m.m[1][3]*m.m[2][1]*m.m[3][2])
			-	(m.m[0][0]*m.m[1][3]*m.m[2][2]*m.m[3][1])-(m.m[0][0]*m.m[1][2]*m.m[2][1]*m.m[3][3])-(m.m[0][0]*m.m[1][1]*m.m[2][3]*m.m[3][2])
			-	(m.m[0][1]*m.m[1][0]*m.m[2][2]*m.m[3][3])-(m.m[0][2]*m.m[1][0]*m.m[2][3]*m.m[3][1])-(m.m[0][3]*m.m[1][0]*m.m[2][1]*m.m[3][2])
			+	(m.m[0][3]*m.m[1][0]*m.m[2][2]*m.m[3][1])+(m.m[0][2]*m.m[1][0]*m.m[2][1]*m.m[3][3])+(m.m[0][1]*m.m[1][0]*m.m[2][3]*m.m[3][2])
			+	(m.m[0][1]*m.m[1][2]*m.m[2][0]*m.m[3][3])+(m.m[0][2]*m.m[1][3]*m.m[2][0]*m.m[3][1])+(m.m[0][3]*m.m[1][1]*m.m[2][0]*m.m[3][2])
			-	(m.m[0][3]*m.m[1][2]*m.m[2][0]*m.m[3][1])-(m.m[0][2]*m.m[1][1]*m.m[2][0]*m.m[3][3])-(m.m[0][1]*m.m[1][3]*m.m[2][0]*m.m[3][2])
			-	(m.m[0][1]*m.m[1][2]*m.m[2][3]*m.m[3][0])-(m.m[0][2]*m.m[1][3]*m.m[2][1]*m.m[3][0])-(m.m[0][3]*m.m[1][1]*m.m[2][2]*m.m[3][0])
			+	(m.m[0][3]*m.m[1][2]*m.m[2][1]*m.m[3][0])+(m.m[0][2]*m.m[1][1]*m.m[2][3]*m.m[3][0])+(m.m[0][1]*m.m[1][3]*m.m[2][2]*m.m[3][0])
			;
		Matrix4x4 result=
		{
			{
			//0
				{///0
					(1 / det)*(
						 (m.m[1][1]*(m.m[2][2]*m.m[3][3]-m.m[2][3]*m.m[3][2]))
						+(m.m[1][2]*(m.m[2][3]*m.m[3][1]-m.m[2][1]*m.m[3][3]))
						+(m.m[1][3]*(m.m[2][1]*m.m[3][2]-m.m[2][2]*m.m[3][1]))
						),
				////

				 ///1
					-(1 / det)*(
						 (m.m[2][1]*(m.m[3][2]*m.m[0][3]-m.m[3][3]*m.m[0][2]))
						+(m.m[2][2]*(m.m[3][3]*m.m[0][1]-m.m[3][1]*m.m[0][3]))
						+(m.m[2][3]*(m.m[3][1]*m.m[0][2]-m.m[3][2]*m.m[0][1]))
					),
				////
		
				///2,
					(1 / det)*(
						 (m.m[3][1]*(m.m[0][2]*m.m[1][3]-m.m[0][3]*m.m[1][2]))
						+(m.m[3][2]*(m.m[0][3]*m.m[1][1]-m.m[0][1]*m.m[1][3]))
						+(m.m[3][3]*(m.m[0][1]*m.m[1][2]-m.m[0][2]*m.m[1][1]))
						),
				////

				///3
					-(1 / det)*(
						 (m.m[0][1]*(m.m[1][2]*m.m[2][3]-m.m[1][3]*m.m[2][2]))
						+(m.m[0][2]*(m.m[1][3]*m.m[2][1]-m.m[1][1]*m.m[2][3]))
						+(m.m[0][3]*(m.m[1][1]*m.m[2][2]-m.m[1][2]*m.m[2][1]))
						),
				////
				},
			////
			
			//1
				{
				///0
				-(1 / det)*(
						 (m.m[1][2]*(m.m[2][3]*m.m[3][0]-m.m[2][0]*m.m[3][3]))
						+(m.m[1][3]*(m.m[2][0]*m.m[3][2]-m.m[2][2]*m.m[3][0]))
						+(m.m[1][0]*(m.m[2][2]*m.m[3][3]-m.m[2][3]*m.m[3][2]))
						),
				////

				///1
				(1 / det)*(
						 (m.m[2][2]*(m.m[3][3]*m.m[0][0]-m.m[3][0]*m.m[0][3]))
						+(m.m[2][3]*(m.m[3][0]*m.m[0][2]-m.m[3][2]*m.m[0][0]))
						+(m.m[2][0]*(m.m[3][2]*m.m[0][3]-m.m[3][3]*m.m[0][2]))
						),
				////

				///2
				-(1 / det)*(
						 (m.m[3][2]*(m.m[0][3]*m.m[1][0]-m.m[0][0]*m.m[1][3]))
						+(m.m[3][3]*(m.m[0][0]*m.m[1][2]-m.m[0][2]*m.m[1][0]))
						+(m.m[3][0]*(m.m[0][2]*m.m[1][3]-m.m[0][3]*m.m[1][2]))
						),
				///3
				(1 / det)*(
						 (m.m[0][2]*(m.m[1][3]*m.m[2][0]-m.m[1][0]*m.m[2][3]))
						+(m.m[0][3]*(m.m[1][0]*m.m[2][2]-m.m[1][2]*m.m[2][0]))
						+(m.m[0][0]*(m.m[1][2]*m.m[2][3]-m.m[1][3]*m.m[2][2]))
						),
				////

				},
			////
			
			//2
				{
				///0
				(1 / det)*(
						 (m.m[1][3]*(m.m[2][0]*m.m[3][1]-m.m[2][1]*m.m[3][0]))
						+(m.m[1][0]*(m.m[2][1]*m.m[3][3]-m.m[2][3]*m.m[3][1]))
						+(m.m[1][1]*(m.m[2][3]*m.m[3][0]-m.m[2][0]*m.m[3][3]))
						),
				////

				///1
				-(1 / det)*(
						 (m.m[2][3]*(m.m[3][0]*m.m[0][1]-m.m[3][1]*m.m[0][0]))
						+(m.m[2][0]*(m.m[3][1]*m.m[0][3]-m.m[3][3]*m.m[0][1]))
						+(m.m[2][1]*(m.m[3][3]*m.m[0][0]-m.m[3][0]*m.m[0][3]))
						),
				////
				
				///2
				(1 / det)*(
						 (m.m[3][3]*(m.m[0][0]*m.m[1][1]-m.m[0][1]*m.m[1][0]))
						+(m.m[3][0]*(m.m[0][1]*m.m[1][3]-m.m[0][3]*m.m[1][1]))
						+(m.m[3][1]*(m.m[0][3]*m.m[1][0]-m.m[0][0]*m.m[1][3]))
						),
				////
			
				///3
				-(1 / det)*(
						 (m.m[0][3]*(m.m[1][0]*m.m[2][1]-m.m[1][1]*m.m[2][0]))
						+(m.m[0][0]*(m.m[1][1]*m.m[2][3]-m.m[1][3]*m.m[2][1]))
						+(m.m[0][1]*(m.m[1][3]*m.m[2][0]-m.m[1][0]*m.m[2][3]))
						),
				},
			////
			
			//3
				{
				///0
				-(1 / det)*(
						 (m.m[1][0]*(m.m[2][1]*m.m[3][2]-m.m[2][2]*m.m[3][1]))
						+(m.m[1][1]*(m.m[2][2]*m.m[3][0]-m.m[2][0]*m.m[3][2]))
						+(m.m[1][2]*(m.m[2][0]*m.m[3][1]-m.m[2][1]*m.m[3][0]))
						),
				///1
				(1 / det)*(
						 (m.m[2][0]*(m.m[3][1]*m.m[0][2]-m.m[3][2]*m.m[0][1]))
						+(m.m[2][1]*(m.m[3][2]*m.m[0][0]-m.m[3][0]*m.m[0][2]))
						+(m.m[2][2]*(m.m[3][0]*m.m[0][1]-m.m[3][1]*m.m[0][0]))
						),
				///2
				-(1 / det)*(
						 (m.m[3][0]*(m.m[0][1]*m.m[1][2]-m.m[0][2]*m.m[1][1]))
						+(m.m[3][1]*(m.m[0][2]*m.m[1][0]-m.m[0][0]*m.m[1][2]))
						+(m.m[3][2]*(m.m[0][0]*m.m[1][1]-m.m[0][1]*m.m[1][0]))
						),
				///3
				(1 / det)*(
						 (m.m[0][0]*(m.m[1][1]*m.m[2][2]-m.m[1][2]*m.m[2][1]))
						+(m.m[0][1]*(m.m[1][2]*m.m[2][0]-m.m[1][0]*m.m[2][2]))
						+(m.m[0][2]*(m.m[1][0]*m.m[2][1]-m.m[1][1]*m.m[2][0]))
						),
				}
			}
		};
		
		
	

		return result;
	}
	Matrix4x4 Transpose(const Matrix4x4& m)
	{
		
		return Matrix4x4(
		{
			
				{m.m[0][0], m.m[1][0], m.m[2][0], m.m[3][0]},
				{m.m[0][1], m.m[1][1], m.m[2][1], m.m[3][1]},
				{m.m[0][2], m.m[1][2], m.m[2][2], m.m[3][2]},
				{m.m[0][3], m.m[1][3], m.m[2][3], m.m[3][3]}
		}
		);
	}
	Matrix4x4 Makeidetity4x4(){
		return Matrix4x4(
			{
				{1,0,0,0},
				{0,1,0,0},
				{0,0,1,0},
				{0,0,0,1}
			}
		
		);
	}
//}//namespace KamataEngine{
//	void VectorScreenPrintf(int x, int y, Vector3& vector, const char* label){
//		Novice::ScreenPrintf(x, y, "%.02f", vector.x);
//		Novice::ScreenPrintf(x + KColumnWidth, y, "%.02f", vector.y);
//		Novice::ScreenPrintf(x + KColumnWidth * 2, y, "%.02f", vector.z);
//		Novice::ScreenPrintf(x + KColumnWidth * 3, y, "%s", label);
//	}
//	//加算
//	Vector3 Add(const Vector3& v1, const Vector3& v2){
//		Vector3 result={
//			v1.x + v2.x,
//			v1.y + v2.y,
//			v1.z + v2.z
//		
//		};
//		return result;
//	}
//	//
//	Vector3 Subtract(const Vector3& v1, const Vector3& v2){
//		Vector3 result = {
//			v1.x - v2.x,
//			v1.y - v2.y,
//			v1.z - v2.z
//		};
//		return result;
//	}
//	//
//	Vector3 Multiply(float scalar, const Vector3& v){
//		Vector3 result = {
//			scalar * v.x,
//			scalar * v.y,
//			scalar * v.z
//		};
//		return result;
//	}
//	//
//	float Dot(const Vector3& v1, const Vector3& v2){
//		
//		float result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
//		return result ;
//	}
//	//
//	float Length(const Vector3& v){
//		float length = v.x * v.x + v.y * v.y + v.z * v.z;
//		if (length > 0.0f) {
//			return sqrtf(length);
//		}
//		return length;
//	}
//	//
//	Vector3 Normalize(const Vector3& v){
//		float length = Length(v);
//		if (length > 0.0f) {
//			Vector3 result = {
//				v.x / length,
//				v.y / length,
//				v.z / length
//			};
//			return result;
//		}
//		Vector3 result = { 0.0f, 0.0f, 0.0f };
//		return result;
//
//	}