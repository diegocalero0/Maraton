#include<bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > vvi;
typedef pair<int, int> ii;
vvi g(1000);
int n, dfs_num[1000], dfs_low[1000], dfs_cont, parent[1000], adjm[1000][1000];

void dfs2(int u){
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(adjm[u][v] != 0){
            if(adjm[u][v] == 2){
                adjm[u][v] = 0;
                adjm[v][u] = 0;
                cout << u + 1 << " " << v + 1 << "\n";
                cout << v + 1 << " " << u + 1<< "\n";
                dfs2(v);
            }else if(adjm[u][v] == 1){
                adjm[u][v] = 0;
                adjm[v][u] = 0;
                cout << u + 1 << " " << v + 1 << "\n";
                dfs2(v);
            }
        }
    }
}

void dfs(int u){
    dfs_low[u] = dfs_num[u] = dfs_cont++;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(dfs_num[v] == -1){
            parent[v] = u;
            dfs(v);
            if(dfs_low[v] > dfs_num[u]){
                adjm[u][v] = 2;
                adjm[v][u] = 2;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if(v != parent[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, s, t, ca = 1;

    while(cin >> n >> m && n + m){
        dfs_cont = 0;
        for(int i = 0; i < n; i++){
            dfs_low[i] = -1;
            dfs_num[i] = -1;
            g[i].clear();
            for(int j = 0; j < n; j++)
                adjm[i][j] = 0;
        }
        while(m--){
            cin >> s >> t;
            s--; t--;
            g[s].push_back(t);
            g[t].push_back(s);
            adjm[s][t] = 1;
            adjm[t][s] = 1;
        }
        dfs(0);
        cout << ca++ << "\n\n";
        dfs2(0);
        cout << "#\n";
    }

    return 0;
}
