#include<bits/stdc++.h>
using namespace std;

int sol(int n, int k){
    if(n == 1)
        return 1;
    return (sol(n - 1, k) + k - 1) % n + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, nc;
    cin >> nc;
    for(int cases = 1; cases <= nc; cases++){
        cin >> n >> k;
        cout << "Case " << cases << ": " << sol(n, k) << "\n";
    }
    return 0;
}
