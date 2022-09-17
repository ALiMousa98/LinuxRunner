#include<stdio.h>
#include <string.h>


int main()
{

	char str[100];

	while(1){


	fgets(str,100,stdin);
	str[strcspn(str,"\n")]=0;
	if(!strcmp(str,"exit"))
	{
	    printf("Good Bye!\n");
	    break;
	}
	printf("You said: %s\n ",str);
    }
	return 0;
}
