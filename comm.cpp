#include "comm.h"
#include <iostream>

const float  FLOATERROR = 1.0e-6F;
const double DOUBLEERROR = 1.0e-15;
const long double LONGDOUBLEERROR = 1.0e-30;

const double GoldNo = 0.618033399;		//»Æ½ð·Ö¸î³£Êý(1.0-0.381966)

//È¡x¾ø¶ÔÖµ
long double Abs(const double& x)
{
        complex<long double> cld(x);
        long double ldAbs = abs(cld);
        return(ldAbs);
}

//È¡x·ûºÅ£¬+-»ò0
double Sgn(const double& x)
{
        return x < double(0) ? double(-1) : (x > double(0) ? double(1) : double(0));
}

//±È½ÏÅÐ¶Ïfloat¸¡µãÊýÏàµÈ
bool FloatEqual(float lhs, float rhs)
{
        if (Abs(lhs - rhs) < FLOATERROR)
                return true;
        else
                return false;
}

//±È½ÏÁ½float¸¡µãÊý²»ÏàµÈ
bool FloatNotEqual(float lhs, float rhs)
{
        if (Abs(lhs - rhs) >= FLOATERROR)
                return true;
        else
                return false;
}

//±È½ÏÁ½double¸¡µãÊýÏàµÈ
bool FloatEqual(double lhs, double rhs)
{
        if (Abs(lhs - rhs) < DOUBLEERROR)
                return true;
        else
                return false;
}

//±È½ÏÁ½double¸¡µãÊý²»ÏàµÈ
bool FloatNotEqual(double lhs, double rhs)
{
        if (Abs(lhs - rhs) >= DOUBLEERROR)
                return true;
        else
                return false;
}

//±È½ÏÁ½long double¸¡µãÊýÏàµÈ
bool FloatEqual(long double lhs, long double rhs)
{
        if (Abs(lhs - rhs) < LONGDOUBLEERROR)
                return true;
        else
                return false;
}

//±È½ÏÁ½long double¸¡µãÊý²»ÏàµÈ
bool FloatNotEqual(long double lhs, long double rhs)
{
        if (Abs(lhs - rhs) >= LONGDOUBLEERROR)
                return true;
        else
                return false;
}

//ÇóxÓëyµÄ×îÐ¡Öµ£¬·µ»ØÐ¡Õß
double Min(const double& x, const double& y)
{
        if(x < y)
                return x;
        else
                return y;
}

//ÇóxÓëyµÄ×î´óÖµ£¬·µ»Ø´óÕß
double Max(const double& x, const double& y)
{
        if(x > y)
                return x;
        else
                return y;
}

//´òÓ¡Êý×é(ÏòÁ¿)ËùÓÐÔªËØÖµ
void ValarrayPrint(const valarray<double>& vOut)
{
        size_t vsize = vOut.size();		//È¡Êý×éÔªËØµÄ¸öÊý
        for(size_t st=0; st<vsize; st++)
        {
                cout.width(15);				//ÔªËØ¶ÔÆë£¬ÈÃÃ¿¸öÔªËØÕ¼15ÁÐ
                cout << vOut[st] << ' ';
        }
        cout << endl;
}

//´òÓ¡Ä³¸öÖ¸¶¨Êý×é(ÏòÁ¿)ÔªËØÖµ
void ValarrayPrint(const valarray<double>& vOut, size_t sPosition)
{
        cout.width(15);					//ÔªËØ¶ÔÆë£¬ÈÃÃ¿¸öÔªËØÕ¼15ÁÐ
        cout << vOut[sPosition] << endl;
}

