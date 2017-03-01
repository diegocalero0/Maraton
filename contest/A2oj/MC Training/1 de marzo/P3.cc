#include<bits/stdc++.h>
using namespace std;
#define INF 200
typedef vector< vector<int> > vvi;

vvi g(500);
vector<int> vi(500);
int ages[500], pos[500], minAges[500],k;
bool visited[500];
int bt(int u){
	visited[u] = 1;
	int res = 200;
	int temp;
	vi[u] = k;
	for(int i = 0; i < g[u].size(); i++){
		if(vi[g[u][i]] < k){
			temp = min(ages[g[u][i]], bt(g[u][i]));
			res = min(res, temp);
		}
	}
	visited[u] = 0;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, q, s, t;
	char f;

	while(cin >> n >> m >> q){
		for(int i = 0; i < n; i++){
			cin >> ages[i];
			pos[i] = i;
			visited[i] = false;
			vi[i] = -1;
			g[i].clear();
		}
		while(m--){
			cin >> s >> t;
			s--; t--;
			g[t].push_back(s);
		}
		k = -1;
		while(q--){
			k++;
			cin >> f;
			if(f == 'T'){
				cin >> s >> t;
				s--; t--;
				swap(ages[pos[s]], ages[pos[t]]);
				swap(pos[s], pos[t]);
			}else{
				cin >> s;
				s--;
				int res;
				if(g[pos[s]].size() != 0){
					res = bt(pos[s]);
					cout << res << endl;
				}else{
					cout << "*" << endl;
				}
			}
		}
	}
	return 0;
}
