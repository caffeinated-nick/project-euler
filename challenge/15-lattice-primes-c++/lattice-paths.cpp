/*
  Hilton and Pederson 1991:
  Lattice paths are given by
    ( a + b ) 
    (   b   )

  where a is the x length and b is the y length

  We then solve using binomial coefficients:

          (a + b)!
      ---------------
      (a + b - b)! b!
*/

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
const int ARRAY_SIZE = 50;
static int factorial[ARRAY_SIZE];


void printArray(int* array){
  cout << "Factorial: ";
  for(int i = 0; i < ARRAY_SIZE; i++) {
    cout << array[i];
  }
  cout << "\n";
}

void clearFactorialArray() {
  for(int i = 0; i < ARRAY_SIZE; i++) {
    factorial[i] = 0;
  }
}

void setupFactorialArray(int input) {
  clearFactorialArray();
  cout << "Generating the initial value for the factorial(" << input << ")...\n";
  int index = ARRAY_SIZE - 1;
  while(input > 0) {
    factorial[index] = input % 10;
    input = input / 10;
    index--;
  }
}

void multiplyOverArray(int factor) {
  int index = ARRAY_SIZE - 1;
  int remainder = 0;
  while(index > -1) {
    cout << "Multiplying factorial index " << index << " (" << factorial[index] << ") by " << factor << " and adding " << remainder << "\n"; 
    factorial[index] = factorial[index] * factor;
    factorial[index] = factorial[index] + remainder;
    remainder = 0;
    while(factorial[index] > 9) {
      remainder = remainder + factorial[index] / 10;
      factorial[index] = factorial[index] % 10;
    }
    index--;
  }
} 

char * generateFactorial(int input) {
  setupFactorialArray(input);
  input--;
  while (input > 0) {
    cout << "New input: " << input << "\n";
    multiplyOverArray(input);
    input--;
    printArray(factorial);
  }
}

int binomialCoefficient(int x, int y) {
  char* numerator = generateFactorial(x + y);
  // need to be able to multiply and divide arrays :)
  // char* denominator = generateFactorial(x + y - y) * generateFactorial(y);
  // return numerator / denominator;
}

int main(){
  setbuf(stdout, NULL);
  int gridDimens = 10; 
  binomialCoefficient(gridDimens, gridDimens);
  printArray(factorial);
}


