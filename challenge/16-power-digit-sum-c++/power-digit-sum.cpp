
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
const int ARRAY_SIZE = 500;
static int bigNumber[ARRAY_SIZE];

void printArray(int* array){
  cout << "bigNumber: ";
  for(int i = 0; i < ARRAY_SIZE; i++) {
    cout << array[i];
  }
  cout << "\n";
}

void clearArray() {
  for(int i = 0; i < ARRAY_SIZE; i++) {
    bigNumber[i] = 0;
  }
}

void setupArray(int input) {
  clearArray();
  // cout << "Generating the initial value for the bigNumber(" << input << ")...\n";
  int index = ARRAY_SIZE - 1;
  while(input > 0) {
    bigNumber[index] = input % 10;
    input = input / 10;
    index--;
  }
}

void multiplyOverArray(int factor) {
  int index = ARRAY_SIZE - 1;
  int remainder = 0;
  while(index > -1) {
    // cout << "Multiplying bigNumber index " << index << " (" << bigNumber[index] << ") by " << factor << " and adding " << remainder << "\n"; 
    bigNumber[index] = bigNumber[index] * factor;
    bigNumber[index] = bigNumber[index] + remainder;
    remainder = 0;
    while(bigNumber[index] > 9) {
      remainder = remainder + bigNumber[index] / 10;
      bigNumber[index] = bigNumber[index] % 10;
    }
    index--;
  }
} 

void powersOfTwo(int factor) {
  setupArray(1);
  for(int i = 1; i <= factor; i++) {
    multiplyOverArray(2);
    cout << i << "\n";
  }
}

int addDigits() {
  int sum = 0;
  for(int i = 0; i < ARRAY_SIZE; i++) {
    sum += bigNumber[i];
  }
  return sum;
}

int main(int argc, char** argv){
  setbuf(stdout, NULL);
  powersOfTwo(atoi(argv[1]));
  printArray(bigNumber);
  cout << "\nThe sum is: " << addDigits() << "\n";
}
