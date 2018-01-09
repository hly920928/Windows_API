#include "Everything.h"
#include <stdarg.h>
#define BUF_SIZE 0x200
#define STRING_SIZE 200
#define MAX_OPTION 6666
extern "C"
struct _RECORD { 
		DWORD			referenceCount; 
		SYSTEMTIME		recordCreationTime;
		SYSTEMTIME		recordLastRefernceTime;
		SYSTEMTIME		recordUpdateTime;
		CHAR			dataString[STRING_SIZE];
	} ;
 struct _HEADER { /* File header descriptor */
		DWORD			numRecords;
		DWORD			numNonEmptyRecords;
	};
void myReportError(LPCTSTR userMessage,DWORD exitCode,
                BOOL printErrorMessage);
void CatFile(HANDLE,HANDLE);
BOOL cci_f(LPCTSTR fIn,LPCTSTR fOut,DWORD shift);
BOOL PrintStrings(HANDLE hOut,...);
BOOL PrintMsg(HANDLE hOut,LPCTSTR pMsg);
BOOL ConsolePrompt(LPCTSTR pPromptMsg,LPTSTR pResponse,DWORD maxChar,BOOL echo);
BOOL TraverseDirectory(LPCTSTR,LPCTSTR,DWORD,LPBOOL);
DWORD FileType(LPWIN32_FIND_DATA);
BOOL ProcessItem(LPWIN32_FIND_DATA,DWORD,LPBOOL);
