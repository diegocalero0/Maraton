#include<bits/stdc++.h>
using namespace std;

void reduce(int n, int m){
    if(n % 6 == 0 && m % 6 == 0)
        cout << n/6 << "/" << m/6 << endl;
    else if(n % 3 == 0 && m % 3 == 0)
        cout << n/3 << "/" << m/3 << endl;
    else if(n % 2 == 0 && m % 2 == 0)
        cout << n/2 << "/" << m/2 << endl;
    else
        cout << n << "/" << m << endl;
}

int main(){
    int y, w, max_value, num;
    cin >> y >> w;
    max_value = max(y, w) - 1;
    num = 6 - max_value;
    reduce(num, 6);
    return 0;
}
