#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases, t, d, k, acc, i;
    long long res, curr, c[21];
    cin >> cases;

    while(cases--){
        cin >> t; t++;
        acc = 0;
        for(i = 0; i < t; i++){
            cin >> c[i];
        }
        cin >> d >> k;
        i = 1;
        while(acc < k){
            acc += i * d;
            i++;
        }
        i--;
        res = 0;
        curr = 1;
        for(long j = 0; j < t; j++){
            res += c[j] * curr;
            curr *= i;
        }
        cout << res << "\n";
    }

    return 0;
}
