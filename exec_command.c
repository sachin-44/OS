#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define MAX 100

int main(){
	char input[MAX];
	printf("Enter the command: ");
	scanf("%s",input);
	while(strcmp(input,"stop")!=0)
	{
		pid_t a=fork();
		if(a==-1)
		{
			printf("Fork impossible\n");
			exit(1);
		}
		else if(a==0)
		{
			printf("a\n");
			if(execlp(input," ",NULL)==0){
				printf("Error exec()\n");
				exit(1);
			}
			
			wait(NULL);
			exit(0);
			
		}
		else
		{
			wait(NULL);
			printf("Command :");
			scanf("%s",input);
			
		}
	}
}
