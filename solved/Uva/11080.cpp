#include<bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > vvi;

vvi g(200);
int v, e, dfs_num[200], cont[2];

bool bipartiteCheck(int u){
    queue<int> q;
    dfs_num[u] = 1;
    cont[1] ++;
    q.push(u);

    while(!q.empty()){
        int curr = q.front(); q.pop();

        for(int i = 0; i < g[curr].size(); i++){
            if(dfs_num[g[curr][i]] == -1){
                cont[1 - dfs_num[curr]]++;
                dfs_num[g[curr][i]] = 1 - dfs_num[curr];
                q.push(g[curr][i]);
            }else if(dfs_num[g[curr][i]] == dfs_num[curr]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k, s, t;
    cin >> k;
    bool bipartite;
    while(k--){
        bipartite = true;
        cin >> v >> e;
        for(int i = 0; i < v; i++){
            g[i].clear();
            dfs_num[i] = -1;
        }
        while(e--){
            cin >> s >> t;
            g[s].push_back(t);
            g[t].push_back(s);
        }
        int res = 0;
        for(int i = 0; i < v; i++){
            cont[0] = 0;
            cont[1] = 0;
            if(dfs_num[i] == -1 && !bipartiteCheck(i)){
                bipartite = false;
                break;
            }
            if(cont[0] == 0 || cont[1] == 0)
                res += max(cont[0], cont[1]);
            else
                res += min(cont[0], cont[1]);
        }
        if(bipartite){
            cout << res << "\n";
        }else{
            cout << -1 << "\n";
        }
    }

    return 0;
}
