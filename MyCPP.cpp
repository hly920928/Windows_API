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
BOOL PrintStrings(HANDLE hOut,...){
    DWORD msgLen,count;
    LPCTSTR pMsg;
    va_list pMsgList;
    va_start(pMsgList,hOut);
    while((pMsg=va_arg(pMsgList,LPCTSTR))!=NULL){
        msgLen=strlen(pMsg);
        if(!WriteConsole(hOut,pMsg,msgLen,&count,NULL)){
             if(!WriteFile(hOut,pMsg,msgLen*sizeof(TCHAR),&count,NULL)){
                 va_end(pMsgList);return FALSE;
             }
        }
    }
     va_end(pMsgList);return TRUE;
}
BOOL PrintMsg(HANDLE hOut,LPCTSTR pMsg){
    return PrintStrings(hOut,pMsg,NULL);
}
BOOL ConsolePrompt(LPCTSTR pPromptMsg,LPTSTR pResponse,DWORD maxChar,BOOL echo){
   HANDLE hIn,hOut;
   DWORD charIn,echoFlag;
   BOOL success;
   hIn=CreateFile(_T("CONIN$"),
   GENERIC_READ|GENERIC_WRITE,0,
   NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
   hOut=CreateFile(_T("CONOUT$"),
   GENERIC_WRITE,0,
   NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
   echoFlag=echo?ENABLE_ECHO_INPUT:0;
   success=SetConsoleMode(hIn,
     ENABLE_LINE_INPUT|echoFlag|ENABLE_PROCESSED_INPUT)
       &&SetConsoleMode(hOut,
     ENABLE_WRAP_AT_EOL_OUTPUT|ENABLE_PROCESSED_INPUT)
     &&PrintStrings(hOut,pPromptMsg,NULL)
     &&ReadConsole(hIn,pResponse,maxChar-2,&charIn,NULL);
    if(success)
      pResponse[charIn-2]='\0';
      else myReportError("ConsolePrompt failure.",0,TRUE);
    CloseHandle(hIn);    CloseHandle(hOut);
    return success;
}
BOOL TraverseDirectory(LPCTSTR FileName,LPCTSTR DirName,DWORD numFlags,LPBOOL flags){
    HANDLE searchHandle;
    WIN32_FIND_DATA findData;
    BOOL recursive=flags[0];
    DWORD fType,iPass;
    CHAR currPath[MAX_PATH+1];
    GetCurrentDirectory(MAX_PATH,currPath);
    for(iPass=1;iPass<=2;iPass++){
        searchHandle=(iPass==1)?FindFirstFile(FileName,&findData):
        FindFirstFile(DirName,&findData);
        do{
            fType=FileType(&findData);
            if(iPass==1)
                ProcessItem(&findData,MAX_OPTION,flags);
            if(fType==TYPE_DIR&&iPass==2&&recursive){
                if(strcmp(findData.cFileName,".git")==0)continue;
                printf("Down To %s\n",findData.cFileName);
                SetCurrentDirectory(findData.cFileName);
                TraverseDirectory(FileName,DirName,numFlags,flags);
                SetCurrentDirectory("..");
            }
            }while(FindNextFile(searchHandle,&findData));
          FindClose(searchHandle);
    }
    return TRUE;
}
BOOL ProcessItem(LPWIN32_FIND_DATA pFileData, DWORD numFlags, LPBOOL flags){
    const char fileTypeChar[]={' ','d'};
    DWORD fType=FileType(pFileData);
    BOOL longList =flags[0];
   SYSTEMTIME lastWrite;
   if (fType != TYPE_FILE && fType != TYPE_DIR) return FALSE;
   CHAR currPath[MAX_PATH+1];
   GetCurrentDirectory(MAX_PATH,currPath);
   printf("currPath %s\n",currPath);
   if (longList) {
		printf("%c ", fileTypeChar[fType - 1]);
		printf("%d ", pFileData->nFileSizeLow);
		FileTimeToSystemTime(&(pFileData->ftLastWriteTime), &lastWrite);
		printf("%d/ %d/ %d %d: %d: %d",
				lastWrite.wMonth, lastWrite.wDay,
				lastWrite.wYear, lastWrite.wHour,
				lastWrite.wMinute, lastWrite.wSecond);
	}
    printf(" %s\n", pFileData->cFileName);
	return TRUE;
}
DWORD FileType(LPWIN32_FIND_DATA pFileData){
    BOOL isDir;
	DWORD fType;
	fType = TYPE_FILE;
	isDir =(pFileData->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
	if (isDir)
		if (strcmp(pFileData->cFileName, ".") == 0
				|| strcmp(pFileData->cFileName, "..") == 0)
			fType = TYPE_DOT;
		else fType = TYPE_DIR;
	return fType;
}
