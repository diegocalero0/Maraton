#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t = 1;
    cin >> n;
    cout << 1 << " ";
    int k = 2;
    long long sqrt;
    long long sum = 1;
    while(1){
        sqrt = k * k;
        k++;
        if(sqrt - sum > n)
            break;
        cout << sqrt - sum << " ";
        t++;
        sum += sqrt - sum;
    }
    int i = 2;
    while(t++ < n){
        cout << i << " ";
        i += 2;
    }
    cout << endl;
}
