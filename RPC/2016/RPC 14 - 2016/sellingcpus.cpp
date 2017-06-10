#include<bits/stdc++.h>
using namespace std;

int matriz[100][100];
int dp[101][101];
int m;
int c;
long maximo(int cpu, int com){
    int i;
    if( cpu == 0 || com == m){
        return 0;
    }

    if(dp[com][cpu] != -1){
        return dp[com][cpu];
    }
    long maxActual = 0;

    maxActual = max( maximo(cpu , com + 1), maxActual);

    for(i = 1; i <= cpu; i++){
        maxActual = max(maximo( cpu - i, com + 1) + matriz[com][i - 1], maxActual);
    }

    dp[com][cpu] = maxActual;
    return maxActual;
}

int main(){

    cin >> c >> m;
    int i, j;

    for(i = 0; i < m;i++){
        for(j=0;j < c;j++){
            cin >> matriz[i][j];
        }
    }

    for(i = 0; i <= m;i++){
        for(j = 0;j <= c;j++){
            dp[i][j] = -1;
        }
    }
    long result = maximo(c, 0);
    cout<<result<<endl;

}
