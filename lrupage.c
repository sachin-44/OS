#include<stdio.h>
#include<stdlib.h>

#define F_SIZE 3

int pages[100];

void lru(int n)
{
    int memory[F_SIZE] = {-1, -1, -1};
    int pgflt = 0;
    int lru = 0;

    for(int i = 0; i < n; i++)
    {
        int page = pages[i];
        int index = findIndex(memory, F_SIZE, page);

        if(index == -1)
        {
            pgflt++;
            memory[lru] = page;
            lru = (lru + 1) % F_SIZE;
        }
        else
        {
            // Move the recently used page to the end of the list
            for(int j = index; j < F_SIZE - 1; j++)
            {
                memory[j] = memory[j + 1];
            }
            memory[F_SIZE - 1] = page;
        }
    }
    printf("Page Faults in LRU : %d\n", pgflt);
}
