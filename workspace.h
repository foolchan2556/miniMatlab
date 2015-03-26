#ifndef _WORKSPACE_H
#define _WORKSPACE_H
#include "item.h"
#include <map> 
#include <string>

using namespace std;

class Item;
class Workspace
{
private:
        map<string, Item *> mapVar;
public:
        Workspace();
        ~Workspace();
        int add(const string & iname, Item * pItem);// 将指向Item的指针pItem以名字iname挂入工作空间 若失败则返回-1
        Item * get(const string & iname); // 返回指向名字为iname的Item的指针 若失败则返回NULL
};
#endif
