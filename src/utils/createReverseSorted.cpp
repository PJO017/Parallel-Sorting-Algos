
using namespace std;
inline void generateReverseSortedArray(int *arr, int n) {
  for (int i = n - 1; i >= 0; i--) {
    arr[n - i - 1] = i;
  }
}
