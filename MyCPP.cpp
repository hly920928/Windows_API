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
void CatFile(HANDLE hInFile,HANDLE hOutFile){
    DWORD nIn,nOut;
    BYTE buffer[BUF_SIZE];
    while(ReadFile(hInFile,buffer,BUF_SIZE,&nIn,NULL)
    &&(nIn!=0)
    &&WriteFile(hOutFile,buffer,nIn,&nOut,NULL)
    );
    return;
}
BOOL cci_f(LPCTSTR fIn,LPCTSTR fOut,DWORD shift){
    HANDLE hIn,hOut;
    DWORD nIn,nOut,iCopy;
    CHAR aBuffer[BUF_SIZE],ccBuffer[BUF_SIZE];
    BOOL writeOK=true;
    hIn=CreateFile(fIn,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if(hIn==INVALID_HANDLE_VALUE)return false;
    hOut=CreateFile(fOut,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
    if(hOut==INVALID_HANDLE_VALUE)return false;
    while(ReadFile(hIn,aBuffer,BUF_SIZE,&nIn,NULL)
    &&nIn>0&&writeOK){
      for(iCopy=0;iCopy<nIn;iCopy++)
        ccBuffer[iCopy]=(aBuffer[iCopy]+shift)%256;
    writeOK=WriteFile(hOut,ccBuffer,nIn,&nOut,NULL);
    }
    CloseHandle(hIn);  CloseHandle(hOut);
    return writeOK;
}
