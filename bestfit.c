#include<stdio.h>
#include<stdlib.h>

int partitions[10];

void bestfit(int p_size, int p) {
    // Sort partitions array in ascending order
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p - i - 1; j++) {
            if (partitions[j] > partitions[j + 1]) {
                int temp = partitions[j];
                partitions[j] = partitions[j + 1];
                partitions[j + 1] = temp;
            }
        }
    }
    
    int flag = 0;
    for (int i = 0; i < p; i++) {
        if (partitions[i] >= p_size) {
            printf("Process size %d - partition %d\n", p_size, partitions[i]);
            partitions[i] -= p_size;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Unable to allocate memory for process size %d\n", p_size);
    }
}

int main() {
    int n, p, val;
    
    printf("No. of partitions: ");
    scanf("%d", &n);
    
    printf("Enter the sizes of partitions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &partitions[i]);
    }
    
    printf("No. of processes: ");
    scanf("%d", &p);
    
    printf("Enter the sizes of processes:\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &val);
        bestfit(val, n);
    }
    
    return 0;
}
