#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef pair<int, int> ii;

vector< vector<ii> > g(20000);
int n;

int dijkstra(int s, int t){
    vector<int> dist(n, INF);
    priority_queue<ii, deque<ii>, greater<ii> > pq;
    pq.push(ii(0, s));
    dist[s] = 0;

    while(!pq.empty()){
        ii curr = pq.top(); pq.pop();
        int d = curr.first; int u = curr.second;
        if(d > dist[u]) continue;
        for(int i = 0; i < g[u].size(); i++){
            ii v = g[u][i];
            if(dist[u] + v.first < dist[v.second]){
                dist[v.second] = dist[u] + v.first;
                pq.push(ii(dist[v.second], v.second));
            }
        }
    }
    return dist[t];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, res, s, t, w, m, a, b;
    cin >> N;
    for(int c = 1; c <= N; c++){
        cin >> n >> m >> s >> t;
        for(int i = 0; i < n; i++)
            g[i].clear();
        while(m--){
            cin >> a >> b >> w;
            g[a].push_back(ii(w, b));
            g[b].push_back(ii(w, a));
        }
        res = dijkstra(s, t);
        cout << "Case #" << c << ": ";
        if(res != INF)
            cout << res << "\n";
        else
            cout << "unreachable\n";
    }
    return 0;
}
