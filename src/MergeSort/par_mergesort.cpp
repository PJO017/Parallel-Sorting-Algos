#include "omp.h"
#include <cctype>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>

using namespace std;
using namespace std::chrono;
using std::stoi;

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
  int len1 = mid - left + 1; // Length of left subarray
  int len2 = right - mid;    // Length of right subarray

  // Create temp arrays
  int left_subarr[len1], right_subarr[len2];

  // Copy data into temp arrays
  int i, j;
  for (i = 0; i < len1; i++) {
    left_subarr[i] = arr[left + i];
  }
  for (j = 0; j < len2; j++) {
    right_subarr[j] = arr[mid + j + 1];
  }

  // Merge subarrays back into array
  i = 0;
  j = 0;
  int k = left;
  while (i < len1 && j < len2) {
    if (left_subarr[i] <= right_subarr[j]) {
      arr[k] = left_subarr[i];
      i++;
    } else {
      arr[k] = right_subarr[j];
      j++;
    }
    k++;
  }

  // Insert remaining elements
  while (i < len1) {
    arr[k] = left_subarr[i];
    k++;
    i++;
  }

  while (j < len2) {
    arr[k] = right_subarr[j];
    k++;
    j++;
  }
}

void mergeSortSeq(int arr[], int left, int right) {
  // If left is equal to right then there is only one element
  if (left < right) {
    int mid = left + (right - left) / 2;

    // Recursively sort left and right half
    mergeSortSeq(arr, left, mid);
    mergeSortSeq(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

void mergeSortRecursive(int array[], int left, int right) {
  if (left < right) {
    if ((right - left) >= 1000) {
      int mid = (left + right) / 2;
#pragma omp taskgroup
      {
#pragma omp task shared(array) untied if (right - left >= (1 << 14))
        {
          mergeSortRecursive(array, left,
                             mid); // One thread sort left sub-array
        }
#pragma omp task shared(array) untied if (right - left >= (1 << 14))
        {
          mergeSortRecursive(array, mid + 1,
                             right); // One thread sort right sub-array
        }
#pragma omp taskyield
        merge(array, left, mid, right); // Merge the two sorted sub-arrays
      }
    } else {
      mergeSortSeq(array, left, right);
    }
  }
}

void mergeSort(int *array, int n) {
#pragma omp parallel
#pragma omp single nowait
  mergeSortRecursive(array, 0, n);
}

void generateRandomArray(int *array, int n) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    int num = rand() % 10000;
    array[i] = num;
  }
}

void printArray(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int n = stoi(argv[1]);
  int arr[n];
  generateRandomArray(arr, n);

  auto start = high_resolution_clock::now();
  mergeSort(arr, n);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);

  cout << duration.count() << " ms" << endl;

  return 0;
}
