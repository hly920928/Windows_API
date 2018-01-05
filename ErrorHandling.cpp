#include "myHeader.h" 

void myReportError(LPCTSTR userMessage,DWORD exitCode,
                BOOL printErrorMessage){
                    DWORD eMegLen,errNum=GetLastError();
                    LPTSTR lpvSysMsg;
                    _ftprintf(stderr,_T("%s\n"),userMessage);
                    if(printErrorMessage){
                        eMegLen=FormatMessage(
                            FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
                            NULL,errNum,
                            MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),
                            (LPTSTR)&lpvSysMsg,0,NULL);
                      if(eMegLen>0){
                          _ftprintf(stderr,"%s\n",lpvSysMsg);
                      }else{
                          _ftprintf(stderr,_T("Last Error Number;%d.\n"),errNum);
                      }
                      if(lpvSysMsg!=NULL)LocalFree(lpvSysMsg);
                    }
                       if(exitCode>0)ExitProcess(exitCode);
                    }


