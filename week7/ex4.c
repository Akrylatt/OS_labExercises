#include <stdio.h>
#include <string.h>

void* my_realloc(void* ptr, int size, int newsize){
    if(ptr==NULL){
        return malloc(newsize);
    }
    else if(newsize == 0){
        free(ptr);
        return(NULL);
    }
    else{
        if(newsize > size){
            void* temp = malloc(newsize);
            memcpy(temp, ptr, size + sizeof(int));
            return temp;
        }
        else{
            void* temp = malloc(newsize);
            memcpy(temp, ptr, newsize + sizeof(int));
            return temp;
        }
    }
}

int main() {
    int* a = malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++){
        a[i] = i;
    }
    a = my_realloc(a, 4 * sizeof(int), 10 * sizeof(int));

    a[9] = 13;

    for(int i = 0; i < 10; i++){
        printf("%d ", a[i]);

    }

 //   --------------------------------------------
    printf(" \n");

    a = my_realloc(a, 4 * sizeof(int), 2 * sizeof(int));

    for(int i = 0; i < 2; i++){
        printf("%d ", a[i]);
    }

    // --------------------------------

    a = malloc(4 * sizeof(int));
    for(int i = 0; i < 4; i++){
        a[i] = i;
    }
    a = my_realloc(a, 4 * sizeof(int), 0);
    if(a == NULL){
        printf("\na is a null pointer");
    }

}