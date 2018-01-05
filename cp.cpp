#include "Everything.h"
#include "myHeader.h"
#include <iostream>
int main(int argc, char* argv[]) {
	printf("in cp\n");
	
	//printf("%s\n",argv[0]);
	int len=atoi(argv[1]);
	//printf("%d\n",len);
	//printf("%s\n",argv[2]);
	HANDLE hInFile,hStdIn=GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	BOOL dashS;
	int iArg,iFirstFile;
	 iFirstFile=-1;
	if(len==0)iFirstFile=0;
	
	if(iFirstFile==0){
		printf("hStdin To hStdOut\n");
		//CatFile(hStdin,hStdOut);
		return 0;
	}
	for(iArg=2;iArg<len+2;iArg++){
		hInFile=CreateFile(
			argv[iArg],GENERIC_READ,0,
			NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
			if(hInFile!=INVALID_HANDLE_VALUE){
				CatFile(hInFile,hStdOut);
			}
		
	}
	return 0;
}


