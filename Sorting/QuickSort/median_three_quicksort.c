// credits to: https://github.com/yarnabrina/Hybrid-Sort
#include <stdio.h>
#include <stdlib.h>
#define CUTOFF \
  12  // arrays with size less than CUTOFF will be sorted by insertion sort
      // (optimum cutoffs are between 160 and 170, based on graphs)

// interchange elements of an array at two positions
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// to calculate median of the first, last and middlemost elements of an array
int median_of_three(int *array, int start, int end) {
  int middle = (start + end) / 2;
  if (array[start] > array[end]) {
    swap(&array[start], &array[end]);
  }
  if (array[middle] > array[end]) {
    swap(&array[middle], &array[end]);
  }
  if (array[start] > array[middle]) {
    swap(&array[start], &array[middle]);
  }
  return middle;
}

// partition hoare algorithm for quick sort using median of first, last and
// middlemost elements as pivot
int partition(int *array, int start, int end) {
  int key = median_of_three(array, start, end);
  swap(&array[start], &array[key]);
  int pivot = array[start];
  int i = (start - 1);
  int j = (end + 1);
  while (1) {
    do {
      i = (i + 1);
    } while (array[i] < pivot);
    do {
      j = (j - 1);
    } while (array[j] > pivot);
    if (i >= j) {
      return j;
    }
    swap(&array[i], &array[j]);
  }
}

// insertion sort algorithm
void insertion_sort(int *array, int start, int end) {
  if (start < end) {
    for (int i = (start + 1); i <= end; ++i) {
      int temp = array[i];
      int j = (i - 1);
      while ((j >= start) && (array[j] > temp)) {
        array[(j + 1)] = array[j];
        j = (j - 1);
      }
      array[(j + 1)] = temp;
    }
  }
}

void quicksort(int *array, int start, int end, int cutoff) {
  if (start < end) {
    // applying partition algorithm only when array size is more than cutoff
    if ((end - start + 1) > cutoff) {
      int key = partition(array, start, end);
      quicksort(array, start, key, cutoff);
      quicksort(array, (key + 1), end, cutoff);
    } else {
      insertion_sort(array, start, end);
    }
  }
}

int main(void) {
  int array[] = {5, 1, 3, 6, 11, 9, 8, 12, 15, 17, 23, 14, 45, 28};
  int arr_size = sizeof(array) / sizeof(array[0]);
  printf("before:\n");
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", array[i]);
  }
  quicksort(array, 0, arr_size - 1, CUTOFF);
  printf("\nafter sorting:\n");
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
