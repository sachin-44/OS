#include<stdio.h>
#include<stdlib.h>

#define F_SIZE 3

int pages[100];

void FIFO(int n)
{
    int memory[F_SIZE] = {-1, -1, -1};
    int pgflt = 0;
    int current = 0;

    for(int i = 0; i < n; i++)
    {
        int page = pages[i];
        if(findIndex(memory, F_SIZE, page) == -1)
        {
            pgflt++;
            memory[current] = page;
            current = (current + 1) % F_SIZE;
        }
    }
    printf("Page Faults in FIFO : %d\n", pgflt);
}
