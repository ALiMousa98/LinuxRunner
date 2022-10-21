#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/utsname.h>


#define RET 0
#define BUILTIN_SET 2
#define BUILTIN_EXPORT 3
#define BUILTIN_HIST 4
#define EXIT 5
#define ASSIGN_LOCALVAR 1

/*
 * Global Vars
*/

char line[100];
char cmd[50];
char *params[50]={NULL};
char *hist[500];
char  localVar[100];
char  *localValues[100];
char  *localVars[100];
char myenv[100];

int histCount=0;
int localCount=0;


void print_prompt(void)
{
	struct utsname buf;
	uname(&buf);
	char buf2[200];
        getcwd(buf2, sizeof(buf2));

	printf("%s@%s:%s$ ",getenv("USER"),buf.nodename,buf2);

}

char* get_line(void)
{
 
  fgets(line,100,stdin);
  line[strcspn(line,"\n")]=0;

  return line;
}

char * removeSpaces(char *str)
{
    // non_space_count to keep the frequency of non space characters
    int non_space_count = 0;
 
    //Traverse a string and if it is non space character then, place it at index non_space_count
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[non_space_count] = str[i];
            non_space_count++;//non_space_count incremented
        }    
    }
    
    //Finally placing final character at the string end
    str[non_space_count] = '\0';
    return str;
}

void add_history(char*_hist)
{


        if(histCount>499)
                printf("History is full! free some\n");
        else
        {
                hist[histCount]=_hist;
                histCount++;
        }


}


int parser(char* _cmd)
{

    char *temp[50];
    int i = 0;
   
    add_history(_cmd);
     
    char *token = strtok (_cmd, " ");
    
    while (token != NULL)
         {
             temp[i++] = token;
             token = strtok (NULL, " ");
	    
	    
         }
 
   
  
    
    if(strcmp(_cmd,"set")==0)
	    return BUILTIN_SET;
    else if (strcmp(_cmd,"export")==0)
    {
	   strcpy(myenv,temp[1]);
	   //printf("myenv: %s\n",myenv); 
	   return BUILTIN_EXPORT;
    }
    else if (strcmp(_cmd,"history")==0)
            return BUILTIN_HIST;
    else if (strcmp(_cmd,"exit")==0)
            return EXIT;

    
   if(i>1)
   {
	  
	  if(strcmp(temp[1],"=")==0)
	  {
      		localVars[localCount]=temp[0];
        	localValues[localCount]=temp[2];

       		localCount++;
     		 return ASSIGN_LOCALVAR;

   	 }
	  else
		{
		
                strcpy(cmd,temp[0]);

                for(int j=0; j<i;j++)
                    params[j]=temp[j];
                params[i]=NULL;
			return RET;
		}

   }

       
	  else
	  {    
		 
   		strcpy(cmd,temp[0]);
       
       	 	for(int j=0; j<i;j++)
                    params[j]=temp[j];
        	params[i]=NULL;
		return RET;
	  }
        

   
}


void show_localVars(void)
{
	if(localCount==0)
		printf("No Local Variables have been added yet! \n");
	else
	{
		for(int i=0; i<localCount;i++)
			printf("Local var[%d] : %s = %s \n",i,localVars[i],localValues[i]);
	}
}

void show_history(void)
{
	for(int i=0; i<histCount; i++)
		printf("%s\n",hist[i]);
}

void set_env(void)
{

	int s=0,temp;
	for(int i = 0; i<localCount;i++)
	{
		temp=i;
		if(strcmp(myenv,localVars[i])==0)
		{
			s++;
			break;
		}

	}
	if (s==0)
		printf("Couldn't find local var %s\n",myenv);
	else
		setenv(myenv, localValues[temp],1);
		

	
}


int main(int argc, char** argv)
{
      int status;
      char myline[100];
      int ch;
      while(1)
      {
	
	print_prompt();
        get_line();
        strcpy(myline,line);
        
	if(strcmp(myline,"\0")==0)
		continue;
      
	ch=parser(myline);

        if(ch==EXIT)
		exit(0);
	if(ch==BUILTIN_SET)
		show_localVars();

	else if(ch==BUILTIN_EXPORT)
                set_env();
	else if(ch==BUILTIN_HIST)
                show_history();
	else if(ch==ASSIGN_LOCALVAR)
		continue;
        else if(ch==RET)
	{	
		int ret_pid=fork();

		if (ret_pid<0)
			printf("Fork Faild \n");
		else if (ret_pid > 0)
			wait(&status);
		else
		{
		        execvp(cmd,params);
			printf("exec Faild \n");
		}

	}



      } // While(1)

	return RET;
}

