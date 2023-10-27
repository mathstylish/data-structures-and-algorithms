#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int length) {
  int temp = 0;
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main(void) {
  int arr[] = {7, 2, 12, 8, 3};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  bubble_sort(arr, arr_size);
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
