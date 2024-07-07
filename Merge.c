#include<stdio.h>
#include<stdlib.h>

void merge(int n,char filenames[10][10],char output[])
{
	FILE *out=fopen(output,"w");
	for(int i=0;i<n;i++){
		FILE* file=fopen(filenames[i],"r");
		char ch;
		while((ch==fgetc(file))!=EOF){
			fputc(ch,out);
		}
		fclose(file);
		

	}
	fclose(out);
}

int main()
{
	int n;
	char output[100];
	printf("NO. OF FILES: ");
	scanf("%d",&n);
	FILE *out=fopen(output,"w");
	char filenames[10][10];
	printf("Enter the filenames\n");
	for(int i=0;i<n;i++)
	{
		scanf("%s",filenames[i]);
	}
	printf("OUTPUT FILE: ");
	scanf("%s",output);
	merge(n,filenames,output);
	
	
	
}
