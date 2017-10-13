#include<bits/stdc++.h>
using namespace std;

int s[260];
int balls[260];
int dp[260][260];
int n, b;
int sol(int u, int sum){
	if(u == -1)
		return 0;
	int res = 10000000;
	if(dp[u][sum] == -1)
		return dp[u][sum];
	for(int i = 0; i < n; i++){
		if(i < sum)
			res = min(res, ((s[(u + i)%n] + s[(u + i + 1)%n]) * balls[u]) + sol(u - 1, i));
	}
	return dp[u][sum] = res;
}

int main(){
	while(cin >> n >> b && (n + b)){
			for(int i = 0; i < n; i++)
				cin >> s[i];
			for(int i = 0; i < b; i++)
				cin >> balls[i];
			for(int i = 0; i < 260; i++)
				for(int j = 0; j < 260; j++)
					dp[i][j] = -1;
			int res = sol(b - 1, n + 5);
			
		cout << -res << endl;
	}
	return 0;
}