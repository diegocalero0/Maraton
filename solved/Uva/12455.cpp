#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, p, bars[20];
    cin >> t;

    while(t--){
        cin >> n >> p;
        for(int i = 0; i < p; i++)
            cin >> bars[i];
        int sum;
        for(int i = 0; i < (1 << p); i++){
            sum = 0;
            for(int j = 0; j < p; j++){
                if(i & (1 << j)){
                    sum += bars[j];
                }
            }
            if(sum == n)
                break;
            else
                sum = -1;
        }
        if(sum != -1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
