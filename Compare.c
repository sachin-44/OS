#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *file1,*file2;
	char a[100],b[100];
	printf("Enter the filename:\n");
	scanf("%s%s",a,b);
	file1=fopen(a,"r");
	file2=fopen(b,"r");
	if(file1==NULL||file2==NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	int line_no=0;
	char line1[100],line2[100];
	while((fgets(line1,sizeof(line1),file1)!=NULL)&&(fgets(line2,sizeof(line2),file2)!=NULL))
	{
		line_no++;
		if(strcmp(line1,line2)!=0){
			printf("Difference at line %d\n",line_no);
				printf("File1 : %s",line1);
				printf("File2 : %s",line2);
		}
	}
	while(fgets(line1,sizeof(line1),file1)!=NULL&&fgets(line2,sizeof(line2),file2)==NULL)
	{
		printf("Extra line in file1: %s",line1);
	}
	while(fgets(line1,sizeof(line1),file1)==NULL&&fgets(line2,sizeof(line2),file2)!=NULL)
	{
		printf("Extra line in file2: %s",line2);
	}
	
	fclose(file1);
	fclose(file2);
	
}		
