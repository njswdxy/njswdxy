#include"header.h"


int main(int argc, char ** argv){
//const char * SFile, const char * DFile, int pos, int blocksize
	int pos = atoi(argv[3]);
	int blocksize = atoi(argv[4]);

	int sfd = open(argv[1], O_RDONLY);
	int dfd = open(argv[2], O_WRONLY | O_CREAT, 0664);

	lseek(sfd, pos, SEEK_SET);
	lseek(dfd, pos, SEEK_SET);

	char buffer[blocksize];
	bzero(buffer, sizeof(buffer));

	int size = read(sfd, buffer, sizeof(buffer));
	write(dfd, buffer, size);
	printf("Copy success\n");

	return 0;
}
