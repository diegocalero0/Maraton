#include<stdio.h>
#include<string>
#include<iostream>
#include<deque>
using namespace std;

const int N = 2005;

int arr[N];
int dp[N][N];

int main(){

    int n, res;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = 0;

    for(int i = 0; i < n; i++)
        dp[i][1] = arr[i] * n;

    int j;
    for(j = 2; j <= n; j++){
        for(int i = 0; i + j - 1 < n; i++){
            dp[i][j] = max(arr[i] * (n - j + 1) + dp[i + 1][j - 1], arr[i + j - 1] * (n - j + 1) + dp[i][j - 1]);
        }
    }


    cout << dp[0][n] << endl;
    return 0;
}
