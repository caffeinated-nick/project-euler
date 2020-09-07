#include <iostream>
#include <cstdio>

using namespace std;

bool isPrime(int num)
{
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int count = 0, ans;
    for(int i = 2; count < 10001; i++)
    {
        if(isPrime(i))
        {
            count++;
            cout << "Prime: " << count << " is: " << i << endl;
            ans = i;
        }
    }
    cout << ans;
    getchar();
    return 0;
}