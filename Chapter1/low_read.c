#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 100

void error_handling(char* message);

int main(void)
{
	int fd;
	char buf[BUF_SIZE];
	
	fd=open("data.txt", O_RDWR);
	if( fd==-1)
		error_handling("open() error!");
	
	printf("file descriptor: %d \n" , fd);
	
	if(read(0, buf, sizeof(buf))==-1)
		error_handling("read() error!");

	if(write(fd, buf, sizeof(buf))==-1)
		error_handling("write() error!");

	printf("file data: %s", buf);
	
	close(fd);
	return 0;
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

/*
root@com:/home/swyoon/tcpip# gcc low_read.c -o lread
root@com:/home/swyoon/tcpip# ./lread
file descriptor: 3 
file data: Let's go!
root@com:/home/swyoon/tcpip# 
*/
