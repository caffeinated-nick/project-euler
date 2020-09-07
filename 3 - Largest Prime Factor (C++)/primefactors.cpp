#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    double rootNum = 600851475143;
    std:vector<int> factors;

    for(int i = 2; i <= rootNum; i++){
        if(fmod(rootNum, i) == 0){
            rootNum = rootNum / i;
            factors.push_back(i);
            i = 2;
        }
    }

    for(int i = 0; i < factors.size(); i++){
        cout << factors[i] << "," << endl;
    }

    char c;
    cin >> c;
    return 0;
}