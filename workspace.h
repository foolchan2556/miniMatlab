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
        int add(const string & iname, Item * pItem);// ��ָ��Item��ָ��pItem������iname���빤���ռ� ��ʧ���򷵻�-1
        Item * get(const string & iname); // ����ָ������Ϊiname��Item��ָ�� ��ʧ���򷵻�NULL
};
#endif
