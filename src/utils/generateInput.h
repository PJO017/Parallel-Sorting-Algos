#include <iostream>
#include <ostream>

inline void generateRandomArray(int *array, int n) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    int num = rand() % 10000;
    array[i] = num;
  }
}

inline void generateReverseSortedArray(int *array, int n) {
  for (int i = n - 1; i >= 0; i--) {
    array[n - i - 1] = i;
  }
}
