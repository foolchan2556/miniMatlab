#ifndef _H_COMM_
#define _H_COMM_

#include <complex>		//ģ����complex�ı�׼ͷ�ļ�
#include <valarray>		//ģ����valarray�ı�׼ͷ�ļ�

using namespace std;	//���ֿռ�

extern const float  FLOATERROR;
extern const double DOUBLEERROR;
extern const long double LONGDOUBLEERROR;

extern const double GoldNo;

long double Abs(const double& x);
double Sgn(const double& x);
bool FloatEqual(float lhs, float rhs);
bool FloatNotEqual(float lhs, float rhs);
bool FloatEqual(double lhs, double rhs);
bool FloatNotEqual(double lhs, double rhs);
bool FloatEqual(long double lhs, long double rhs);
bool FloatNotEqual(long double lhs, long double rhs);
double Min(const double& x, const double& y);
double Max(const double& x, const double& y);
void ValarrayPrint(const valarray<double>& vOut);
void ValarrayPrint(const valarray<double>& vOut, size_t sPosition);

#endif // _H_COMM_
