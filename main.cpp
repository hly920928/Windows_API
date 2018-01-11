#include "Everything.h"
#include "myHeader.h"
#include <iostream>

int main(int argc, char* argv[]) {
    FILETIME newFileTime;
	LPFILETIME pAccessTime = NULL, pModifyTime = NULL;
    HANDLE hFile;
    const char fileName[]="123456.txt\0";
    hFile = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, 0, NULL,
				OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    GetSystemTimeAsFileTime(&newFileTime);
    pAccessTime = &newFileTime;
    pModifyTime = &newFileTime;
    SetFileTime(hFile, NULL, pAccessTime, pModifyTime);
    CloseHandle(hFile);
    return 0;
}


