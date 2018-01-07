#include "Everything.h"
#include "myHeader.h"
#include <iostream>
int main(int argc, char* argv[]) {
   HANDLE hIn,hOut;
   DWORD count;
   hIn=CreateFile(_T("CONIN$"),
   GENERIC_READ|GENERIC_WRITE,0,
   NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
   hOut=CreateFile(_T("CONOUT$"),
   GENERIC_WRITE,0,
   NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
   char pBuffer[999];
   const char str[]="Please InPut\n";
   WriteConsole(hOut,str,strlen(str),&count,NULL);
   while(true){
   	ReadConsole(hIn,pBuffer,999,&count,NULL);
   	pBuffer[count-2]='\n';pBuffer[count-1]='\0';
   	if(pBuffer[0]=='0')break;
   	WriteConsole(hOut,pBuffer,count-1,&count,NULL);
   }
   const char end[]="Echo End\n";
   WriteConsole(hOut,end,strlen(end),&count,NULL);
    return 0;
}


