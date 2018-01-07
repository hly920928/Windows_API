#include "Everything.h"
#include "myHeader.h"
#include <iostream>
int main(int argc, char* argv[]) {
	char pwdBuffer[999];
	DWORD lenCurDir;
	lenCurDir=GetCurrentDirectory(999,pwdBuffer);
    PrintMsg(GetStdHandle(STD_OUTPUT_HANDLE),pwdBuffer);
	return 0;
}


