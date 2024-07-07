#include<stdio.h>
int tq=0;

struct process{
	int id,at,bt;
	int ct,tat,tbt,wt;
}p[10];

void read(int n){
printf("Enter process details ID AT BT \n");
	for(int i=0;i<n;i++)
	{
		printf("Process %d :",i+1);
		scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
	}
	for(int i=0;i<n;i++)
	{
		p[i].tbt=p[i].bt;
	}
}

void sort(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				struct process p1=p[i];
				p[i]=p[i+1];
				p[i+1]=p1;
			}
		}
	}
}


void RRS(int n) {
    int x = 0, y = 0, i = 0;
    float t_tat = 0, t_wt = 0;
    
    while (y != n) {
        if (p[i].bt > 0) {
            if (p[i].bt > tq) {
                p[i].bt -= tq;
                x += tq;
            } else {
                x += p[i].bt;
                p[i].bt = 0;
                p[i].ct = x;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].tbt;
                t_tat += p[i].tat;
                t_wt += p[i].wt;
                y++;
            }
        }
        
     
        if (i == n - 1)
            i = 0;
        else
            i++;
        
      
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (p[j].bt > 0) {
                flag = 0;
                break;
            }
        }
        
        
        if (flag)
            break;
    }
    
    printf("Average WT: %f\n", (t_wt / n));
    printf("Average TAT: %f\n", (t_tat / n));
}


int main()
{
	int n,t;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the time quantum: ");
	scanf("%d",&t);
	tq=t;
	read(n);
	RRS(n);
	printf("ID\tAT\tBT\tTAT\tCT\tWT\n");
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].tbt,p[i].tat,p[i].ct,p[i].wt);
	}
}	
				
		
		
		
		
		
		
		
		
		
		
		
		
		
		
