#include<bits/stdc++.h>
using namespace std;

int n, times[100], score[100];
int dp[101][601];

int dpmet(int u, int t){
    int maxi = 0;
    if(dp[u][t] != -1)
        return dp[u][t];
    for(int i = 0; i < n; i++){
        if(times[i] <= t)
            maxi = max(maxi, score[i] + dpmet(i, t - times[i]));
    }
    return dp[u][t] = maxi;
}

int main(){
    int t, k = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n >> t && n){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= t; j++){
                dp[i][j] = -1;
            }
        }
        for(int i = 0; i < n; i++){
            cin >> times[i] >> score[i];
        }
        cout << "Instancia " << k++ << "\n";
        cout << dpmet(0, t) << "\n\n";
    }

    return 0;
}
