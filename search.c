#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *file;
	char filename[100];
	char pattern[100];
	printf("Enter the filename: ");
	scanf("%s",filename);
	printf("Enter the pattern: ");
	scanf("%s",pattern);
	file=fopen(filename,"r");
	if(file==NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	char line[100];
	int no;
	while(fgets(line,sizeof(line),file)!=NULL)
	{
		no++;
		if(strstr(line,pattern)!=NULL)
		{
			printf("Line %d : %s",no,line);
		}
	}
	fclose(file);
}
