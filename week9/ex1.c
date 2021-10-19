#include <stdio.h>
#include <stdlib.h>
#define PG 10
#define BITS 16

FILE *file;

int find(int ar[], int a){
    for(int j = 0; j < PG; j++){
        if(ar[j] == a){
            return 1;
        }
    }
    return 0;
}

int toRemove(int ar[]){
    int min = 0;
    for(int j = 1; j < PG; j++){
        if(ar[0] > ar[j]){
            min = j;
        }
    }
    return min;
}

int main() {


   int missCount = 0;
   int hitCount = 0;

    file = fopen("C:\\Users\\42072\\OneDrive\\Documents\\Innopolis\\OperatingSystems\\Labs\\9\\input.txt", "r");

    if (!file) {
        perror("Cannot open file.\n");
        return 0;
    }

    int virtual[PG];
    int age[PG];
    int current;
    int i;
    int free;

    for(int i = 0; i < PG; i++){
        age[i] = 0;
    }

    for (i = 0; i < 1000; i++)
    {
        fscanf(file, "%d", &current);

        if(find(virtual, current) == 1){
            hitCount++;
        }
        else{
            missCount++;
            free = toRemove(age);
            virtual[free] = current;
            age[free] = 0;

        }

        for(int j = 0; j < PG; j++){
            age[i] = age[i] << 1;
        }
        age[free] = age[free] / 2;


    }

    printf("Hit/miss = %d", (missCount/hitCount));
    return 0;
}
