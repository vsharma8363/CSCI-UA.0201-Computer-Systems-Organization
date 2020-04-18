#include <stdio.h>
#define COLS 2


void test1()
{
    int grid1[2][2] = {{5,6},{7,8}};
    int grid2[2][2] = {{2,2},{2,2}};
    int grid3[2][2] = {{2,2},{2,2}};

    int *curr = &grid1[0][0];
    int *new = &grid2[0][0];
    int *tmp = &grid3[0][0];

    int i = 1;
    int j = 1;
    
}

void test2()
{
    int grid1[2][2] = {{5,6},{7,8}};
    int grid2[2][2] = {{2,2},{2,2}};

    int(*ing)[2][2];
    int(*newg)[2][2];
    int(*tmpg)[2][2];

    ing = &grid1;
    newg = &grid2;

    printf("%d - %d\n", (*ing)[0][0], (*newg)[0][0]);

    tmpg = ing;
    ing = newg;
    newg = tmpg;

    printf("%d - %d\n", (*ing)[0][0], (*newg)[0][0]);

}

int main()
{
    test2();
}