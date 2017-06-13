#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;


int r, c, result;
int dp[30][30][4];
bool seen[30][30];
bool valid(int i, int j){
	if(i >= 0 && i < r && j >= 0 && j < c && !seen[i][j])
		return true;
	return false;
}

long long numberOfPaths(int m, int n){
    long long count[m][n];
 
    for (int i = 0; i < m; i++)
        count[i][0] = 1;
 
    for (int j = 0; j < n; j++)
        count[0][j] = 1;
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++)
            count[i][j] = count[i-1][j] + count[i][j-1];
 
    }
    return count[m-1][n-1];
}


int main(){

	int t;
	cin >> t;
	while(t--){
		result = 0;
		cin >> r >> c;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				seen[i][j] = false;
				for(int k = 0; k < 4; k++){
					dp[i][j][k] = -1;
				}
			}
		}
	
    cout << numberOfPaths(r, c) << endl;
	}

	return 0;
}