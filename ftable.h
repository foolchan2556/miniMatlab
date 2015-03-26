#ifndef _H_FTABLE_
#define _H_FTABLE_


#include "matrix.h"

typedef matrix<double> _Myt;

class Ftable
{
	public:
	static _Myt * eval(const string & fname,_Myt params[], const int nparam);
};

#endif // _H_FTABLE_
