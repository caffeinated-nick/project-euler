#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main(){
  int max = 1000001;
  int* sequenceCounts = new int[max];
  sequenceCounts[0] = 0;

  for(int i = 1; i < max; i++) {
    double currentNum = i;
    int currentSequence = 1;
    // printf("Now running for %d\n", currentNum);
    // printf("  %d -> ", i);

    while(currentNum > 1) {
      // If we've already counted the seuqnce for currentNum we can use the previous calculation.
      if(currentNum < i) {
        // printf("(see %d)\n  currentNum less than i, adding array value for currentNum (%d) from array and breaking...\n", currentNum, sequenceCounts[currentNum]);
        currentSequence--;
        currentSequence += sequenceCounts[(int) currentNum];
        break;
      }
      // If even, divide by 2
      if(fmod(currentNum, 2.0) == 0.0) {
        currentNum /= 2.0;
      // else multiply by 3, add 1
      } else {
        currentNum *= 3;
        currentNum += 1;
      }
      currentSequence++;
      // printf("  currentSequence now at %d, num now at %d\n", currentSequence, currentNum);
      // printf("%d -> ", currentNum);
    }
    // printf("  thank god that's over, adding %d at position %d\n", currentSequence, i);
    sequenceCounts[i] = currentSequence;
    fflush( stdout );
    if(currentNum < 1) {
      printf("Something has gone horribly wrong...\n i = %d\n", i);
    }
  }

  printf("Checking for the longest sequence...\n");
  int numWithLongestSequence = 0;
  for(int i = 0; i < max; i++) {
    // printf("%d: %d,\n", i, sequenceCounts[i]);
    if (sequenceCounts[i] > sequenceCounts[numWithLongestSequence]) {
      numWithLongestSequence = i;
      printf("New num with max sequence found: %d, with a sequence of: %d\n", i, sequenceCounts[i]);
    }
  }
  printf("Looks like the highest starting number was %d with a chain of %d.\n", numWithLongestSequence, sequenceCounts[numWithLongestSequence]);
}