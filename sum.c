#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int even_sum=0,odd_sum=0;
	pid_t pid=fork();
	if(pid==0)
	{
		for(int i=2;i<=1000;i+=2)
		{
			even_sum+=i;
		}
	printf("Sum of even numbers is %d\n",even_sum);
	}
	
	else if(pid<0)
	{
		printf("Fork failed\n");
		return 1;
	}
	
	else
	{
		for(int i=1;i<=1000;i+=2)
		{
			odd_sum+=i;
		}
		printf("Sum of odd numbers is %d\n",odd_sum);
		wait(NULL);
	}
}
		
