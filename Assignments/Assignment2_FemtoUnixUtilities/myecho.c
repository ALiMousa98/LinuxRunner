#include<stdio.h>

#define RET 0

int main(int argc, char **argv)
{
    if(argc==1)
	   printf("Too few Args fro myecho program \n"); 
    else
    {
	    int i=1;

	    for(;i<argc;i++)
		    printf("%s ",argv[i]);
	   
	    printf("\n");
    }



    return RET;
}
