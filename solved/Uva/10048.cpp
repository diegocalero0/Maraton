#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector< vector<ii> > vvii;

vvii g(100);
vector< pair<int, ii> > edges;

int parent[100], rankk[100], fat[100];

void build_set(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rankk[i] = 0;
        g[i].clear();
    }
}

int find_(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find_(parent[x]);
}

void union_(int x, int y){
    int xroot = find_(x);
    int yroot = find_(y);

    if(rankk[xroot] > rankk[yroot]){
        parent[yroot] = xroot;
    }else{
        parent[xroot] = yroot;
        if(rankk[xroot] == rankk[yroot])
            rankk[yroot] ++;
    }
}

bool same_set(int x, int y){
    return find_(x) == find_(y);
}

void MST(){
    for(int i = 0; i < edges.size(); i++){
        pair<int, ii> v = edges[i];
        if(!same_set(v.second.first, v.second.second)){
            g[v.second.first].push_back(ii(v.first, v.second.second));
            g[v.second.second].push_back(ii(v.first, v.second.first));
            union_(v.second.first, v.second.second);
        }
    }
}

int bfs(int s, int t){
    queue<ii> q;
    int res = 0;
    q.push(ii(0, s));
    fat[s] = s;

    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(u.second == t){
            return u.first;
        }
        for(int i = 0; i < g[u.second].size(); i++){
            ii v = g[u.second][i];
            if(v.second != fat[u.second]){
                fat[v.second] = u.second;
                q.push(ii(max(u.first, v.first), v.second));
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q, s, t, w, cases = 1;
    while(cin >> n >> m >> q && (n + m + q)){
        build_set(n);
        edges.clear();
        while(m--){
            cin >> s >> t >> w;
            s--; t--;
            edges.push_back(make_pair(w, ii(s, t)));
        }
        sort(edges.begin(), edges.end());
        MST();
        if(cases != 1)
            cout << "\n";
        cout << "Case #" << cases++ << "\n";
        while(q--){
            cin >> s >> t;
            s--;
            t--;
            int res = bfs(s, t);
            if(res == -1){
                cout << "no path\n";
            }else{
                cout << res << "\n";
            }
        }
    }
    return 0;
}
