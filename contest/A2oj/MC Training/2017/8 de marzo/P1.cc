#include<bits/stdc++.h>
using namespace std;

int n, times[31], pizzas[31];
int dp[31][31];

int sol(int u, int p){
	if(u == n) return 0;
	if(dp[u][p] != -1)
		return dp[u][p];
	int res = 0;
	for(int i = u; i < n; i++){
		if(p - pizzas[i] >= 0)
			res = max(res, times[i] + sol(i + 1, p - pizzas[i]));
	}
	return dp[u][p] = res;
}

int main(){
	int p;
	while(cin >> n && n){
		cin >> p;
		for(int i = 0; i < 31; i++)
			for(int j = 0; j < 31; j++)
				dp[i][j] = -1;
		for(int i = 0; i < n; i++)
			cin >> times[i] >> pizzas[i];
		int res = sol(0, p);
		cout << res << " min." << endl;
	}
	return 0;
}