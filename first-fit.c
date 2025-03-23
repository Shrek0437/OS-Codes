#include <stdio.h>

void firstfit(int blockSize[], int n, int processSize[], int m){
    int allocation[n];

    for(int i=0; i<n; i++){
        allocation[i] = -1;
    }

    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (blockSize[j]>=processSize[i]){
                allocation[i] = j;
                blockSize[j] -= processSize[i];
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock Size\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != -1){
            printf("%d\n", allocation[i]+1);
        }
        else{
            printf("NOT ALLOCATED\n");
        }
    }
}

int main(){
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);

    firstfit(blockSize, n, processSize, m);
    return 0;
}