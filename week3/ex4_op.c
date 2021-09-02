#include <stdio.h>

void quick_sort(int arr[], int left, int right){
  if(left == right){
    return;
  }

  int pivot = arr[left]; 
  int index = left;

  for(int i = left + 1; i < right; i++){
    if(arr[i] > pivot){
      int a = arr[++index];
      arr[index] = arr[i];
      arr[i] = a;
    }
  }
 
  int a = arr[index];
  arr[index] = arr[left];
  arr[left] = a;

  quick_sort(arr, left, index);
  quick_sort(arr, index + 1, right);
  
}

void print_array(int size, int *param_array){
  printf("%d", param_array[0]);
  for(int i = 1; i < size; i++){
    printf("\t%d", param_array[i]);
  }
}

int main(void) {
int pole1[] = {4, 5, 6, 0, 7, 2, 9, 7, 1, 8, -1, 3};

quick_sort(pole1, 0, 12);
print_array(12, pole1);
return 0;
}