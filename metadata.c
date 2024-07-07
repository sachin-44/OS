#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
	char file[100];
	struct stat file_stat;
	printf("Enter the filename: ");
	scanf("%s",file);
	if(stat(file,&file_stat)<0)
	{
		printf("Error\n");
		exit(1);
	}
	printf("\nFile Size : %ld bytes\n",file_stat.st_size);
	printf("File Access : ");
	if(file_stat.st_mode&R_OK){
		printf("Read\t");
	}
	if(file_stat.st_mode&W_OK){
		printf("Write\t");
	}
	if(file_stat.st_mode&X_OK){
		printf("Execution\n");
	}
	printf("Creation Time : %s",ctime(&file_stat.st_ctime));
	printf("Modification Time : %s",ctime(&file_stat.st_mtime));
	printf("Last Access Time : %s",ctime(&file_stat.st_atime));
}
