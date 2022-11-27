#include <random>
#include <stdlib.h>
#include <time.h>

inline void generateRandomArray(int *arr, int n) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    int num = rand() % 10000;
    arr[i] = num;
  }
}

inline void generateReverseSortedArray(int *arr, int n) {
  for (int i = n - 1; i >= 0; i--) {
    arr[n - i - 1] = i;
  }
}
