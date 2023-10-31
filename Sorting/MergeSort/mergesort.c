#include <stdio.h>
#include <stdlib.h>

void merge(int *orig_arr, int left, int middle, int right) {
  int temp_arr[right];
  // copy original array values to array temp
  for (int i = 0; i <= right; i++) {
    temp_arr[i] = orig_arr[i];
  }
  // "split" array in virtual sections
  int i = left;  // left subarray. Will be incremented if a value from this
                 // subarray is chosen to be inserted into temp

  int j = middle + 1;  // right subarray. Will be incremented if a value from
                       // this subarray is chosen to be inserted into temp

  int k = left;  // will be incremented whenever values from the left or right
                 // subarrays are added to the temp array

  // iterate over left and right subarrays to sort
  while (i <= middle && j <= right) {
    // if value in left is less than right subarray, left will be added in temp
    // array, else right will be added
    if (temp_arr[i] < temp_arr[j]) {
      orig_arr[k] = temp_arr[i];
      i++;
    } else {
      orig_arr[k] = temp_arr[j];
      j++;
    }
    k++;
  }
  // if the initial half was not all consumed, make the append.
  while (i <= middle) {
    orig_arr[k] = temp_arr[i];
    i++;
    k++;
  }
  // if the final half was not all consumed, make the append.
  while (j <= right) {
    orig_arr[k] = temp_arr[j];
    j++;
    k++;
  }
}

void print_arr(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void merge_sort(int *arr, int left, int right) {
  if (left < right) {
    int middle = (left + right) / 2;
    // recursively call this method to divide array in subarrays
    merge_sort(arr, left, middle);       // left half
    merge_sort(arr, middle + 1, right);  // right half

    merge(arr, left, middle, right);  // then merge both left and half
  }
}

int main(void) {
  int arr[] = {7,  10, 19, 20, 32, 39, 43, 48, 60, 74, 91, 98,
               99, 9,  12, 17, 19, 28, 30, 31, 50, 80, 88, 89};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  merge_sort(arr, 0, arr_size - 1);
  print_arr(arr, arr_size);
  return EXIT_SUCCESS;
}
