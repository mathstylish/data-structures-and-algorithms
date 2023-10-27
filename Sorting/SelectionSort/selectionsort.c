#include <stdio.h>
#include <stdlib.h>

// time complexity is O(n²)
void selection_sort(int *arr, int length) {
  int min_index = 0, temp = 0;
  for (int i = 0; i < length; i++) {
    min_index = i;  // assumes that the current index is the smallest
    for (int j = i + 1; j < length; j++) {  // searches for the smallest
      if (arr[min_index] > arr[j]) {  // if value in min_index is greater than
                                      // value in j, then min_index is wrong

        min_index = j;  // update min_index to correct min_index
      }
    }
    // swap current value with value at min_index position
    temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
}

int main(void) {
  int arr[] = {15, 28, 17, 12, 18, 9, 6};
  size_t arr_size = sizeof(arr) / sizeof(arr[0]);
  selection_sort(arr, arr_size);
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
