#include<stdio.h>
 

#define RET 0

int main(int argc, char **argv)
{
    if(argc>3)
    {
	   printf("Too Many Args for cut program \n");
	   return -1;
    }

    if(argc<3)
    {
           printf("Too Few Args for cut program \n");
	   return -1;
    }   
    else
    {
	    int check=rename(argv[1],argv[2]);
	    if (check==-1)
	    {
		    printf("Syntax Error \n");
		    printf("Please Enter a vaild [Source file] and [Destination directory]  \n");

		    return -1;
	    }
	    else
	    {
		    remove(argv[1]);
	    }
    }



    return RET;
}
