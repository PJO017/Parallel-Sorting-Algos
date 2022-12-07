#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  int size = atoi(argv[1]);
  string filename = "../data/Sorted/sorted_" + to_string(size);

  fstream file;
  file.open(filename, ios::out);
  if (!file) {
    std::cout << "File not found";
  } else {
    std::cout << "File created";

    int arr[size];
    for (int i = 0; i < size; i++) {
      arr[i] = i;
    }

    std::sort(arr, arr + size);

    for (int j = 0; j < size; j++) {
      file << arr[j] << " ";
    }

    file.close();
  }
  return 0;
}
