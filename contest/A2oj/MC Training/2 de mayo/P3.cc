#include<bits/stdc++.h>
using namespace std;

int adj[260][260], dist[260];
int n, c;
void floydwharshall(){
	for(int k = c; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				adj[i][j] = adj[j][i] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main(){

	int m, k, u, v, p;

	while(cin >> n >> m >> c >> k && (n + n + c + k)){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = 9999999;
		while(m--){
			cin >> u >> v >> p;
			adj[u][v] = adj[v][u] = p;
		}
		dist[c - 1] = 0;
		for(int i = c - 2; i >= 0; i--)
			dist[i] = dist[i + 1] + adj[i][i + 1];
		floydwharshall();
		int result = adj[k][c-1];
		for(int i = 0; i < c - 1; i++)
			result = min(result, adj[k][i] + dist[i]);
		cout << result << endl;
	}

	return 0;
}