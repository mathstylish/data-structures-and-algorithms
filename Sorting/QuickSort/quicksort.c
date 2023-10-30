#include <stdio.h>
#include <stdlib.h>

// swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// partition the array and return the pivot index
int partition(int *arr, int low, int high) {
  int pivot = arr[high];  // choose the rightmost element as the pivot
  int i = (low - 1);      // initialize the index of the smaller element
  for (int j = low; j <= high - 1; j++) {
    // curr element is smaller than or equal to the pivot
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  // swap the pivot element with the element at index i+1
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quick_sort(int *arr, int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    // recursively sort elements before and after the pivot
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
  }
}

int main(void) {
  int arr[] = {4, 7, 2, 6, 4, 1, 8, 3};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  quick_sort(arr, 0, arr_size - 1);
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
