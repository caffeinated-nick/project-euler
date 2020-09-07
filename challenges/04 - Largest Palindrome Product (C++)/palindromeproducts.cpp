#include <iostream>
#include <string.h>

using namespace std;

bool palindrome(int num)
{
    char digits[6];
    sprintf(digits, "%d", num);
    for(int i = 0; i < strlen(digits) - 1; i++)
    {
        if(digits[i] != digits[5 - i])
        {
            return false;
        }
    }  
    return true;
}

int main()
{
    int max = 9009,
        current = 0;

    for(int i = 999; i > 99; i--)
    {
        for(int j = 999; j > 99; j--)
        {
            current = i * j;
            if(current > max)
            {
                if(palindrome(current))
                {
                    cout << current << " is the current largest palindrome!" << endl;
                    max = current;
                }
            }
        }
    }


    cout << "Finished: " << max << " is the largest palindrome!" << endl;
    char c;
    cin >> c;
}