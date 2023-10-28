#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int length) {
  for (int i = 1; i < length; i++) {
    int j, key = arr[i];
    for (j = i - 1; j >= 0 && arr[j] > key; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = key;
  }
}

int main(void) {
  int arr[] = {5, 3, 1, 9, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  insertion_sort(arr, arr_size);
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
