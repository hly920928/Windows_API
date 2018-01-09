#include "Everything.h"
#include "myHeader.h"
#include <iostream>

int main(int argc, char* argv[]) {
    LPCTSTR filename="123456.txt";
    LPCTSTR Dirname="*";
    BOOL flag[10];flag[0]=1;
    TraverseDirectory(filename,Dirname,666,flag);
    return 0;
}


