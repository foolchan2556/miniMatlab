#include "workspace.h"

using namespace std;
/*
class Variable
{
private:
        string vName;
        Item* pItem;
};
*/
class Item;



Workspace::Workspace()
{
}

Workspace::~Workspace()
{
        for(map<string, Item *>::iterator it = mapVar.begin(); it!=mapVar.end(); it++)
        {
                delete it->second;
        }
}

/////////////////////////////////////////////////////////////////
//	function: Workspace::get
//	summary:
// 		·µ»ØÖ¸ÏòÃû×ÖÎªinameµÄItemµÄÖ¸Õë ÈôÊ§°ÜÔò·µ»ØNULL
//	assumption:
//		1.iname ·Ç¿Õ£¨ÔÚcallItem 1ÏÂ³ÉÁ¢, ÓÉcheckValidName ±£Ö¤£©
//
//template <class _Ty>
Item * Workspace::get(const string & iname)
{
        map<string, Item*>::iterator it;
        it = mapVar.find(iname);
        if(it == mapVar.end())
                return NULL;
        else
                return it->second;
}
////////////////////////////////////////////////////////////////
// function: Workspace::add
// summary:
//		½«Ö¸ÏòItemµÄÖ¸ÕëpItemÒÔÃû×Öiname¹ÒÈë¹¤×÷¿Õ¼ä ÈôÊ§°ÜÔò·µ»Ø-1
// 		Éè¶¨½á¹û½ÓÊÜ±äÁ¿£¬Èç¹û²ÎÊýÃû¶ÔÓ¦±äÁ¿ÊÇ£º
//		1.ÐÂ±äÁ¿£ºÉùÃ÷
//		2.ÀÏ±äÁ¿£ºÖ¸Ïò
//		3.¿Õ´®£ºÖ¸Ïòans
// assumption:
// 		1.iname ºÏ·¨£¨ÔÚcallItem 1ÏÂ³ÉÁ¢, ÓÉcheckValidName ±£Ö¤£©
//		2.iname ²»ÔÚµ±Ç°mapÖÐ£¨µ÷ÓÃÌõ¼þÊÇget·µ»ØNULL£©
//
//template <class _Ty>
int Workspace::add(const string & iname, Item * pItem)
{
        mapVar[iname] = pItem;
        return 1;
}
