#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * file;
	char filename[100];
	char ch;
	int lines=0,words=0,characters=0;
	printf("Enter the filename: ");
	scanf("%s",filename);
	file=fopen(filename,"r");
	if(file==NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	while((ch=fgetc(file))!=EOF)
	{
		characters++;
		if(ch==' '||ch=='\t'||ch=='\n'||ch=='\r')
			words++;
		if(ch=='\n')
			lines++;
	}
	
	if(characters>0)
		words++;
	fclose(file);
	printf("LINE COUNT : %d\n",lines);
	printf("WORD COUNT : %d\n",words);
	printf("CHARACTER COUNT : %d\n",characters);
}
