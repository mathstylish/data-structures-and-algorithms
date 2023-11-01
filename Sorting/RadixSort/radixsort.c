#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGIT(NUMBER, EXPONENT, BASE) ((NUMBER / EXPONENT) % BASE)

int find_max(int *arr, int length) {
  int k = arr[0];
  for (int i = 1; i < length; i++) {
    if (arr[i] > k) k = arr[i];
  }
  return k;
}

// counting_sort version for radix sort
// the main difference is that the value of c is based on the base and not the
// largest value in the array
void counting_sort(int *arr, int length, int div, int base, int *temp) {
  int t, c[base], acc = 0;
  memset(c, 0, sizeof(int) * base);

  // counting occurrences of a digit
  for (int i = 0; i < length; i++) {
    c[DIGIT(arr[i], div, base)] += 1;
  }

  // prefix sum
  for (int i = 0; i < base; i++) {
    t = c[i];
    c[i] = acc;
    acc += t;
  }

  // copy values from arr to temp arr in the correct order
  for (int i = 0; i < length; i++) {
    temp[c[DIGIT(arr[i], div, base)]] = arr[i];
    c[DIGIT(arr[i], div, base)]++;
  }

  // copy values from temp to original array
  memcpy(arr, temp, sizeof(int) * length);
}

void radix_sort(int *arr, int length) {
  int k, div = 1;
  k = find_max(arr, length);
  int *temp = malloc(sizeof(int) * length);
  while (k > 0) {
    counting_sort(arr, length, div, 10, temp);
    div *= 10;  // get next 10^n: 1 * 10, 10 * 10, 10 * 10 * 10, .. etc
    k /= 10;  // cut off digits, i.e 129 -> 129/10 (cut 9), 12/10 (cut 2), 1/10
              // (0, finish)
  }
  free(temp);
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
  radix_sort(arr, arr_size);
  print_arr(arr, arr_size);
  return EXIT_SUCCESS;
}
