#include"header.h"


int block(const char * SFile, int pro_num){
	
	int fd;
	fd = open(SFile, O_RDONLY);
	int blocksize = lseek(fd, 0, SEEK_END);
	if(blocksize % pro_num == 0)
		return blocksize / pro_num;
	else
		return blocksize / pro_num + 1;
}
