#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

void listFile(char * basepath)
{
	char path[1000];
	struct dirent *dp;
	DIR * dir=opendir(basepath);
	
	if(!dir)
	{
		return;
	}
	while((dp=readdir(dir))!=NULL)
	{
		if(strcmp(dp->d_name,".")!=0 && strcmp(dp->d_name,"..")!=0)
		{
			printf("%s\n",dp->d_name);
			strcpy(path,basepath);
			strcat(path,"/");
			strcat(path,dp->d_name);
			listFile(path);
		}
	}
	closedir(dir);
}

int main()
{
	char path[100];
	printf("Enter path to list files: ");
	scanf("%s",path);
	listFile(path);
}
	
