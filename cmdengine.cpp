#include "cmdengine.h"

#include <iostream>
#include "item.h"
#include "plotter.h"

#define MAX_EXPR_LENGTH 100

const int ILLEGAL_EXPR = -1;
const int ILLEGAL_NAME = -2;
const int ERROR_ADD = -3;
const int ERROR_EVAL = -4;
Workspace wksp;
//Plotter plotter;
//const Item* P_ANS = wksp.get("ans");
// È¥µô¿ªÍ·µÄ=»¹ÊÇ±¨´í£¿
/*const string readexpr()
{
        string expr;
        getline(cin, expr);
        return expr;
}*/
int checkValidName(const string & vName)
{
        return 1;
}
//	variable declaration needed
void uniform(string & expr)	//	space, paraphase,
{

}
//////////////////////////////////////////////////////////////
// function: callItem
// 		¼ì²éÊÇ·ñÊÇ¸³ÖµÓï¾ä¡£Èç¹ûÊÇ£º
// 		1.¸üÐÂ±í´ïÊ½Îª²»´ø¸³ÖµµÄ½á¹û±í´ïÊ½
//		2.Èç¹ûÎÞ¸³Öµ£¬½«½á¹û±£´æÓÚans
//		3.ÔÚ·µ»Ø½á¹ûÖ®ºó¶¨Òå±äÁ¿
// assumption:
// 		1.²ÎÊý±í´ïÊ½ºÏ·¨£¨Ä¿Ç°ÒªÇóÎª¿ªÍ·²»ÊÇ=£»Ä¿Ç°Ã»ÓÐÒªÇóËã·ûÖ®¼äÎÞ¿Õ¸ñ£¬¼ÙÉèÔÚ
// 		Item::eval ÖÐÖ´ÐÐ¸Ã²Ù×÷£©
//
string callItem(string & expr)
{
        string::size_type p;
        p = expr.find("plot", 0);
        if(p != string::npos)
        {
                return "Plotter Called\n";
        }
        string vName = "ans";
        Item* pItem;
        Item* P_ANS;
        int report = 0;
        string str = "";
        p = expr.find('=', 0);	//	NULL at the end if use const string
        if(p != string::npos && expr[p-1] != '=' && expr[p-1] != '!')
        {
                vName.assign(expr, 0, p);		// get the name of the variable
                expr.erase(0, p+1);				// update the expression into normal form
                report = checkValidName(vName);
                if(report == ILLEGAL_NAME)		// if the name is illegal, return -2.
                        return "Illegal Name/n";
                //	another solution: report variable illegal and take the expression as
                // 	a normal expression with no assignment ahead.
                //	vName = "ans";
        }
        str.append(vName);
        str+=" = ";
        str.append("\n");
        if( NULL == ( pItem = wksp.get(vName) ) )	// get the pointer to the variable's item
        {
                pItem = new Item(&wksp);
                if(wksp.add(vName, pItem) == -1)	// Workspace::add return -1 if error accures
                {
                        report = ERROR_ADD;
                        return "Error in Adding Variables\n";
                }
        }
        if(pItem->eval(expr) == -1)	// item.eval
        {
                report = ERROR_EVAL;
                return "Error Evalling\n";
        }
        else
        {
                str += pItem->value().disp();
                if( NULL != (P_ANS = wksp.get("ans")))
                {
                        P_ANS->eval(expr);
                }
        }
        return str;
}
//	variable assignment needed, think how to relate the workspace var and item.
//////////////////////////////////////////////////////
//	function: callPlotter
//	summary:
//		¶Ô±í´ïÊ½µÄ´¦ÀíÓëÆäËûº¯ÊýÏàÍ¬¡£Ó¦¸Ã´«µÝ¸øplotterÁ½¸öItemÖ¸Õë

string callPlotter(string & expr)	//	execute the postfix expression
{
        string::size_type pos;
        pos = expr.find("plot", 0);
        string info = "";
        if(pos != string::npos)
        {
                for(; expr[pos] != '('; pos++)
                        ;
                pos++;
                string::size_type end;
                end = expr.find("@", pos);
                if(end == string::npos)
                {
                        return info = "Plotter: Syntax Error\n";
                }
                string expr1(expr, pos, end-pos);
                pos = end+1;
                end = expr.find("@", pos);
                if(end == string::npos)
                {
                        return info = "Plotter: Syntax Error\n";
                }
                string expr2(expr, pos, end-pos);
                pos = end+1;
                end = expr.find(")", pos);
                if(end == string::npos)
                {
                        return info = "Plotter: Syntax Error\n";
                }
                string expr3(expr, pos, end-pos);
                Item item(&wksp);
                if(item.eval(expr1) == -1)
                {
                        return info = "Syntax Error in double* x\n";
                }
                double* arg1 = item.value().row(0);
                if( arg1 == NULL )
                {
                        return info = "Cannot ge the value of the first argument\n";
                }
                if(item.eval(expr2) == -1)
                {
                        return info = "Syntax Error in double* y\n";
                }
                double* arg2 = item.value().row(0);
                if( arg2 == NULL )
                {
                        return info = "Cannot ge the value of the second argument\n";
                }
                if(item.eval(expr3) == -1)
                {
                        return info = "Syntax Error in int size\n";
                }
                int arg3 = item.value().getElem(0,0);
                if( arg3 == NULL )
                {
                        return info = "Cannot ge the value of the third argument\n";
                }
                Plotter plotter(arg1, arg2, arg3);	//debugging
                plotter.exec();
                string info = "Plot done\n";
        }
        return info;
}

const string process(const string & cmd)
{
        string expr(cmd);
        uniform(expr);
        callPlotter(expr);
        string str = callItem(expr);
//	const string result1(expr);	//debugging version 1
        return str;
}
/*int main()
{
        int line = 1;
        while(1)
        {
                cout << "minilab:" << line << ">" ;
                const string cmd = readexpr();
//		cout << cmd;	//	check if the expression is successfully read
                cout << process(cmd);	// check the value passing
                line ++;
        }
}*/
