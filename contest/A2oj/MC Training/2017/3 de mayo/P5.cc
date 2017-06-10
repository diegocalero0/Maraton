#include<bits/stdc++.h>
using namespace std;

int f;
int chars[60];
int times[60];
int dp[1005][60];
int sol(int c, int u){

	if(u == f) return 0;
	if(dp[c][u] != -1)
		return dp[c][u];
	int res = 0;
	for(int i = u; i < f; i++){
		if(chars[i] <= c)
			res = max(res, times[i] + sol(c - chars[i], i + 1));
	}
	return dp[c][u] = res;
}

int main(){
	int numChars, t, c;
	int cases = 1;
	while(cin >> c >> f && c + f){
		for(int i = 0; i < 1005; i++)
			for(int j = 0; j < 60; j++)
				dp[i][j] = -1;
		for(int i = 0; i < f; i++){
			cin >> chars[i] >> times[i];
		}
		cout << "Teste " << cases++ << endl;
		cout << sol(c, 0) << endl;
		cout << endl;
	}
	return 0;
}