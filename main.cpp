#include "Everything.h"
#include "myHeader.h"
#include <iostream>
struct myStru{
	DWORD a;
	DWORD b;
	DWORD c;
};
int main(int argc, char* argv[]) {
   char Flag=' ';
 
   HANDLE hFile;
   LARGE_INTEGER curPtr;
   DWORD openOption,nXfer,recNo;
   _RECORD record;
     /*
   CHAR string[STRING_SIZE],command,extra;
   OVERLAPPED ov={0,0,0,0,NULL},ovZero={0,0,0,0,NULL};
   _HEADER header={0,0};
   SYSTEMTIME currentTime;
   BOOLEAN headerChange,recordChange;
    //printf("argc = %d\n",argc);
   printf("Please InPut File Name\n");
   */
   CHAR FileName[STRING_SIZE]="E:\\MFC_TEST\\GCC\\Windows_API\\sub\\123456.txt\0";

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
       DWORD temp=777;
       WriteFile(hFile,&temp,sizeof(temp),&nXfer,NULL);
       //curPtr.QuadPart=(LONGLONG)sizeof(header);
       //SetFilePointerEx(hFile,curPtr,NULL,FILE_BEGIN);
       temp=669999;
       WriteFile(hFile,&temp,sizeof(temp),&nXfer,NULL);
       temp=78775;
       WriteFile(hFile,&temp,sizeof(temp),&nXfer,NULL);
       myStru st={4,5,6};
       WriteFile(hFile,&st,sizeof(st),&nXfer,NULL);
       SetEndOfFile(hFile);
        printf("Create File OK\n");
        return 0;
   }
   ////
   std::cout<<"Open "<<FileName<<std::endl;
   //SetFilePointerEx(hFile,(LARGE_INTEGER)curPtr,NULL,FILE_BEGIN);
   //curPtr.QuadPart=(LONGLONG)sizeof(header);
   //SetFilePointerEx(hFile,curPtr,NULL,FILE_BEGIN);
   char str[999];
   ReadFile(hFile,str,9,&nXfer,NULL);
   printf("test1 %s\n",str);
   ReadFile(hFile,str,9,&nXfer,NULL);
   printf("test2 %s\n",str);
  /*
   curPtr.QuadPart=(LONGLONG)0;
   SetFilePointerEx(hFile,curPtr,NULL,FILE_BEGIN);
   ReadFile(hFile,&temp,sizeof(temp),&nXfer,NULL);
   printf("test3 %d\n",temp);
   myStru st;
   curPtr.QuadPart=-1*(LONGLONG)sizeof(st);
   SetFilePointerEx(hFile,curPtr,NULL,FILE_END);
   ReadFile(hFile,&st,sizeof(st),&nXfer,NULL);
   printf("test4 %d %d %d\n",st.a,st.b,st.c);;
  *
  /
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


