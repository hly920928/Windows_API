#include "Everything.h"
#include "myHeader.h"
#include <iostream>
int main(int argc, char* argv[]) {
   char Flag=' ';
   HANDLE hFile;
   DWORD curPtr;
   DWORD openOption,nXfer,recNo;
   _RECORD record;
   CHAR string[STRING_SIZE],command,extra;
   OVERLAPPED ov={0,0,0,0,NULL},ovZero={0,0,0,0,NULL};
   _HEADER header={0,0};
   SYSTEMTIME currentTime;
   BOOLEAN headerChange,recordChange;
    //printf("argc = %d\n",argc);
   printf("Please InPut File Name\n");
   CHAR FileName[STRING_SIZE];
   scanf("%s",FileName);
   //printf("%s\n",FileName);
   printf("Create New File Y:N \n");
   std::cin>>Flag;
   //std::cout<<Flag<<std::endl;
   openOption=(Flag=='N')?
               OPEN_EXISTING:CREATE_ALWAYS;
   hFile=CreateFile(FileName,
   GENERIC_READ|GENERIC_WRITE,0,
   NULL,openOption,FILE_FLAG_RANDOM_ACCESS,NULL);
   //create new File
   if(Flag=='Y'){
       header.numRecords=777;
       WriteFile(hFile,&header,sizeof(header),&nXfer,&ovZero);
       record.referenceCount=333;
       WriteFile(hFile,&record,sizeof(record),&nXfer,&ovZero);
       //SetEndOfFile(hFile);
        printf("Create File OK\n");
        return 0;
   }
   ////
   std::cout<<"Open "<<FileName<<std::endl;
   //SetFilePointerEx(hFile,(LARGE_INTEGER)curPtr,NULL,FILE_BEGIN);
   ReadFile(hFile,&header,sizeof(header),&nXfer,NULL);
   std::cout<<"header.numRecords "<<header.numRecords<<std::endl;
   ReadFile(hFile,&record,sizeof(record),&nXfer,NULL);
   std::cout<<"record.referenceCount "<<record.referenceCount<<std::endl;
   /*
   
   HANDLE hIn,hOut;
   DWORD count;
   hIn=CreateFile(_T("CONIN$"),
   GENERIC_READ|GENERIC_WRITE,0,
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
   */
    return 0;
}


