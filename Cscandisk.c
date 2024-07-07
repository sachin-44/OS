#include<stdio.h>
#include<stdlib.h>

int requests[100];

void sort(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(requests[j] > requests[j + 1])
            {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
}

void C_SCAN(int n, int head, int direction, int size)
{
    int seek = 0;
    sort(n);

    int index;
    for(index = 0; index < n; index++)
    {
        if(requests[index] > head)
        {
            break;
        }
    }

    if(direction == 0) // Towards lower cylinder numbers
    {
        for(int i = index; i < n; i++)
        {
            seek += abs(head - requests[i]);
            head = requests[i];
        }
        seek += size - 1 - head;
        head = size - 1;
        seek += head;
        head = 0;
        for(int i = 0; i < index; i++)
        {
            seek += abs(head - requests[i]);
            head = requests[i];
        }
    }
    else // Towards higher cylinder numbers
    {
        for(int i = index - 1; i >= 0; i--)
        {
            seek += abs(head - requests[i]);
            head = requests[i];
        }
        seek += head;
        head = 0;
        seek += size - 1 - head;
        head = size - 1;
        for(int i = n - 1; i >= index; i--)
        {
            seek += abs(head - requests[i]);
            head = requests[i];
        }
    }

    printf("C-SCAN Total Seek Time: %d\n", seek);
}

int main()
{
    int n, head, size, direction;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    printf("Enter the requests: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the size of the disk: ");
    scanf("%d", &size);
    printf("Enter direction (0: lower cylinder numbers, 1: higher cylinder numbers): ");
    scanf("%d", &direction);

    C_SCAN(n, head, direction, size);

    return 0;
}
