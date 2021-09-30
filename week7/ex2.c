#include <stdio.h>

int main() {
    int N;
    printf("What is the length of the array to allocate?\n");
    scanf_s("%d", &N);

    int *array;
    array = (int *) malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        array[i] = i;
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}
