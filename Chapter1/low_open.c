#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error_handling(char* message);

int main(void)
{
	int fd1, fd2;
	char buf[]="Let's go!\n";
	
	fd1=open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);
	if(fd1==-1)
		error_handling("open() error!");

	fd2=open("data2.txt", O_CREAT|O_WRONLY|O_TRUNC);
	if(fd2==-1)
		error_handling("open() error!");

	printf("file descriptor1: %d \n", fd1);
	printf("file descriptor2: %d \n", fd2);

	if(write(fd1, buf, sizeof(buf))==-1)
		error_handling("write() error!");

	if(write(fd2, buf, sizeof(buf))==-1)
		error_handling("write() error!");

	if(write(1, buf, sizeof(buf))==-1)
		error_handling("write() error!");

	close(fd1);
	close(fd2);
	
	return 0;
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

/*
root@com:/home/swyoon/tcpip# gcc low_open.c -o lopen
root@com:/home/swyoon/tcpip# ./lopen
file descriptor: 3 
root@com:/home/swyoon/tcpip# cat data.txt
Let's go!
root@com:/home/swyoon/tcpip# 
*/
