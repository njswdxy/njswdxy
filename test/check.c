#include"header.h"

int check(const char * SFile, int arg_num, int pro_num){

	if(access(SFile, F_OK) != 0){
		printf("sfile is not exit\n");
		exit(-1);
	}

	if(pro_num < 0 || pro_num > 100){
		printf("the pronum should > 0 and < 100");
		exit(-1);
	}

	return  0;
}
