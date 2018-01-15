#include "Everything.h"
#include "myHeader.h"
#include <iostream>
#include <float.h>


int main(int argc, char* argv[]) {
	//open float Point exception control
	DWORD fpOld,fpNew;
	fpOld=_controlfp(0,0);
    fpNew=fpOld&~(_EM_INVALID|_EM_DENORMAL
              |_EM_ZERODIVIDE|_EM_OVERFLOW
              |_EM_UNDERFLOW|_EM_INEXACT);
    _controlfp(fpNew,_MCW_EM);
    //test exception is thrown
    double a=0;
    double b=1;
    double c=b/a;
    return 0;
}


