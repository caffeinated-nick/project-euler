#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int sumSquares = 0, squaredSum = 0;

    for(int i = 1; i <= 100; i++)
    {
        sumSquares += i * i;
        squaredSum += i;
    }
    squaredSum *= squaredSum;
    cout << squaredSum - sumSquares;
    getchar();
    return 0;
}