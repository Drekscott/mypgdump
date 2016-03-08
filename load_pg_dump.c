/*
Author: Dreyton Scott
Date: 02/15/16

Purpose: To load in a local pgdump. This takes in 2 arguments. First being the path to the pgdump.
The second being the path to the vagrantfile.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
void initcommands(char *, char *, char *, char *, char *, char*);
int main(int argc, char *argv[])
{
	char *cmd1,*cmd2,*cmd3,*cmd4,
	*cmd5,*cmd6,*pgdumppath,*pgdumpname,
	*vagrantfilepath;
	char *command = malloc(MAX);
	char *command2 = malloc(MAX);
	if (argc == 3)
		pgdumppath = argv[1];
		vagrantfilepath = argv[2];
	        strcpy(command, "scp -P 2222 ");
	pgdumpname = strrchr(pgdumppath, '/');
	cmd1 = "vagrant halt";
        cmd2 = "vagrant up";
        cmd3 = "vagrant ssh";
        cmd4 = "vagrant ssh vagrant --command dropdb vagrant";
        cmd5 = "vagrant ssh vagrant --command createdb vagrant";
        cmd6 = "~/";	 
        strcat(command, pgdumppath);
        strcat(command, " vagrant@localhost:/home/vagrant");
        chdir(vagrantfilepath);
	system(cmd1);
	system(cmd2);
	system(command);
	system(cmd4);
	system(cmd5);
        strcpy(command2, "vagrant ssh vagrant --command pg_restore -d vagrant ~/");
        strcat(command2, pgdumpname+1);
        system(command2);
	free(command);
        chdir(cmd6);
	exit(0);

}

void initcommands(char *cmd1, char *cmd2, char *cmd3, char *cmd4, char *cmd5, char *cmd6)
{
	cmd1 = "vagrant halt";
	cmd2 = "vagrant up";
	cmd3 = "vagrant ssh";
	cmd4 = "dropdb vagrant";
	cmd5 = "createuser urec";
	cmd6 = "~/";
	
}
