#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A = (int *)malloc(3000 * 1000 * sizeof(int));
    int *B = (int *)malloc(3000 * 1000 * sizeof(int));
    int *C = (int *)malloc(3000 * 1000 * sizeof(int));

    int i, j = 0;
    for(i = 0; i <  1000; i++)
    {
        for(j = 0; j < 3000; j++)
        {
            *(A + i*1000 + j) = i + j;
            *(B + i*1000 + j) = i * j;
        }
    }
    
    for(i = 0; i <  1000; i++)
        for(j = 0; j < 3000; j++)
            *(C + i*1000 + j) = *(A + i*1000 + j) + *(B + i*1000 + j);
    
    for(i = 0; i <  1000; i++){
        for(j = 0; j < 3000; j++){
            printf("A: %d ", *(A + i*1000 + j));
            printf("B: %d ", *(B + i*1000 + j));
            printf("C: %d ", *(C + i*1000 + j));
        }
    }
    
    return 0;
}
