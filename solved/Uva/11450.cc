#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > vvi;
vvi v(20);
int m, c;
int dp[205][25];
int solution(int money, int u){
	if(money < 0) return -10000000;
	if(dp[money][u] != -1) return dp[money][u];
	if(u == c) return m - money;

	int res = -1;
	for(int i = 0; i < v[u].size(); i++){
		res = max(res, solution(money - v[u][i] , u + 1));
	}
	return dp[money][u] = res;
}


int main(){

	int n, k, curr;
	cin >> n;

	while(n--){
		cin >> m >> c;
		for(int i = 0; i < c; i++){
			cin >> k;
			v[i].clear();
			for(int j = 0; j < k; j++){
				cin >> curr;
				v[i].push_back(curr);
			}
		}
		memset(dp, -1,sizeof dp);
		int sol = solution(m, 0);
		if(sol < 0)
			cout << "no solution\n";
		else
			cout << sol << endl;
	}

	return  0;
}