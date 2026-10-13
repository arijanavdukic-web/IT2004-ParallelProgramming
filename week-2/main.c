#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr;
    int sum = 0;
    arr = (int *) malloc(n * sizeof(int));

    printf("First element: %d\n", arr[0]);

    for (int i = 0; i <= n; i++) {arr[i] = i * 10;}

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of array: %d\n", sum);
    return 0;
}
