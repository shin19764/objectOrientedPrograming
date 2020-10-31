//
//  main.c
//  test
//
//  Created by Changwoo Pyo on 2020/10/23.
//
//  To compare efficiency of recursive and non-recursive, using end number as 46.

#include <stdio.h>
#include <time.h>

int fibbonacciRecursive (int num) {
    if (num == 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else {
        return fibbonacciRecursive(num - 2) + fibbonacciRecursive(num - 1);
    }
}


int fibbonacciMemoizationArray[2] = {0, 1};
int fibbonacciMemoization (int num) {
    if (num == 0) {
        fibbonacciMemoizationArray[0] = 0;
        return fibbonacciMemoizationArray[0];
    } else if (num == 1) {
        fibbonacciMemoizationArray[1] = 1;
        return fibbonacciMemoizationArray[1];
    } else {
        int next = fibbonacciMemoizationArray[0] + fibbonacciMemoizationArray[1];
        fibbonacciMemoizationArray[0] = fibbonacciMemoizationArray[1];
        fibbonacciMemoizationArray[1] = next;
        return fibbonacciMemoizationArray[1];
    }
}


int main() {
    int endNum = 0;
    double result;
    
    // Decide End Number
    printf("Enter \"END NUMBER\": ");
    scanf("%d", &endNum);
    
    // Solve using non-recursive fuction
    printf("Unisg Non-recursive Solution\n");
    clock_t memoization;
    memoization = clock();
    for (int count = 0; count <= endNum; count++) {
        printf("fib(%d) = %d\n", count, fibbonacciMemoization(count));
    }
    result = (double)(clock() - memoization) / CLOCKS_PER_SEC;
    printf("take time is %5.2f\n\n", result);
    
    // Solve using recursive fuction
    printf("Unisg Recursive Solution\n");
    clock_t recursive;
    recursive = clock();
    for (int count = 0; count <= endNum; count++) {
        printf("fib(%d) = %d\n", count, fibbonacciRecursive(count));
    }
    result = (double)(clock() - recursive) / CLOCKS_PER_SEC;
    printf("take time is %5.2f\n", result);
    
    return 0;
}
