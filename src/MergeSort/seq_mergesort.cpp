#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generateRandomArray(int *array, int n) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    int num = rand() % 100;
    array[i] = num;
  }
}

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

void mergesort(int arr[], int left, int right) {
  // If left is equal to right then there is only one element
  if (left < right) {
    int mid = left + (right - left) / 2;

    // Recursively sort left and right half
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

void printArray(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n = 10;
  int arr[n];
  generateRandomArray(arr, n);

  printArray(arr, n);
  mergesort(arr, 0, n - 1);
  printArray(arr, n);
  return 0;
}