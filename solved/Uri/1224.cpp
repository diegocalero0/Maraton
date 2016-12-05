#include<bits/stdc++.h>
using namespace std;

long long cards[10001];
long long dp[10001][10001];

int main(){

    int n, i, j;

    while(cin >> n){

        for(i = 0; i < n; i++)
            cin >> cards[i];


        for(int col = 1; col < n; col++){
            i = 0;
            j = col;

            while(j < n){
                if(j - i == 1)
                    dp[i][j] = max(cards[i], cards[j]);
                if((j - i) % 2 == 0)
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
                else
                    dp[i][j] = max(cards[i] + dp[i + 1][j], cards[j] + dp[i][j - 1]);
                i++;
                j++;
            }
        }
        cout << dp[0][n - 1] << endl;
    }
    return 0;
}
