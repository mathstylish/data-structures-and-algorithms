#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_max(int *arr, int length) {
  int k = arr[0];
  for (int i = 1; i < length; i++) {
    if (arr[i] > k) k = arr[i];
  }
  return k;
}

int *counting_sort(int *arr, int k, int length) {
  int c[k];
  memset(c, 0, sizeof(int) * k);  // fill counting array with zeros

  int *b = malloc(sizeof(int) * length);  // b size must be same as arr

  // counting frequency
  // ex: number 3 frequency will be stored at index 2, 4 at index 3 and so on
  // for a = [1,9,1,3,4,7,6,7] and k = 9, c will be [2,0,1,1,0,1,2,0,1]
  for (int i = 0; i < length; i++) {
    c[arr[i] - 1] += 1;  // increase frequency
  }

  // cumulative sum to register number of elements which are less than or equal
  // the cumulative calculation is based on the current value (c[i]) = current
  // value (c[i]) + previous value (c[i-1]). to c[i] for c =
  // [2,0,1,1,0,1,2,0,1], c will be [2,2,3,4,4,5,7,7,8] For example, the value 8
  // means that there are 8 values less than or equal to 9 in the array. The
  // value 5 means that there are 5 values less than or equal to 4 and so on
  for (int i = 1; i < k; i++) {
    c[i] += c[i - 1];
  }

  // the sorting happens from beginning to end
  // arr[i]: value to be inserted, i.e: 3
  // arr[i] - 1: index to look in c, i.e: if value is 3, then index in c is 2
  // c[arr[i] - 1]: value in c, which indicates where (index -1) in b, the value
  // arr[i] should be inserted, i.e: if index has value 5, then value must be
  // inserted at index 4 in b
  // c[arr[i] - 1] -= 1: decrement ocurrence to insert in other indexes (same
  // value in other index if exists or none if 0)
  for (int i = length - 1; i >= 0; i--) {
    b[c[arr[i] - 1] - 1] = arr[i];
    c[arr[i] - 1] -= 1;
  }

  return b;  // return b sorted
}

void print_arr(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {
  int arr[] = {7,  10, 19, 20, 32, 39, 43, 48, 60, 74, 91, 98,
               99, 9,  12, 17, 19, 28, 30, 31, 50, 80, 88, 89};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  int max_element = find_max(arr, arr_size);
  int *sorted_arr = counting_sort(arr, max_element, arr_size);
  print_arr(sorted_arr, arr_size);
  free(sorted_arr);
  return EXIT_SUCCESS;
}
