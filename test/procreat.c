#include"header.h"


int procreat(const char * SFile, const char * DFile, int pro_num, int blocksize){

	int flag;
	pid_t pid;
	for(flag = 0; flag < pro_num; flag ++){
		pid = fork();
		if(pid == 0) break;
	}

	if(pid > 0){
		printf("parent process pit[%d] 非阻塞回收子進程\n", getpid());
		pid_t zpid;
		while((zpid = waitpid(-1, NULL, WNOHANG)) != -1){
			if(zpid > 0){
				printf("parent process pid[%d] success wait child process\n", zpid);
			}
		}
	}else if(pid == 0){
		printf("child process work\n");
		int pos = flag * blocksize;

		char cpos[10];
		char cblock[10];
		bzero(cpos, sizeof(cpos));
		bzero(cblock, sizeof(cblock));

		sprintf(cpos, "%d", pos);
		sprintf(cblock, "%d", blocksize);

		execl("/home/colin/study/test/Copy", "./Copy", SFile, DFile, cpos, cblock, NULL);

	}else{
		perror("fork call failed\n");
		exit(-1);
	}

	return 0;
}
