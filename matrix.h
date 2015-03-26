//Matrix.h
#ifndef _H_MATRIX_
#define _H_MATRIX_

#include "comm.h"
#include <math.h>
#include <assert.h>
#include <string>
#include <cstdio>
#include <iostream>

#define MAX 10000

template <class _Ty=double>
class matrix
{
	typedef matrix<_Ty> _Myt;
private:
	std::valarray<_Ty> m_Datas;
	size_t m_stRow;		//Row
	size_t m_stCol;		//Column
public:
	bool isValid;		//Valid
	typedef _Ty value_type;
	//constructor 1
	matrix(size_t stRow, size_t stCol):m_Datas(stRow*stCol),m_stRow(stRow),m_stCol(stCol),isValid(true)
	{
		m_Datas.resize(m() * n(), _Ty(0));
	}
	//constructor 2
	matrix(const _Ty* rhs, size_t stRow, size_t stCol):m_Datas(rhs, stRow*stCol),m_stRow(stRow),m_stCol(stCol),isValid(true)
	{
	}
	//constructot 3
	matrix(const _Myt &rhs):m_Datas(rhs.m_Datas),m_stRow(rhs.m()),m_stCol(rhs.n()),isValid(true)
	{
	}

	size_t m() const
	{
		return m_stRow;
	}

	size_t n() const
	{
		return m_stCol;
	}

	_Ty& operator () (size_t stRow, size_t stCol)
	{
		assert(stRow < m());	//断定stRow不超实际矩阵行值
		assert(stCol < n());	//断定stCol不超实际矩阵列值

		return m_Datas[stRow * n() + stCol];
	}
/******
 重载()运算符，返回二维矩阵中元素(stRow, stCol)在一维数组中的位置
 stRow与stCol分别为矩阵某元素行与列的位置数
 当矩阵元素在运算符右边(被读)时使用
******/
	const _Ty operator () (size_t stRow, size_t stCol) const
	{
		assert(stRow < m());	//断定stRow不超实际矩阵行值
		assert(stCol < n());	//断定stCol不超实际矩阵列值

		return m_Datas[stRow * n() + stCol];
	}

	// 赋值操作符
	//矩阵与矩阵的自反*, +, -运算符
	_Myt& operator += (const _Myt& rhs)		//矩阵与矩阵的自反+
	{
		assert(m() == rhs.m());	//断定两矩阵的行数相等
		assert(n() == rhs.n());	//断定两矩阵的列数相等
		//利用类valarray定义，使其对象m_Datas定义进行两矩阵相加
		m_Datas += rhs.m_Datas;
		//结果放在左边矩阵中，返回指向左边矩阵的指针
		return *this;
	}

	_Myt& operator -= (const _Myt& rhs)		//矩阵与矩阵的自反-
	{
		assert(m() == rhs.m());
		assert(n() == rhs.n());
		//利用类valarray定义，使其对象m_Datas定义进行两矩阵相减
		m_Datas -= rhs.m_Datas;
		//结果放在左边矩阵中，返回指向左边矩阵的指针
		return *this;
	}

	_Myt& operator *= (const _Myt& rhs)		//矩阵与矩阵的自反*
	{
		MatrixMultiply(*this, *this, rhs);	//调用矩阵乘法函数

		return *this;						//最后结果放在左边矩阵中
	}

	//矩阵自反加、减、乘以、除以数
	_Myt& operator += (const _Ty& rhs)		//矩阵自加数
	{
		m_Datas += rhs;			//利用数组对象对每个元素加数
	
		return *this;			//结果放在原矩阵(数组m_Datas)中
	}

	_Myt& operator -= (const _Ty& rhs)		//矩阵自减数
	{
		m_Datas -= rhs;

		return *this;
	}

	_Myt& operator *= (const _Ty& rhs)		//矩阵自乘数
	{
		m_Datas *= rhs;
	
		return *this;
	}

	_Myt& operator /= (const _Ty& rhs)		//矩阵自除以数
	{
		m_Datas /= rhs;

		return *this;
	}

