#include "Everything.h"
#include <stdarg.h>
#define BUF_SIZE 0x200
extern "C"
void myReportError(LPCTSTR userMessage,DWORD exitCode,
                BOOL printErrorMessage);
void CatFile(HANDLE,HANDLE);
BOOL cci_f(LPCTSTR fIn,LPCTSTR fOut,DWORD shift);
BOOL PrintStrings(HANDLE hOut,...);
BOOL PrintMsg(HANDLE hOut,LPCTSTR pMsg);
BOOL ConsolePrompt(LPCTSTR pPromptMsg,LPTSTR pResponse,DWORD maxChar,BOOL echo);
