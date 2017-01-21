#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}

int main(){

    int n;
    cin >> n;
    if(n == 1)
        cout << 3 << "\n";
    else if(n == 2)
        cout << 4 << "\n";
    else if(n % 2 != 0)
        cout << 1 << "\n";
    else
        for(int i = 1; i < n; i++){
            if(!isPrime(n * i + 1)){
                cout << i << "\n";
                break;
            }
        }
}
