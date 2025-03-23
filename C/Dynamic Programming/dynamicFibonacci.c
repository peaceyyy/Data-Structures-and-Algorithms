#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int fibTable[MAX_SIZE];

void initializeFibTable()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        fibTable[i] = -1;
    }
    fibTable[0] = 0;
    fibTable[1] = 1;
}
int bottomUpFibV1(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;

    for (int i = 2; i <= num; i++)
    {
        fibTable[i] = fibTable[i - 1] + fibTable[i - 2];
    }

    return fibTable[num];
}
int bottomUpFibV2(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;

    int prev = 0, curr = 1;

    for (int i = 2; i <= num; i++)
    {
        int temp = curr;
        curr += prev;
        prev = temp;
    }

    return curr;
}

int main()
{

    initializeFibTable();
    printf("%d\n", bottomUpFibV1(8));
    printf("%d\n", bottomUpFibV2(8));
}