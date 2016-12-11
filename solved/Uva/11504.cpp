#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
vvi g(100000);
int seen[100000], dfs_low[100000], dfs_num[100000], n, m, dfs_count, visited[100000], nulled[100000];
vector<int> S;

int parent[100000], rango[100000];
int num_scc;
void make_set(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rango[i] = 0;
    }

}

int find_(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find_(parent[x]);
}

bool same_component(int x, int y){
    if(find_(x) == find_(y)){
        return true;
    }
    return false;
}

void union_(int x, int y){
    int xroot = find_(x);
    int yroot = find_(y);
    if(rango[xroot] > rango[yroot]){
        parent[yroot] = xroot;
    }else{
        parent[xroot] = yroot;
        if(rango[xroot] == rango[yroot])
            rango[yroot]++;
    }
}

void SCC(int u){
    dfs_low[u] = dfs_num[u] = dfs_count++;
    seen[u] = 1;
    S.push_back(u);
    for(int i = 0; i < g[u].size(); i++){
        if(dfs_num[g[u][i]] == -1)
            SCC(g[u][i]);
        if(seen[g[u][i]] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[g[u][i]]);
    }


    if(dfs_low[u] == dfs_num[u]){
        num_scc++;
        while(u != S.back()){
            union_(S.back(), u);
            seen[S.back()] = -1;
            S.pop_back();
        }
        seen[S.back()] = -1;
        S.pop_back();
    }
}

void dfs(int u){
    visited[u] = 1;
    for(int i = 0; i < g[u].size(); i++){
        if(!same_component(u, g[u][i]) && nulled[find_(g[u][i])] == -1){
                num_scc--;
                nulled[find_(g[u][i])] = 1;
        }
        if(visited[g[u][i]] == -1){
            dfs(g[u][i]);
        }
    }
}

int main(){

    int t, s, r;
    cin >> t;

    while(t--){
        cin >> n >> m;
        make_set(n);
        S.clear();
        for(int i = 0; i < n; i++){
            seen[i] = -1;
            dfs_num[i] = -1;
            dfs_low[i] = -1;
            visited[i] = -1;
            nulled[i] = -1;
            g[i].clear();
        }

        while(m--){
            cin >> s >> r;
            s--;
            r--;
            g[s].push_back(r);
        }

        num_scc = 0;
        dfs_count = 0;
        for(int i = 0; i < n; i++){
            if(dfs_num[i] == -1)
                SCC(i);
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == -1)
                dfs(i);
        }
        cout << num_scc << endl;
    }

    return 0;
}