	// 一元操作符  对矩阵(每个元素)赋予+或-号
	_Myt operator + () const	//赋+号
	{
		return *this;			//不用作任何处理，维持原状
	}

	_Myt operator - () const	//赋-号
	{
		_Myt mat(*this);
		mat.m_Datas = -mat.m_Datas;		//每个元素赋-号

		return mat;
	}

	// 二元操作符
	//矩阵加数	mat = lhs + rhs
	friend _Myt operator + (const _Myt& lhs, const _Ty& rhs)
	{
		_Myt mat(lhs);			//新生成一新矩阵对象mat
		mat.m_Datas += rhs;		//对新矩阵对象每个元素加数

		return mat;				//返回新矩阵对象
	}

	//矩阵减数	mat = lhs - rhs
	friend _Myt operator - (const _Myt& lhs, const _Ty& rhs)
	{
		_Myt mat(lhs);
		mat.m_Datas -= rhs;

		return mat;
	}

	//矩阵乘以数	mat = lhs * rhs
	friend _Myt operator * (const _Myt& lhs, const _Ty& rhs)
	{
		_Myt mat(lhs);			//新生成一新矩阵对象mat
		mat.m_Datas *= rhs;		//对新矩阵对象每个元素乘以数

		return mat;				//返回新矩阵对象
	}

	//矩阵除以数	mat = lhs / rhs
	friend _Myt operator / (const _Myt& lhs, const _Ty& rhs)
	{
		_Myt mat(lhs);
		mat.m_Datas /= rhs;

		return mat;
	}

	//数加矩阵	mat = lhs + rhs
	friend _Myt operator + (const _Ty& lhs, const _Myt& rhs)
	{
		_Myt mat(rhs);			//新生成一新矩阵对象mat
		mat.m_Datas += lhs;		//数加上新矩阵对象的每个元素

		return mat;
	}

	//数减矩阵	mat = lhs - rhs
	friend _Myt operator - (const _Ty& lhs, const _Myt& rhs)
	{
		_Myt mat(rhs);			//新生成一新矩阵对象mat
		mat.m_Datas -= lhs;		//数减新矩阵对象的每个元素

		return mat;
	}

	//数乘以矩阵	mat = lhs * rhs
	friend _Myt operator * (const _Ty& lhs, const _Myt& rhs)
	{
		_Myt mat(rhs);			//新生成一新矩阵对象mat
		mat.m_Datas *= lhs;		//对新矩阵对象每个元素乘以数

		return mat;
	}

	//矩阵加矩阵	mat = lhs + rhs
	friend _Myt operator + (const _Myt& lhs, const _Myt& rhs)
	{
		_Myt mat(lhs);					//新生成一新矩阵对象mat, 用左边阵初始化
		mat.m_Datas += rhs.m_Datas;		//加上右边矩阵对象每个相应元素

		return mat;						//返回新矩阵对象
	}

	//矩阵减矩阵	mat = lhs - rhs
	friend _Myt operator - (const _Myt& lhs, const _Myt& rhs)
	{
		_Myt mat(lhs);					//新生成一新矩阵对象mat, 用左边阵初始化
		mat.m_Datas -= rhs.m_Datas;		//减去右边矩阵对象每个相应元素

		return mat;						//返回新矩阵对象
	}

	//矩阵乘以矩阵	mTmp = lhs * rhs
	friend _Myt operator * (const _Myt& lhs, const _Myt& rhs)
	{	//生成一个矩阵新对象mTmp		
		_Myt mTmp(lhs.m(), rhs.n());	//没初始化

		MatrixMultiply(mTmp, lhs, rhs);			//调用矩阵乘法函数

		return mTmp;		//用新矩阵对象返回
	}

	//矩阵比较
	//比较两矩阵是否不相等，若相等返回true，否则返回false
	friend bool operator != (const _Myt& lhs, const _Myt& rhs)
	{
		if (lhs.m() != rhs.m())
			return true;
		if (lhs.n() != rhs.n())
			return true;

		for (size_t i = 0; i < lhs.m_Datas.size(); i ++)
		{
			if (lhs.m_Datas[i] != rhs.m_Datas[i])
				return true;
		}

		return false;
	}

