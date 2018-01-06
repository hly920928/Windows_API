#include "Everything.h"
#include "myHeader.h"
#include <iostream>
int main(int argc, char* argv[]) {
	if(argv[1]==0){
		printf("In cci_f\n");
		return 0;
	}
	//printf("%s\n",argv[0]);
	cci_f(argv[1],argv[2],atoi(argv[3]));
	return 0;
}


