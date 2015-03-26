#include "ftable.h"

#include <iostream>

using namespace std;


_Myt * Ftable::eval(const string & fname,_Myt params[], const int nparam)
{
        for(int i=0; i<nparam; ++i)
                if (!params[i].isValid) {
                        _Myt * resMat = new _Myt(1, 1);
                        resMat->isValid = false;
                        return resMat;
                }

        if (fname == "row" && nparam == 2)//è¿åæå®è¡?
        {
                if(params[1].m()==1&&params[1].n()==1)
                {
                        _Myt * resMat = new _Myt(params[0].row((int)params[1].getElem(0,0) - 1),params[0].n(),1);
                        return resMat;
                }
        }
        else if (fname == "col" && nparam == 2)//è¿åæå®å?
        {
                if(params[1].n()==1&&params[1].m()==1)
                {
                        _Myt * resMat = new _Myt(params[0].col((int)params[1].getElem(0,0) - 1),params[0].m(),1);
                        return resMat;
                }
        }
        else if (fname == "ran" && nparam == 1)//è¿åç§?
        {
                double dm[1][1] = {{MatrixRank(params[0])}};
                _Myt * resMat = new _Myt(&dm[0][0],1,1);
                return resMat;
        }
        else if (fname == "inv" && nparam == 1)//è¿åéç©é?
        {
                _Myt * resMat = new _Myt(params[0]);
                MatrixInversionGS(*resMat);
                return resMat;
        }
        else if (fname == "tra" && nparam == 1)//è¿åè½¬ç½®ç©éµ
        {
                _Myt * resMat = new _Myt(params[0].n(),params[0].m());
                MatrixTranspose(params[0],*resMat);
                return resMat;
        }
        else if (fname == "det" && nparam == 1)//è¿åè¡åå¼?
        {
                double dm[1][1] = {{(double)MatrixDeterminant(params[0])}};
                _Myt * resMat = new _Myt(&dm[0][0],1,1);
                return resMat;
        }
        else if (fname == "sin" && nparam == 1)//æ­£å¼¦å½æ°
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,sin(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "cos" && nparam == 1)//ä½å¼¦å½æ°
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,cos(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "tan" && nparam == 1)//æ­£åå½æ°
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,tan(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "asi" && nparam == 1)//åæ­£å¼¦å½æ?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,asin(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "aco" && nparam == 1)//åä½å¼¦å½æ?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,acos(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "ata" && nparam == 1)//åæ­£åå½æ°ï¼ä¸»å¼ï¼
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,atan(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "sih" && nparam == 1)//åæ²æ­£å¼¦å½æ°
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,sinh(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "coh" && nparam == 1)//åæ²ä½å¼¦å½æ°
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,cosh(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "tah" && nparam == 1)//åæ²æ­£åå½æ°
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,tanh(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "pow" && nparam == 2)//ææ°å½æ°
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,pow(resMat->getElem(i,j),params[1].getElem(0,0)));
                return resMat;
        }
        else if (fname == "ln" && nparam == 1)//å¯¹æ°å½æ°ï¼eä¸ºåºï¼?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,log(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "lg" && nparam == 1)//å¯¹ä¹¦å½æ°ï¼?0ä¸ºåºï¼?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,log10(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "abs" && nparam == 1)//ç»å¯¹å?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,abs(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "fab" && nparam == 1)//æµ®ç¹åç»å¯¹å?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,fabs(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "lab" && nparam == 1)//é¿æ´åç»å¯¹å?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,labs(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "exp" && nparam == 1)//ææ°å½æ°ï¼eä¸ºåºï¼?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,exp(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "cei" && nparam == 1)//åä¸æ?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,ceil(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "flr" && nparam == 1)//åä¸æ?
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,floor(resMat->getElem(i,j)));
                return resMat;
        }
        else if (fname == "add" && nparam == 2)//æåç´ å
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,resMat->getElem(i,j)+params[1].getElem(0,0));
                return resMat;
        }
        else if (fname == "sub" && nparam == 2)//æåç´ å
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,resMat->getElem(i,j)-params[1].getElem(0,0));
                return resMat;
        }
        else if (fname == "mul" && nparam == 2)//æåç´ ä¹
        {
                _Myt * resMat = new _Myt(params[0]);
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,resMat->getElem(i,j)*params[1].getElem(0,0));
                return resMat;
        }
        else if (fname == "div" && nparam == 2)//æåç´ é¤
        {
                _Myt * resMat = new _Myt(params[0]);
                if (params[1].getElem(0,0) == 0) {
                        resMat->isValid = false;
                        return resMat;
                }
                for(int i = 0;i < resMat->n();i++)
                        for(int j = 0;j < resMat->m();j++)
                                resMat->setElem(i,j,resMat->getElem(i,j)/params[1].getElem(0,0));
                return resMat;
        }
        else {
                        _Myt * resMat = new _Myt(1, 1);
                        resMat->isValid = false;
                        return resMat;
        }
}