	//比较两矩阵是否相等，若相等返回true，否则返回false
	friend bool operator == (const _Myt& lhs, const _Myt& rhs)
	{
		if (lhs.m() != rhs.m())
			return false;
		if (lhs.n() != rhs.n())
			return false;

		for (size_t i = 0; i < lhs.m_Datas.size(); i ++)
		{
			if (lhs.m_Datas[i] != rhs.m_Datas[i])
				return false;
		}

		return true;
	}

	
	//改变元素的值
	void setElem(int i,int j,double value)
	{
		m_Datas[j * n() + i] = value;
	}

	//返回i,j位置的元素
        double getElem(int i,int j) const
	{
		return m_Datas[j * n() + i];
	}

	// 以数组形式返回第i行元素 若失败则返回NULL
        double * row(int i) const
	{
		try{
			int k;
			double * rElements = (double *)malloc(sizeof(double)*m_stCol);
			for(k = 0;k < m_stCol;k++)
				*(rElements + k) = m_Datas[i * n() + k];
			return rElements;
		}
		catch(...)
		{
			return NULL;
		}
	}

	// 以数组形式返回第j列元素 若失败则返回NULL
        double * col(int j) const
	{
		try{
			int k;
			double * cElements = (double *)malloc(sizeof(double)*m_stRow);
			for(k = 0;k < m_stRow;k++)
				*(cElements + k) = m_Datas[j  + k * m()];
			return cElements;
		}
		catch(...)
		{
			return NULL;
		}
	}

	// 返回能输出在屏幕上的字符串
	string disp() const
	{
		if (!isValid) {
			return "<Invalid Matrix>";
		}
		char* strOut = (char *)malloc(sizeof(char)*MAX);
		int offset = 0;
		
		int i,j;
		for(i = 0;i < m_stRow; i ++)
		{
			for(j = 0;j < m_stCol; j ++)
			{
				offset += sprintf(strOut + offset,"%10.6lf    ",m_Datas[i * m_stCol + j]);
			}
			offset += sprintf(strOut + offset,"\n");
		}
		string out(strOut);
		return out;
	}
};

typedef matrix<float> matrixf;
typedef matrix<double> matrixd;
typedef matrixd Matrix;

