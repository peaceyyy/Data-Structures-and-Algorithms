#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int fibTable[MAX_SIZE];

void initializeFibTable() {
    for (int i = 0; i < MAX_SIZE; i++) {
        fibTable[i] = -1;
    }
    fibTable[0] = 0;
    fibTable[1] = 1;
}

int fib(int num) {
    if (fibTable[num] != -1) {
        return fibTable[num];
    }
    for (int i = 2; i <= num; i++) {
        fibTable[i] = fibTable[i - 1] + fibTable[i - 2];
    }
    return fibTable[num];
}

int main() {
    initializeFibTable();
    printf("%d", fib(4));
}