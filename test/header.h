#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>

int check(const char * SFile, int arg_num, int pro_num);
int block(const char * SFile, int pro_num);
int procreat(const char * SFile, const char * DFile, int pro_num, int blocksize);
