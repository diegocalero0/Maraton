#include<bits/stdc++.h>
using namespace std;

int main(){
    int p1, p2, p3;

    cin >> p1 >> p2 >> p3;

    if(p1 == p2 || p1 == p3 || p2 == p3 || p1 + p2 == p3 || p1 + p3 == p2 || p2 + p3 == p1)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
