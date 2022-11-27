#include "../utils/generateInput.h"
#include <cctype>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string.h>

using namespace std;
using namespace std::chrono;

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

void mergeSort(int arr[], int left, int right) {
  // If left is equal to right then there is only one element
  if (left < right) {
    int mid = left + (right - left) / 2;

    // Recursively sort left and right half
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int arr[n];

  if (argc > 2 && strcmp(argv[2], "-r") == 0) {
    generateReverseSortedArray(arr, n);
  } else {
    generateRandomArray(arr, n);
  }

  auto start = high_resolution_clock::now();
  mergeSort(arr, 0, n - 1);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << duration.count() << " μs" << endl;

  return 0;
}
