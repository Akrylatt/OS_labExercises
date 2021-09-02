#include <stdio.h>

void bubble_sort(int x[], int pocet){
  for(int i = 0; i < pocet - 1; i++){
    for(int j = 0; j < pocet - i - 1; j++){
      if(x[j] < x[j + 1]){
        
        int a = x[j];
        x[j] = x[j + 1];
        x[j + 1] = a;
      }
    }
  }
}

void print_array(int size, int *param_array){
  printf("%d", param_array[0]);
  for(int i = 1; i < size; i++){
    printf("\t%d", param_array[i]);
  }
}

int main(void) {
  int array[] = {4, 5, 6, 0, 7, 2, 9, 7, 1, 8, -1, 3};
  bubble_sort(array, 12);
  print_array(12, array);
  return 0;
}