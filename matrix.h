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
		assert(stRow < m());	//�϶�stRow����ʵ�ʾ�����ֵ
		assert(stCol < n());	//�϶�stCol����ʵ�ʾ�����ֵ

		return m_Datas[stRow * n() + stCol];
	}
/******
 ����()����������ض�ά������Ԫ��(stRow, stCol)��һά�����е�λ��
 stRow��stCol�ֱ�Ϊ����ĳԪ�������е�λ����
 ������Ԫ����������ұ�(����)ʱʹ��
******/
	const _Ty operator () (size_t stRow, size_t stCol) const
	{
		assert(stRow < m());	//�϶�stRow����ʵ�ʾ�����ֵ
		assert(stCol < n());	//�϶�stCol����ʵ�ʾ�����ֵ

		return m_Datas[stRow * n() + stCol];
	}

	// ��ֵ������
	//�����������Է�*, +, -�����
	_Myt& operator += (const _Myt& rhs)		//�����������Է�+
	{
		assert(m() == rhs.m());	//�϶���������������
		assert(n() == rhs.n());	//�϶���������������
		//������valarray���壬ʹ�����m_Datas����������������
		m_Datas += rhs.m_Datas;
		//���������߾����У�����ָ����߾����ָ��
		return *this;
	}

	_Myt& operator -= (const _Myt& rhs)		//�����������Է�-
	{
		assert(m() == rhs.m());
		assert(n() == rhs.n());
		//������valarray���壬ʹ�����m_Datas����������������
		m_Datas -= rhs.m_Datas;
		//���������߾����У�����ָ����߾����ָ��
		return *this;
	}

	_Myt& operator *= (const _Myt& rhs)		//�����������Է�*
	{
		MatrixMultiply(*this, *this, rhs);	//���þ���˷�����

		return *this;						//�����������߾�����
	}

	//�����Է��ӡ��������ԡ�������
	_Myt& operator += (const _Ty& rhs)		//�����Լ���
	{
		m_Datas += rhs;			//������������ÿ��Ԫ�ؼ���
	
		return *this;			//�������ԭ����(����m_Datas)��
	}

	_Myt& operator -= (const _Ty& rhs)		//�����Լ���
	{
		m_Datas -= rhs;

		return *this;
	}

	_Myt& operator *= (const _Ty& rhs)		//�����Գ���
	{
		m_Datas *= rhs;
	
		return *this;
	}

	_Myt& operator /= (const _Ty& rhs)		//�����Գ�����
	{
		m_Datas /= rhs;

		return *this;
	}

	// һԪ������  �Ծ���(ÿ��Ԫ��)����+��-��
	_Myt operator + () const	//��+��
	{
		return *this;			//�������κδ���ά��ԭ״
	}

	_Myt operator - () const	//��-��
	{
		_Myt mat(*this);
		mat.m_Datas = -mat.m_Datas;		//ÿ��Ԫ�ظ�-��

		return mat;
	}

	// ��Ԫ������
	//�������	mat = lhs + rhs
	friend _Myt operator + (const _Myt& lhs, const _Ty& rhs)
	{
		_Myt mat(lhs);			//������һ�¾������mat
		mat.m_Datas += rhs;		//���¾������ÿ��Ԫ�ؼ���

		return mat;				//�����¾������
	}

	//�������	mat = lhs - rhs
	friend _Myt operator - (const _Myt& lhs, const _Ty& rhs)
	{
		_Myt mat(lhs);
		mat.m_Datas -= rhs;

		return mat;
	}

	//���������	mat = lhs * rhs
	friend _Myt operator * (const _Myt& lhs, const _Ty& rhs)
	{
		_Myt mat(lhs);			//������һ�¾������mat
		mat.m_Datas *= rhs;		//���¾������ÿ��Ԫ�س�����

		return mat;				//�����¾������
	}

	//���������	mat = lhs / rhs
	friend _Myt operator / (const _Myt& lhs, const _Ty& rhs)
	{
		_Myt mat(lhs);
		mat.m_Datas /= rhs;

		return mat;
	}

	//���Ӿ���	mat = lhs + rhs
	friend _Myt operator + (const _Ty& lhs, const _Myt& rhs)
	{
		_Myt mat(rhs);			//������һ�¾������mat
		mat.m_Datas += lhs;		//�������¾�������ÿ��Ԫ��

		return mat;
	}

	//��������	mat = lhs - rhs
	friend _Myt operator - (const _Ty& lhs, const _Myt& rhs)
	{
		_Myt mat(rhs);			//������һ�¾������mat
		mat.m_Datas -= lhs;		//�����¾�������ÿ��Ԫ��

		return mat;
	}

	//�����Ծ���	mat = lhs * rhs
	friend _Myt operator * (const _Ty& lhs, const _Myt& rhs)
	{
		_Myt mat(rhs);			//������һ�¾������mat
		mat.m_Datas *= lhs;		//���¾������ÿ��Ԫ�س�����

		return mat;
	}

	//����Ӿ���	mat = lhs + rhs
	friend _Myt operator + (const _Myt& lhs, const _Myt& rhs)
	{
		_Myt mat(lhs);					//������һ�¾������mat, ��������ʼ��
		mat.m_Datas += rhs.m_Datas;		//�����ұ߾������ÿ����ӦԪ��

		return mat;						//�����¾������
	}

	//���������	mat = lhs - rhs
	friend _Myt operator - (const _Myt& lhs, const _Myt& rhs)
	{
		_Myt mat(lhs);					//������һ�¾������mat, ��������ʼ��
		mat.m_Datas -= rhs.m_Datas;		//��ȥ�ұ߾������ÿ����ӦԪ��

		return mat;						//�����¾������
	}

	//������Ծ���	mTmp = lhs * rhs
	friend _Myt operator * (const _Myt& lhs, const _Myt& rhs)
	{	//����һ�������¶���mTmp		
		_Myt mTmp(lhs.m(), rhs.n());	//û��ʼ��

		MatrixMultiply(mTmp, lhs, rhs);			//���þ���˷�����

		return mTmp;		//���¾�����󷵻�
	}

	//����Ƚ�
	//�Ƚ��������Ƿ���ȣ�����ȷ���true�����򷵻�false
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

	//�Ƚ��������Ƿ���ȣ�����ȷ���true�����򷵻�false
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

	
	//�ı�Ԫ�ص�ֵ
	void setElem(int i,int j,double value)
	{
		m_Datas[j * n() + i] = value;
	}

	//����i,jλ�õ�Ԫ��
        double getElem(int i,int j) const
	{
		return m_Datas[j * n() + i];
	}

	// ��������ʽ���ص�i��Ԫ�� ��ʧ���򷵻�NULL
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

	// ��������ʽ���ص�j��Ԫ�� ��ʧ���򷵻�NULL
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

	// �������������Ļ�ϵ��ַ���
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
{	//�϶���߾�����������ұ߾�����������
	assert(lhs.n() == rhs.m());
	//���ɾ����¶�����lhs������Ϊ�������������rhs��������Ϊ���������
	matrix<_Tyout> mTmp(lhs.m(), rhs.n());

	for(size_t i = 0; i < mTmp.m(); i ++)
	{
		for(size_t j = 0; j < mTmp.n(); j ++)
		{
			mTmp(i, j) = _Tyout(0);		//����ֵ0
			for(size_t k = 0; k < lhs.n(); k ++)
			{
				mTmp(i, j) += lhs(i, k) * rhs(k, j);
			}
		}
	}

	mOut = mTmp;		//�������ת����mOut������
	return mOut;		//���ؽ������mOut
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
                        std::cout.width(15);				//Ԫ�ض��룬��ÿ��Ԫ��ռ15��
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
                std::cout.width(15);				//Ԫ�ض��룬��ÿ��Ԫ��ռ15��
                std::cout << mOut(LineNo, stC) << ' ';
	}
        std::cout << endl;
}
//transposition
template<class _Ty>
void MatrixTranspose(matrix<_Ty>& mIn, matrix<_Ty>& mOut)
{
	size_t sR, sC;
	sR = mIn.m();			//ȡԭ��������
	sC = mIn.n();			//ȡԭ��������

	matrix<_Ty> mTemp(sC, sR);		//����һ����������������ԭ�󻥻�

	for(size_t stC=0; stC<sC; stC++)
		for(size_t stR=0; stR<sR; stR++)
			mTemp(stC, stR) = mIn(stR, stC);	//������ֵ

	mOut = mTemp;					//�����µ�ת����
}
//Symmetry
template<class _Ty>
bool MatrixSymmetry(const matrix<_Ty>& rhs)
{
	bool bSy = true;
	size_t stRow = rhs.m();	//ȡ��������

	if(rhs.n() == stRow)	// �����Ƿ���
	{
		for(size_t i = 1; i < stRow; i ++)			//�ж��Ƿ�Գ�
			for(size_t j = 0; j < i; j ++)
				if(FloatNotEqual((double)rhs(i, j), (double)rhs(j, i)))
				{
					bSy =  false;
					goto RET;
				}
	}
	else
		bSy = false;
RET: return bSy;	//����Գ�
}
//Determinant
template<class _Ty>
double MatrixDeterminant(const matrix<_Ty>& rhs)		
{	
	double  MaxValue, tmp;
	size_t stRank = rhs.n();	// �������
	if(stRank != rhs.m())
		return double(0);			//rhs���Ƿ���

	matrix<double> m(stRank, stRank);	//����һmatrix����

	for(size_t i=0; i<stRank; i++)
		for(size_t j=0; j<stRank; j++)
			m(i, j) = (double)rhs(i, j);	//��ʼ��

	size_t iSign, jSign;				// ��Ԫ��λ�ñ�־

	double Det(1);					// ����ʽ��ֵ

	int	nSgn = 1;						// ����

	for(size_t k = 0; k < stRank - 1; k ++)	// ȫѡ��Ԫ
	{	
		MaxValue = 0.0;
		for(size_t i = k; i < stRank; i ++)
		{
			for(size_t j = k; j < stRank; j ++)
			{
				tmp = Abs(m(i, j));		//��m(i,j)����ֵ
				if(tmp > MaxValue)
				{
					MaxValue = tmp;
					iSign = i;			//������Ԫλ��
					jSign = j;
				}
			}
		}

		if(FloatEqual(MaxValue, 0))	//����ֵ���Ԫ��Ϊ0������ʽҲΪ0
			return double(0);

		if(iSign != k)			//����ֵ���Ԫ�ز��ڵ�ǰ��
		{
			nSgn = -nSgn;		//�任����ʽ����
			for(size_t j = k; j < stRank; j ++)		//������
				swap(m(k, j), m(iSign, j));
		}

		if(jSign != k)			//����ֵ���Ԫ�ز��ڵ�ǰ��
		{
			nSgn = -nSgn;		//�任����ʽ����
			for(size_t i = k; i < stRank; i ++)		//������
				swap(m(i, jSign), m(i, k));
		}

		Det *= m(k, k);					//�Խ�Ԫ���
		for(size_t i = k + 1; i < stRank; i ++)
		{
			double d(m(i, k) / m(k, k));		//��Ԫ����
			for(size_t j = k + 1; j < stRank; j ++)	//����Ԫ�·�Ԫ����Ϊ0
				m(i, j) -= d * m(k, j);	//��ǰ��Ԫ����������Ԫ�����任
		}
	}

	return Det * nSgn * m(stRank - 1, stRank - 1);	//��������ʽ��ֵ
}
//Symmetry Regular
template<class _Ty>
int MatrixSymmetryRegular(const matrix<_Ty>& rhs, int sym)
{							
	double ldDet;
	size_t i, j, k;

	size_t sC = rhs.n();	//��������
	size_t sR = rhs.m();	//��������

	size_t stRank = sR;				// �������
	if(stRank != rhs.m())
		return int(-1);				// ���Ƿ���

	if(sym > 0)
		if(MatrixSymmetry(rhs)==false)
			return int(-2);			//rhs���ǶԳ���

        std::cout << " K = 1 \t Determinant = " << rhs(0, 0) <<endl;

	for(k = 0; k < stRank; k ++)	//��Ҫ�б�����������������Ҫ�޸�
	{
		if(FloatEqual(rhs(k, k), 0)||rhs(k, k) < 0)
			return int(-3);	//�Խ�Ԫ������0��������������
	}

	for(k = 2; k <= sR; k++)
	{
		matrix<double> m(k, k);	//����һmatrix����

		for(i=0; i<k; i++)
			for(j=0; j<k; j++)
				m(i, j) = (double)rhs(i, j);	//��ʼ��

		ldDet = MatrixDeterminant(m);				// ˳������ʽ��ֵ

                std::cout << " K = " << k << "\t Determinant = " << ldDet << endl;

		if(FloatEqual(ldDet,0) || ldDet < 0.0)
			return (0);					//����������
	}
	if(sym == 1) return int(2);			//����Ϊ�����Գ���
	else		 return int(1);			//����Ϊ������
}
//Rank
template<class _Ty>
size_t MatrixRank(const matrix<_Ty>& rhs)
{
	size_t iSign, jSign;					//��Ԫ��λ�ñ�־
	size_t mRank = 0;						//��������
	size_t stRow = rhs.m();			//ȡ��������
	size_t stCol = rhs.n();			//ȡ��������
	size_t ColRowMin = Min(stRow, stCol);	//ȡ�л�����Сֵ

	matrix<_Ty> m(rhs);				//����һmatrix������rhs��ʼ��

	for(size_t k = 0; k < ColRowMin; k ++)
	{	// ȫѡ��Ԫ
		double MaxValue(0);
		for(size_t i = k; i < stRow; i ++)
		{
			for(size_t j = k; j < stCol; j ++)
			{
				double tmp(Abs(m(i, j)));	//��m(i,j)����ֵ
				if(tmp > MaxValue)
				{
					MaxValue = tmp;
					iSign = i;					//������Ԫλ��
					jSign = j;
				}
			}
		}

		//����Ԫ�ؾ���ֵ�����Ϊ0��	ע�⸡������0��ȵĶ��壬��comm.h
		if(FloatEqual(MaxValue, 0)) 
			break;	//return mRank;
		else				
			mRank++;		//����Ԫ�ؾ���ֵ����߲�Ϊ0�������ȼ�1

		if(k ==(ColRowMin - 1))		//�ѵ����һ��(��)
			break;	//return mRank;

		if(iSign != k)				//��Ԫ���ڵ�ǰ��
		{
			for(size_t j = k; j < stCol; j ++)	//������Ԫ��
				swap(m(k, j), m(iSign, j));
		}

		if(jSign != k)				//��Ԫ���ڵ�ǰ��
		{
			for(size_t i = k; i < stRow; i ++)	//������Ԫ��
				swap(m(i, jSign), m(i, k));
		}

		for(size_t i = k + 1; i < stRow; i ++)
		{
			const _Ty d(m(i, k) / m(k, k));		//��Ԫ����
			for(size_t j = k + 1; j < stCol; j ++)	
				m(i, j) -= d * m(k, j);		//��ǰ��Ԫ������Ԫ�����任
		}
	}
	return mRank;
}
//Inversion
template<class _Ty>
int MatrixInversionGS(matrix<_Ty >& rhs)
{
	size_t stRank = rhs.n();	// �������
	if(stRank != rhs.m())
		return int(-1);					//rhs���Ƿ���

	valarray<size_t> is(stRank);		//�н�����Ϣ
	valarray<size_t> js(stRank);		//�н�����Ϣ

	matrix<_Ty> m(rhs);					//����һmatrix����

	for(size_t k = 0; k < stRank; k++)
	{	// ȫѡ��Ԫ
		double MaxValue(0);
		for(size_t i = k; i < stRank; i ++)
		{
			for(size_t j = k; j < stRank; j ++)
			{
				double tmp(Abs(m(i, j)));	//��m(i,j)����ֵ
				if(tmp > MaxValue)				//��Ԫ���ڶԽ�����
				{
					MaxValue = tmp;
					is[k] = i;					//��¼��Ԫ����
					js[k] = j;					//��¼��Ԫ����
				}
			}
		}

		if(FloatEqual(MaxValue, 0)) 
			return int(0);						//��ԪΪ0����������

		if(is[k] != k)							//��Ԫ���ڵ�ǰ��
		{
			for(size_t j = 0; j < stRank; j ++)	//������Ԫ��
				swap(m(k, j), m(is[k], j));
		}

		if(js[k] != k)							//��Ԫ���ڵ�ǰ��
		{
			for(size_t i = 0; i < stRank; i ++)	//������Ԫ��
				swap(m(i, k), m(i, js[k]));
		}

		m(k, k) = 1.0 / m(k, k);				//��Ԫ����
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
	int iSym = MatrixSymmetryRegular(rhs, 1);	//�б��Ƿ�Գ�����
	if(iSym < 2)
		return (iSym);			//rhs���ǶԳ�������

	size_t stRank = rhs.n();	// �������

	matrix<_Ty> msr(rhs);			//����һmatrix������rhs��ʼ��

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
