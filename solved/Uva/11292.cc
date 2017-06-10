#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, di, ki;
    while(cin >> n >> m && n + m){
        vector<int> d(n);
        vector<int> k(m);
        for(int i = 0; i < n; i++){
            cin >> d[i];
        }
        for(int i = 0; i < m; i++){
            cin >> k[i];
        }

        int gold = di = ki = 0;
        sort(d.begin(), d.end());
        sort(k.begin(), k.end());

        while(di < n && ki < m){
            while(d[di] > k[ki] && ki < m) ki++;
            if(ki == m) break;
            gold += k[ki];
            ki++, di++;
        }
        if(di == n)
            cout << gold << "\n";
        else
            cout << "Loowater is doomed!\n";
    }

    return 0;
}
