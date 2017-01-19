#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, max_;
    long arr[100];
    cin >> n;
    max_ = -1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > max_){
            max_ = arr[i];
        }
    }
    long res = 0;
    for(int i = 0; i < n; i++){
        res += max_ - arr[i];
    }
    cout << res << endl;
    return 0;
}
