#include <iostream>

using namespace std;

bool evenlyDivisible(int num)
{
    if(num % 20 != 0)
    {
        return false;
    }
    if(num % 19 != 0)
    {
        return false;
    }
    if(num % 18 != 0)
    {
        return false;
    }
    if(num % 17 != 0)
    {
        return false;
    }
    if(num % 16 != 0)
    {
        return false;
    }
    if(num % 15 != 0)
    {
        return false;
    }
    if(num % 14 != 0)
    {
        return false;
    }
    if(num % 13 != 0)
    {
        return false;
    }
    if(num % 12 != 0)
    {
        return false;
    }
    if(num % 11 != 0)
    {
        return false;
    }
    return true;
}


int main(){
    int i = 2519;
    do
    {
        i++;
    } 
    while(!evenlyDivisible(i));

    cout << i;
    char c;
    cin >> c;

    return 0;
}