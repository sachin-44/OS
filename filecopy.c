#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * ptr1,*ptr2;
	char filename[100],c;
	printf("Enter the filename to open for reading: ");
	scanf("%s",filename);
	ptr1=fopen(filename,"r");
	if(ptr1==NULL)
	{
		printf("Error opening file %s\n",filename);
		exit(0);
	}
	printf("Enter the filename to open for writing: " );
	scanf("%s",filename);
	ptr2=fopen(filename,"w");
	if(ptr1==NULL)
	{
		printf("Error opening file %s\n",filename);
		exit(0);
	}
	c=fgetc(ptr1);
	while(c!=EOF)
	{
		fputc(c,ptr2);
		c=fgetc(ptr1);
	}
	printf("Contents copied to file\n");
	
	if(ferror(ptr1))
		printf("Error reading from file\n");
	if(ferror(ptr2))
		printf("Error writing to file\n");
	
		
	fclose(ptr1);
	fclose(ptr2);
	
}
