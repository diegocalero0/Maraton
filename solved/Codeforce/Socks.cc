#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
typedef vector< vector<int> > vvi;

vvi g(200000);
int seen[200000];
map<int, int> timeColors[200000];

int colors[200000];
int maxC, diffColors, res, sol;
int run = 0;
void paint(int u){
	seen[u] = 1;
	timeColors[run][colors[u]]++;
	res++;
	maxC = max(maxC, timeColors[run][colors[u]]);
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(!seen[v])
			paint(v);
	}

}

int main(){

	int n, m, k, curr, u, v;
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++)
		seen[i] = 0;

	for(int i = 0; i < n; i++){
		cin >> colors[i];
		colors[i]--;
	}

	while(m--){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	for(int i = 0; i < n; i++){
		maxC = 0;
		diffColors = 0;
		res = 0;
		
		if(!seen[i]){
			paint(i);
			sol += (res - maxC);
			run++;
		}
	}

	cout << sol << endl;

	return 0;
}