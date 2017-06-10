#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    if(n == k){
        for(int i = 0; i < n; i++){
            cout << "a";
        }
        cout << endl;
    }else{
        if(n == 2){
            cout << "ab" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
