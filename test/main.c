#include"header.h"

int main(int argc, char ** argv){

	if(argc < 3){
		printf("arg_num error");
		exit(-1);
	}
	int pro_num = atoi(argv[3]);
	if(pro_num == 0){
		pro_num = 5;
	}else{
		pro_num = atoi(argv[3]);
	}

	int blocksize;
	check(argv[1], argc, pro_num);
	blocksize = block(argv[1], pro_num);
	procreat(argv[1], argv[2], pro_num, blocksize);

	return 0;
}
