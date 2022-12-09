#include "../utils/readData.h"
#include <cctype>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iostream>
#include <omp.h>
#include <string.h>

using std::cout;
using std::endl;
using namespace std::chrono;

class ParallelQuickSort {
  // keep count of threads
  int k = 0;

private:
  // partitioning procedure
  int partition(int arr[], int l, int r) {
    int i = l + 1;
    int j = r;
    int key = arr[l];
    int temp;
    while (true) {
      while (i < r && key >= arr[i])
        i++;
      while (key < arr[j])
        j--;
      if (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      } else {
        temp = arr[l];
        arr[l] = arr[j];
        arr[j] = temp;
        return j;
      }
    }
  }

public:
  void quickSort(int arr[], int l, int r) {
    if (l < r) {
      int p = partition(arr, l, r);

      {
#pragma omp task shared(arr)
        {
          k = k + 1;
          quickSort(arr, l, p - 1);
        }
#pragma omp task shared(arr)
        {
          k = k + 1;
          quickSort(arr, p + 1, r);
        }
      }
    }
  }
  // run the whole procedure
  void run(int *arr, int size, int num_threads) {

    auto start = high_resolution_clock::now();
    omp_set_dynamic(0);
    omp_set_num_threads(num_threads);
#pragma omp parallel
    {
#pragma omp single nowait
      { quickSort(arr, 0, size - 1); }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << " μs" << endl;
  }
};

int main(int argc, char *argv[]) {
  int size = atoi(argv[1]);
  string filename = argv[2];
  int num_threads = atoi(argv[3]);
  int arr[size];

  readData(filename, arr, size);
  ParallelQuickSort pqs;
  pqs.run(arr, size, num_threads);
  return 0;
}
