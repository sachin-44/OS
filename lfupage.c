#include<stdio.h>
#include<stdlib.h>

#define F_SIZE 3

typedef struct {
    int pageno;
    int freq;
} page;

int pages[100];

int findIdx(page arr[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i].pageno == target)
        {
            return i;
        }
    }
    return -1;
}

void lfu(int n)
{
    page memory[F_SIZE];
    int pgflt = 0;

    for(int i = 0; i < F_SIZE; i++)
    {
        memory[i].pageno = -1;
        memory[i].freq = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int page = pages[i];
        int index = findIdx(memory, F_SIZE, page);

        if(index == -1)
        {
            pgflt++;
            int minIdx = 0;
            for(int j = 1; j < F_SIZE; j++)
            {
                if(memory[j].freq < memory[minIdx].freq)
                {
                    minIdx = j;
                }
            }
            memory[minIdx].pageno = page;
            memory[minIdx].freq = 1;
        }
        else
        {
            memory[index].freq++;
        }
    }
    printf("Page Faults in LFU : %d\n", pgflt);
}
