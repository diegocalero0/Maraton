#include<bits/stdc++.h>
using namespace std;

int blocks[25];
int dp[25][1000001];
int n;


int minBlocks(int m){

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            if(blocks[i] <= j)
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - blocks[i]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n - 1][m];

}

int main(){

    int t, m;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> m;

        for(int i = 0; i <= m; i++){
            dp[0][i] = i;
        }

        for(int i = 0; i < n; i++){
            cin >> blocks[i];
        }

        sort(blocks, blocks + n);
        int result = minBlocks(m);
        cout << result << endl;
    }

    return 0;
}
