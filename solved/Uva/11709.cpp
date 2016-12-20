#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > g(1000);
vector<int> S;
int dfs_num[1000], dfs_low[1000], dfs_cont, visited[1000], SCC;

void dfs(int u){
    dfs_low[u] = dfs_num[u] = dfs_cont++;
    visited[u] = 1;
    S.push_back(u);
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(dfs_num[v] == -1)
            dfs(v);
        if(visited[v] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        SCC++;
        while(1){
            int v = S.back(); S.pop_back();
            visited[v] = -1;
            if(v == u)
                break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int p, t, im, v, w;
    string s, f;
    map<string, int> ma;
    while(cin >> p >> t && (p + t)){
        ma.clear();
        for(int i = 0; i < p; i++){
            g[i].clear();
            dfs_num[i] = -1;
            dfs_low[i] = -1;
            visited[i] = -1;
            cin >> s >> f;
            ma[s + f] = i;
        }

        while(t--){
            cin >> s >> f;
            v = ma[s + f];
            cin >> s >> f;
            w = ma[s + f];
            g[v].push_back(w);
        }
        dfs_cont = 0;
        SCC = 0;
        for(int i = 0; i < p; i++){
            if(dfs_num[i] == -1)
                dfs(i);
        }
        cout << SCC << endl;
    }

    return 0;
}
