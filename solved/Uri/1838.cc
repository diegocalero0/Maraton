#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<ii> t;
int dp[1100];
int n;

int sol(int u){
	if(dp[u] != 0){
		return dp[u];
	}
	int res = t[u].second - t[u].first;
	for(int i = u + 1; i < n; i++){
		if(t[i].first >= t[u].second){
			res = max(res, (t[u].second - t[u].first) + sol(i));
		}
	}
	return dp[u] = res;
}

int main(){

	cin >> n;
	int a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		t.push_back(ii(a, b));
	}
	sort(t.begin(), t.end());
	int res = sol(0);
	for(int i = 1; i < n; i++){
		res = max(res, sol(i));
	}
	cout << res << endl;
	return 0;
}