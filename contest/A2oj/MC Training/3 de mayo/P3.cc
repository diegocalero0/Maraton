#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main(){

	int n, m, a, b, x, y;
	cin >> n >> m >> a >> b;
	vector<int> gr(n, 0);
	vector< vector<int> > graph(n);
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		x--, y--;
		gr[x]++;
		gr[y]++;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	set<ii> p;
	for(int i = 0; i < n; i++){
		p.insert(ii(gr[i], i));
	}

	while(1){
		ii mini = p.begin();
		ii maxi = p.end();

		if(mini.first < a){
			for(int i = 0; i < graph[mini.second].size(); i++){
				int v = graph[mini.second][i];
				gr[v]--;
			}
		}
	}

	return 0;
}