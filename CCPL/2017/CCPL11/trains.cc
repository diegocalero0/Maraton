#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

typedef pair<int, int> ii;
typedef vector< vector<ii> > vvii;

const int N = 200;


vvii ga(N);
vvii gb(N);

int matria[N][N]; int matrib[N][N];
int n;

int disjtra(double a){
	vector<double> dist(n, INF);
	dist[0] = 0.0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, 0));

	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d > dist[u]) continue;

		for(int j = 0; j < ga[u].size(); j++){
			ii v = ga[u][j];

			double cost = 0.0;

			if(matrib[u][v.first] != -1){
				cost = a * double(v.second) + (1.0 - a) * double(matrib[u][v.first]);
			}else{
				cost = v.second;
			}

			if(dist[u] + cost < dist[v.first]){
				dist[v.first] = dist[u] + cost;
				pq.push(ii(cost, v.first));
			}

		}

		for(int j = 0; j < gb[u].size(); j++){
			ii v = gb[u][j];

			double cost = 0.0;

			if(matria[u][v.first] != -1){
				cost = (1.0 - a) * double(v.second) + a * double(matria[u][v.first]);
			}else{
				cost = v.second;
			}

			if(dist[u] + cost < dist[v.first]){
				dist[v.first] = dist[u] + cost;
				pq.push(ii(cost, v.first));
			}
		}

	}

	return dist[n - 1];
}

int main(){

	int ma, mb, k;
	int u, v, w;
	double a;
	while(cin >> n >> ma >> mb >> k && n != -1 && ma != -1 && mb != -1 && k != -1){
		
		for(int i = 0; i < n; i++){
			ga[i].clear();
			gb[i].clear();
			for(int j = 0; j < n; j++){
				matria[i][j] = matrib[i][j] = -1;
			}
		}
		while(ma--){
			cin >> u >> v >> w;
			matria[u][v] = matria[v][u] = w;
			ga[u].push_back(ii(v, w));
			ga[v].push_back(ii(u, w));
		}

		while(mb--){
			cin >> u >> v >> w;
			matrib[u][v] = matrib[v][u] = w;
			gb[u].push_back(ii(v, w));
			gb[v].push_back(ii(u, w));
		}

		for(int i = 0; i < k; i++){
			cin >> a;
			cout << int(disjtra(a)) << endl;
		}

	}


	return 0;
}