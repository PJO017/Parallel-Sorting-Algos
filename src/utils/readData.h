#include <fstream>
#include <string>
#include <iostream>

using namespace std;

inline void readData(string filename, int *arr, int size) {
  fstream file;
  file.open(filename, ios::in);
  for (int i = 0; i < size; i++) {
    file >> arr[i];
    if (file.eof()) {
      break;
    }
  }
}
