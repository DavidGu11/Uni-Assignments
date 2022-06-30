// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "servers.h"


int main()
{
	int fd1;
	int fd2;
	char * myfifo = global_proc;
	char * WR = "./Cle/CO_WR";
	unsigned char str1[2048];
	unsigned char str2[2048] = {[2] = 'C',[3] = 'O',[258] = 'C',[259] = 'l',[260] = 'e'};
	unsigned char msg[2048] = {[0] = '1' - '0',[2] = 'H',[3] = 'E',[2] = 'L',[2] = 'L',[2] = 'O',[2] = 'Y',[2] = 'O',[2] = 'U'};
	// printf("%d",(int)msg[0]);
	fd1 = open(myfifo,O_WRONLY);
	write(fd1, str2, 2048);
	close(fd1);
	for(int i = 0; i < 2047;i++){
		str2[i] = '\0';
	}
	int testInteger;
	fd2=open(WR, O_WRONLY);
	write(fd2, msg, 2048);	
	// write(fd2, msg, 2048);
	// write(fd2, msg, 2048);

	
	// while(1){		
	// 	printf("Enter an integer: ");
	// 	scanf("%d", &testInteger);
	// 	if(testInteger == 1){
	// 		fd2=open(WR, O_WRONLY);
	//         int num = write(fd2, msg, 2048);	
	// 		printf("is %c\n",msg[2]);
	// 		close(fd2);
	// 	}	
	// }


	return 0;
}