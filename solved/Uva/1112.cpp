#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector< vector<ii> > g(100);
int T, res, dist[100], visited[100], n;
#define INF 10000000

void dijkstra(int s){
    priority_queue<ii, deque<ii>, greater<ii> > pq;
    pq.push(ii(0, s));

    for(int i = 0; i < n; i++){
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[s] = 0;
    while(!pq.empty()){
        ii curr = pq.top(); pq.pop();
        int d = curr.first; int u = curr.second;
        if(d > dist[u]) continue;
        for(int i = 0; i < g[u].size(); i++){
            ii v = g[u][i];
            if(dist[u] + v.first < dist[v.second]){
                dist[v.second] = dist[u] + v.first;
                if(dist[v.second] <= T && visited[v.second] == 0){
                    res++;
                    visited[v.second] = 1;
                }
                pq.push(ii(dist[v.second], v.second));
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k, s, t, w, dest, m;
    cin >> k;

    for(int b = 0; b < k; b++){
        res = 0;
        cin >> n >> dest >> T >> m;
        for(int i = 0; i < n; i++)
            g[i].clear();
        dest--;
        while(m--){
            cin >> s >> t >> w;
            g[--t].push_back(ii(w, --s));
        }
        dijkstra(dest);
        if(b != 0)
            cout << "\n";
        cout << res + 1<< "\n";
    }

    return 0;
}
