
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const short ONE = 3;
const short TWO = 3;
const short THREE = 5;
const short FOUR = 4;
const short FIVE = 4;
const short SIX = 3;
const short SEVEN = 5;
const short EIGHT = 5;
const short NINE = 4;

const short TEN = 3;
const short ELEVEN = 6;
const short TWELVE = 6;
const short THIRTEEN = 8;
const short FOURTEEN = 8;
const short FIFTEEN = 7;
const short SIXTEEN = 7;
const short SEVENTEEN = 9;
const short EIGHTEEN = 8;
const short NINETEEN = 8;

const short TWENTY = 6;
const short THIRTY = 6;
const short FORTY = 5;
const short FIFTY = 5;
const short SIXTY = 5;
const short SEVENTY = 7;
const short EIGHTY = 6;
const short NINETY = 6;

const short HUNDRED = 7;
const short THOUSAND = 8;

const short AND = 3;

int countSingleDigit(int digit) {
  switch(digit) {
    case 0: return 0;
    case 1: return ONE;
    case 2: return TWO;
    case 3: return THREE;
    case 4: return FOUR;
    case 5: return FIVE;
    case 6: return SIX;
    case 7: return SEVEN;
    case 8: return EIGHT;
    case 9: return NINE;
  }
}

int countTens(int tenDigit) {
  // cout << "Calculating tens chars in " << tenDigit << "\n";
  switch(tenDigit) {
    case 2: return TWENTY;
    case 3: return THIRTY;
    case 4: return FORTY;
    case 5: return FIFTY;
    case 6: return SIXTY;
    case 7: return SEVENTY;
    case 8: return EIGHTY;
    case 9: return NINETY;
  }
}

int countTeens(int number) {
  // cout << "Calculating teens chars in " << number << "\n";
  switch(number) {
    case 10: return TEN;
    case 11: return ELEVEN;
    case 12: return TWELVE;
    case 13: return THIRTEEN;
    case 14: return FOURTEEN;
    case 15: return FIFTEEN;
    case 16: return SIXTEEN;
    case 17: return SEVENTEEN;
    case 18: return EIGHTEEN;
    case 19: return NINETEEN;
  } 
}

int countHundreds(int hundredDigit) {
  // cout << "Calculating hundreds chars in " << hundredDigit << "\n";
  return countSingleDigit(hundredDigit) + HUNDRED;
}

int countThousands(int thousandDigit) {
  // cout << "Thousands digit: " << thousandDigit << "\n";
  return countSingleDigit(thousandDigit) + THOUSAND;
}

int countChars(int input) {
  int chars = 0;
  int currentNum = 0;

  for(int i = 1; i <= input; i++) {
    cout << "Chars after " << i << ": " << chars << "\n";
    currentNum = i;
    if (currentNum / 1000 > 0) {
      chars += countThousands(currentNum / 1000);
      currentNum %= 1000;
    }
    if (currentNum / 100 > 0) {
      chars += countHundreds(currentNum / 100);
      currentNum %= 100;
      if (currentNum > 0) {
        cout << "Hundred and something here!\n";
        chars += AND;
      }
    }
    if (currentNum / 10 > 0) {
      if (currentNum > 9 && currentNum < 20) {
        chars += countTeens(currentNum);
        continue;
      } 
      chars += countTens(currentNum / 10);
      currentNum %= 10;
    } 
    currentNum = currentNum % 10;
    if (currentNum > 0) {
      chars += countSingleDigit(currentNum);
    }
  }
  return chars;
}

int main(int argc, char** argv){
  setbuf(stdout, NULL);
  cout << "Characters: " << countChars(atoi(argv[1])) << "\n";
}
