#ifndef _H_ITEM_
#define _H_ITEM_

#include <cctype>
#include <cstdio>
#include <vector>
#include <string>

#include "ftable.h"
#include "workspace.h"

using namespace std;

class Workspace;
/*
class Workspace{ // dummy
public:
		Item * get(const string & str){return NULL;}
};
*/
class Item
{
public:
	Item(Workspace * workspace = NULL);
	~Item();
	//int setFtable(Ftable * pFtable) // 将指向Ftable的指针pFtable挂载到Item类上 no longer used
	void setWorkspace(Workspace * workspace);
	int eval(const string & expr); // 存入表达式字符串expr，并计算得到matrix结果存在内部
                              // 若失败则返回-1 结果matrix的isValid为false	
	const string & expr(); // 返回存储的expr表达式字�?	
	const Matrix & value(); // 返回存储的计算结果（matrix�?private:
	//static Ftable * ftable;
	string exp;
	Workspace * worksp;
	Matrix * matrix;
	
	Matrix * evalExp(const string & str, int & pos);
	Matrix * evalTerm(const string & str, int & pos);
	Matrix * evalFactor(const string & str, int & pos);
	Matrix * evalMatrix(const string & str, int & pos);
};

#endif // _H_ITEM_
