#include<stdio.h>
#include <unistd.h>


#define RET 0

int main(void)
{

    char buf[100];
    getcwd(buf, sizeof(buf));

    printf("%s\n", buf);


    return RET;
}
