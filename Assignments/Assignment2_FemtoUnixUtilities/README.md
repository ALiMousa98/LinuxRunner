#Assignment2 Femto Unix Utilities. 

mycp:

It's a simple c program similer to cp in linux that take 2 Arguments and copy first one content into the second and keep the original one.

Syntax: 
 ./mycp Source Target
 
  e.g. ./mycp test_copy test_copy2

this program uses Libraries: 
	- stdio
	- unistd
	- sys/types
	- sys/stat
	- fcntl

This program handles cases like too many or few arguments, copy the whole content whatever its length.


![Output Example for mycp program](mycp_output.png)

mypwd: 

It's a simple C program similer to pwd command in linux take no options.

Syntax:
 ./mypwd

this program uses Libraries:
        - stdio
        - unistd

![Output Example for mypwd program](mypwd_output.png)


myecho: 

It's a simple C program similer to echo command

Syntax:
 ./myecho [Text]

this program uses Libraries:
        - stdio
![Output Example for myecho program](myecho_output.png)

cut:
It's a simple C program make cut/paste and renaming functionality.

Syntax:
 ./cut [Source] [Target]

this program uses Libraries:
        - stdio

This program handles cases like too many or few arguments, invaild path input.

![Output Example for cut program](cut_output.png)

