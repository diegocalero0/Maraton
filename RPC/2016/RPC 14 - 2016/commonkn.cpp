#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    int i;
    cin >> n;
    long long int result;
    long long int uno = 1;
    long long int dos = 1;
    for(i = 0; i < n; i++)
        uno *= 4;
    for(i = 0; i < n; i++)
        dos *= 2;
    result = uno * dos;
    cout<<result<<endl;
}
