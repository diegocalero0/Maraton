#include<bits/stdc++.h>
using namespace std;

int n, b, arr[90];

bool check(int n2){
    for(int i = 0; i < b; i++){
        for(int j = 0; j < b; j++){
            if(arr[i] - arr[j] == n2 || arr[j] - arr[i] == n2){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;

    while(cin >> n >> b && n + b){
        for(int i = 0; i < b; i++){
            cin >> arr[i];
        }
        flag = true;
        for(int i = 0; i <= n; i++){
            if(!check(i)){
                flag = !flag;
                break;
            }
        }
        if(!flag)
            cout << "N\n";
        else
            cout << "Y\n";
    }

    return 0;
}
