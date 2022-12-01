#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
  int size = atoi(argv[1]); 
  string filename = "../data/Random/randomArray_" + to_string(size);

  fstream file;
  std::cout << "Filename: " << filename << " \n";
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
