#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  int size = atoi(argv[1]);
  string filename = "../data/Random/randomArray_" + to_string(size);

  fstream file;
  file.open(filename, ios::out);
  if (!file) {
    std::cout << "File not found";
  } else {
    std::cout << "File created";

    srand(time(0));
    for (int i = 0; i < size; i++) {
      int num = rand() % 100000;
      file << num << " ";
    }
    file.close();
  }
  return 0;
}
