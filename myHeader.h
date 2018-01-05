#include "Everything.h"
#define BUF_SIZE 0x200
extern "C"
void myReportError(LPCTSTR userMessage,DWORD exitCode,
                BOOL printErrorMessage);
void CatFile(HANDLE,HANDLE);
