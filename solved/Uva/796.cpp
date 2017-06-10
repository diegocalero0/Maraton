#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;


vvi g(10000);

int n, dfs_cont, dfs_num[10000], dfs_low[10000], parent[10000];
int adj[10000][10000];
void bridges(int u){
    dfs_num[u] = dfs_low[u] = dfs_cont++;
    for(int i = 0; i < g[u].size(); i++){
        if(dfs_num[g[u][i]] == -1){
            parent[g[u][i]] = u;
            bridges(g[u][i]);

            if(dfs_low[g[u][i]] > dfs_num[u]){
                adj[g[u][i]][u] = 1;
                adj[u][g[u][i]] = 1;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[g[u][i]]);
        }else if(parent[u] != g[u][i]){
            dfs_low[u] = min(dfs_low[u], dfs_num[g[u][i]]);
        }
    }

}

int main(){
    string line, tr;
    int i, j;
    while(cin >> n){
        for(i = 0; i < n; i++){
            g[i].clear();
            for(j = i + 1; j < n; j++)
                adj[i][j] = 0;
        }
        for(int k = 0; k < n; k++){
            dfs_num[k] = -1;
            dfs_low[k] = -1;
            parent[k] = -1;
            cin >> i;
            getline(cin, line);
            stringstream ss(line);
            ss >> tr;
            while(ss >> j){
                g[i].push_back(j);
            }
        }
        dfs_cont = 0;
        for(i = 0; i < n; i++){
            if(dfs_num[i] == -1){
                bridges(i);
            }
        }
        int cont = 0;
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
                if(adj[i][j] == 1)
                    cont++;
        cout << cont << " critical links" << endl;
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
                if(adj[i][j] == 1)
                    cout << i << " - " << j << endl;
        cout << endl;
    }

    return 0;
}
