#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	char *addr1="127.212.124.78";	// 0x4E7CD47F(78.124.212.127), 네트워크 엔디언으로 출력
	char *addr2="127.212.124.255";

	unsigned long conv_addr=inet_addr(addr1);
	if(conv_addr==INADDR_NONE)
		printf("Error occured! \n");
	else
		printf("Network ordered integer addr: %#lx \n", conv_addr);
	
	conv_addr=inet_addr(addr2);
	if(conv_addr==INADDR_NONE)
		printf("Error occureded \n");
	else
		printf("Network ordered integer addr: %#lx \n\n", conv_addr);
	return 0;
}