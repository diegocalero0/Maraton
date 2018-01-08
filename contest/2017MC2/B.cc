#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main(){

    string a, b;
    cin >> a >> b;

    int res = 0;
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            res += (a[i] - '0') * (b[j] - '0');

    cout << res << endl;
    return 0;
}
