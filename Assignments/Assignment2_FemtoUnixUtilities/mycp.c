#include<stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RET 0

int main(int argc, char * argv[])
{
	char buf[100];
       	int count;
	
	if(argc > 3)
	{	
		printf("Too Many Args for mycp program \n");
		return -1;
	}
	else if(argc<3)
	{
                printf("Too Few Args for mycp program \n");
                return -1;
        }
	else
	{

		int fd1=open(argv[1],O_RDONLY);
        int fd2=open(argv[2],O_WRONLY|O_CREAT,0644);

        count=read(fd1,buf,100);
        while(count!=0)
        {
                write(fd2,buf,count);
                count=read(fd1,buf,100);
        }

        close(fd1);
        close(fd2);

	}

	
	return RET;
}