//Multiply
template<class _Tyout, class _Tylhs, class _Tyrhs>
matrix<_Tyout>& MatrixMultiply(matrix<_Tyout>& mOut, const matrix<_Tylhs>& lhs, const matrix<_Tyrhs>& rhs)
{	//断定左边矩阵的列数与右边矩阵的行数相等
	assert(lhs.n() == rhs.m());
	//生成矩阵新对象，用lhs的行作为新阵的行数，用rhs的列数作为新阵的列数
	matrix<_Tyout> mTmp(lhs.m(), rhs.n());

	for(size_t i = 0; i < mTmp.m(); i ++)
	{
		for(size_t j = 0; j < mTmp.n(); j ++)
		{
			mTmp(i, j) = _Tyout(0);		//赋初值0
			for(size_t k = 0; k < lhs.n(); k ++)
			{
				mTmp(i, j) += lhs(i, k) * rhs(k, j);
			}
		}
	}

	mOut = mTmp;		//将最后结果转放入mOut矩阵中
	return mOut;		//返回结果矩阵mOut
}
//Print by line
template<class _Ty>
void MatrixLinePrint(const matrix<_Ty>& mOut)
{	
	size_t sR, sC;
	sR=mOut.m();
	sC=mOut.n();

	for(size_t stR=0; stR<mOut.m(); stR++)
	{
		for(size_t stC=0; stC<mOut.n(); stC++)
		{
                        std::cout.width(15);				//元素对齐，让每个元素占15列
                        std::cout << mOut(stR, stC) << ' ';
		}
                std::cout << endl;
	}
}
//Print one line
template<class _Ty>
void MatrixLinePrint(const matrix<_Ty>& mOut, size_t LineNo)
{	
	size_t sR, sC;

	sR=mOut.m();
	sC=mOut.n();

	for(size_t stC=0; stC<mOut.n(); stC++)
	{
                std::cout.width(15);				//元素对齐，让每个元素占15列
                std::cout << mOut(LineNo, stC) << ' ';
	}
        std::cout << endl;
}
//transposition
template<class _Ty>
void MatrixTranspose(matrix<_Ty>& mIn, matrix<_Ty>& mOut)
{
	size_t sR, sC;
	sR = mIn.m();			//取原矩阵行数
	sC = mIn.n();			//取原矩阵列数

	matrix<_Ty> mTemp(sC, sR);		//生成一新阵，行数与列数与原阵互换

	for(size_t stC=0; stC<sC; stC++)
		for(size_t stR=0; stR<sR; stR++)
			mTemp(stC, stR) = mIn(stR, stC);	//对新阵赋值

	mOut = mTemp;					//返回新的转置阵
}
//Symmetry
template<class _Ty>
bool MatrixSymmetry(const matrix<_Ty>& rhs)
{
	bool bSy = true;
	size_t stRow = rhs.m();	//取矩阵行数

	if(rhs.n() == stRow)	// 必须是方阵
	{
		for(size_t i = 1; i < stRow; i ++)			//判断是否对称
			for(size_t j = 0; j < i; j ++)
				if(FloatNotEqual((double)rhs(i, j), (double)rhs(j, i)))
				{
					bSy =  false;
					goto RET;
				}
	}
	else
		bSy = false;
RET: return bSy;	//矩阵对称
}
//Determinant
template<class _Ty>
double MatrixDeterminant(const matrix<_Ty>& rhs)		
{	
	double  MaxValue, tmp;
	size_t stRank = rhs.n();	// 矩阵阶数
	if(stRank != rhs.m())
		return double(0);			//rhs不是方阵

	matrix<double> m(stRank, stRank);	//生成一matrix对象

	for(size_t i=0; i<stRank; i++)
		for(size_t j=0; j<stRank; j++)
			m(i, j) = (double)rhs(i, j);	//初始化

	size_t iSign, jSign;				// 主元的位置标志

	double Det(1);					// 行列式的值

	int	nSgn = 1;						// 符号

	for(size_t k = 0; k < stRank - 1; k ++)	// 全选主元
	{	
		MaxValue = 0.0;
		for(size_t i = k; i < stRank; i ++)
		{
			for(size_t j = k; j < stRank; j ++)
			{
				tmp = Abs(m(i, j));		//求m(i,j)绝对值
				if(tmp > MaxValue)
				{
					MaxValue = tmp;
					iSign = i;			//记下主元位置
					jSign = j;
				}
			}
		}

		if(FloatEqual(MaxValue, 0))	//绝对值最大元素为0，行列式也为0
			return double(0);

		if(iSign != k)			//绝对值最大元素不在当前行
		{
			nSgn = -nSgn;		//变换行列式符号
			for(size_t j = k; j < stRank; j ++)		//交换行
				swap(m(k, j), m(iSign, j));
		}

		if(jSign != k)			//绝对值最大元素不在当前列
		{
			nSgn = -nSgn;		//变换行列式符号
			for(size_t i = k; i < stRank; i ++)		//交换列
				swap(m(i, jSign), m(i, k));
		}

		Det *= m(k, k);					//对角元相乘
		for(size_t i = k + 1; i < stRank; i ++)
		{
			double d(m(i, k) / m(k, k));		//消元因子
			for(size_t j = k + 1; j < stRank; j ++)	//将主元下方元素消为0
				m(i, j) -= d * m(k, j);	//当前主元行下行其余元素作变换
		}
	}

	return Det * nSgn * m(stRank - 1, stRank - 1);	//返回行列式数值
}
//Symmetry Regular
template<class _Ty>
int MatrixSymmetryRegular(const matrix<_Ty>& rhs, int sym)
{							
	double ldDet;
	size_t i, j, k;

	size_t sC = rhs.n();	//矩阵列数
	size_t sR = rhs.m();	//矩阵行数

	size_t stRank = sR;				// 矩阵阶数
	if(stRank != rhs.m())
		return int(-1);				// 不是方阵

	if(sym > 0)
		if(MatrixSymmetry(rhs)==false)
			return int(-2);			//rhs不是对称阵

        std::cout << " K = 1 \t Determinant = " << rhs(0, 0) <<endl;

	for(k = 0; k < stRank; k ++)	//若要判别半正定，负定，这句要修改
	{
		if(FloatEqual(rhs(k, k), 0)||rhs(k, k) < 0)
			return int(-3);	//对角元不大于0，矩阵不是正定阵
	}

	for(k = 2; k <= sR; k++)
	{
		matrix<double> m(k, k);	//生成一matrix对象

		for(i=0; i<k; i++)
			for(j=0; j<k; j++)
				m(i, j) = (double)rhs(i, j);	//初始化

		ldDet = MatrixDeterminant(m);				// 顺序主子式的值

                std::cout << " K = " << k << "\t Determinant = " << ldDet << endl;

		if(FloatEqual(ldDet,0) || ldDet < 0.0)
			return (0);					//不是正定阵
	}
	if(sym == 1) return int(2);			//矩阵为正定对称阵
	else		 return int(1);			//矩阵为正定阵
}
//Rank
template<class _Ty>
size_t MatrixRank(const matrix<_Ty>& rhs)
{
	size_t iSign, jSign;					//主元的位置标志
	size_t mRank = 0;						//矩阵秩数
	size_t stRow = rhs.m();			//取矩阵行数
	size_t stCol = rhs.n();			//取矩阵列数
	size_t ColRowMin = Min(stRow, stCol);	//取行或列最小值

	matrix<_Ty> m(rhs);				//生成一matrix对象，用rhs初始化

	for(size_t k = 0; k < ColRowMin; k ++)
	{	// 全选主元
		double MaxValue(0);
		for(size_t i = k; i < stRow; i ++)
		{
			for(size_t j = k; j < stCol; j ++)
			{
				double tmp(Abs(m(i, j)));	//求m(i,j)绝对值
				if(tmp > MaxValue)
				{
					MaxValue = tmp;
					iSign = i;					//记下主元位置
					jSign = j;
				}
			}
		}

		//子阵元素绝对值最大者为0，	注意浮点数与0相等的定义，见comm.h
		if(FloatEqual(MaxValue, 0)) 
			break;	//return mRank;
		else				
			mRank++;		//子阵元素绝对值最大者不为0，矩阵秩加1

		if(k ==(ColRowMin - 1))		//已到最后一行(列)
			break;	//return mRank;

		if(iSign != k)				//主元不在当前行
		{
			for(size_t j = k; j < stCol; j ++)	//交换行元素
				swap(m(k, j), m(iSign, j));
		}

		if(jSign != k)				//主元不在当前列
		{
			for(size_t i = k; i < stRow; i ++)	//交换列元素
				swap(m(i, jSign), m(i, k));
		}

		for(size_t i = k + 1; i < stRow; i ++)
		{
			const _Ty d(m(i, k) / m(k, k));		//消元因子
			for(size_t j = k + 1; j < stCol; j ++)	
				m(i, j) -= d * m(k, j);		//当前主元右下阵元素作变换
		}
	}
	return mRank;
}
//Inversion
template<class _Ty>
int MatrixInversionGS(matrix<_Ty >& rhs)
{
	size_t stRank = rhs.n();	// 矩阵阶数
	if(stRank != rhs.m())
		return int(-1);					//rhs不是方阵

	valarray<size_t> is(stRank);		//行交换信息
	valarray<size_t> js(stRank);		//列交换信息

	matrix<_Ty> m(rhs);					//生成一matrix对象

	for(size_t k = 0; k < stRank; k++)
	{	// 全选主元
		double MaxValue(0);
		for(size_t i = k; i < stRank; i ++)
		{
			for(size_t j = k; j < stRank; j ++)
			{
				double tmp(Abs(m(i, j)));	//求m(i,j)绝对值
				if(tmp > MaxValue)				//主元不在对角线上
				{
					MaxValue = tmp;
					is[k] = i;					//记录主元行数
					js[k] = j;					//记录主元列数
				}
			}
		}

		if(FloatEqual(MaxValue, 0)) 
			return int(0);						//主元为0，矩阵奇异

		if(is[k] != k)							//主元不在当前行
		{
			for(size_t j = 0; j < stRank; j ++)	//交换行元素
				swap(m(k, j), m(is[k], j));
		}

		if(js[k] != k)							//主元不在当前列
		{
			for(size_t i = 0; i < stRank; i ++)	//交换列元素
				swap(m(i, k), m(i, js[k]));
		}

		m(k, k) = 1.0 / m(k, k);				//主元倒数
		for(size_t j = 0; j < stRank; j ++)
			if(j != k)
				m(k, j) *= m(k, k);

		for(size_t i = 0; i < stRank; i ++)
			if(i != k)
				for(size_t j = 0; j < stRank; j ++)	
					if(j != k)
						m(i, j) = m(i, j) - m(i, k) * m(k, j);

		for(size_t i = 0; i < stRank; i ++)
			if(i != k)
				m(i, k) = -m(i, k) * m(k, k);
	}

	for(int r = stRank - 1; r >= 0; r--)
	{
		if(js[r] != r)
			for(size_t j = 0; j < stRank; j ++)
				swap(m(r, j), m(js[r], j));
		if(is[r] != r)
			for(size_t i = 0; i < stRank; i ++)
				swap(m(i, r), m(i, is[r]));
	}

	rhs = m;

	return int(1);
}
//Symmetry Regular Inversion
template<class _Ty>
int MatrixSymmetryRegularInversion(matrix<_Ty>& rhs)
{
	int iSym = MatrixSymmetryRegular(rhs, 1);	//判别是否对称正定
	if(iSym < 2)
		return (iSym);			//rhs不是对称正定阵

	size_t stRank = rhs.n();	// 矩阵阶数

	matrix<_Ty> msr(rhs);			//生成一matrix对象，用rhs初始化

	valarray<_Ty> b(stRank);

	for(size_t k=0; k<stRank; k++)
	{
		_Ty w= msr(0, 0);
		size_t m = stRank - k -1;
		for(size_t i = 1; i < stRank; i++)
		{
			_Ty g = msr(i, 0);
			b[i] = g / w;
			if(i <= m) b[i] = -b[i];
			for(size_t j = 1; j <= i; j ++)
				msr((i-1),(j-1)) = msr(i, j) + g * b[j];
		}
		msr(stRank-1, stRank-1) = 1.0 / w;
		for(size_t i = 1; i < stRank; i ++)
			msr(stRank-1,(i-1)) =  b[i];
	}
	for(size_t i = 0; i < stRank-1; i ++)
		for(size_t j = i+1; j < stRank; j ++)
			msr(i,j) = msr(j, i);

	rhs = msr;

	return (iSym);
}
/************************************************************
//zeros
template<class _Ty>
_Myt zeros(_Ty &m_st);
_Myt zeros(_Ty &m_stRow, _Ty &m_stCol);

//eye
template<class _Ty>
_Myt eye(_Ty &m_st);
_Myt eye(_Ty &m_stRow, _Ty m_stCol);

//magic
template<class _Ty>
_Myt zeros(_Ty &m_st);

//rand
template<class _Ty>
_Myt rand(_Ty &m_st);
_Myt rand(_Ty &m_stRow, _Ty &m_stCol);

//randn
template<class _Ty>
_Myt randn(_Ty &m_st);
_Myt randn(_Ty &m_stRow, _Ty &m_stCol);
*/

#endif // _H_MATRIX_
