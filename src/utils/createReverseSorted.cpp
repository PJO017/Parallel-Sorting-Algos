#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  int size = atoi(argv[1]);
  string filename =
      "../data/ReverseSorted/reverseSortedArray_" + to_string(size);

  fstream file;
  file.open(filename, ios::out);
  if (!file) {
    std::cout << "File not found";
  } else {
    std::cout << "File created";

    for (int i = size - 1; i >= 0; i--) {
      file << i << " ";
    }
    file.close();
  }
  return 0;
}
