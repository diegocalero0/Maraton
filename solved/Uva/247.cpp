#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;

int n, m, dfs_num[25], dfs_low[25], visited[25], dfs_cont, ca = 1;
vector<int> S;
map<string, int> ma1;
map<int, string> ma2;
vvi g(25);

void SCC(int u){
    dfs_low[u] = dfs_num[u] = dfs_cont++;
    visited[u] = 1;
    S.push_back(u);

    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(dfs_num[v] == -1)
            SCC(v);
        if(visited[v] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_num[u] == dfs_low[u]){
        while(1){
            int v = S.back(); S.pop_back();
            visited[v] = -1;
            cout << ma2[v];
            if(u == v) break;
            cout << ", ";
        }
        cout << endl;
    }

}

int main(){

    int inMap, si, ti;
    string s, t;
    while(cin >> n >> m && (n + m)){
        if(ca > 1)
            cout << endl;
        inMap = 0;
        ma1.clear();
        ma2.clear();
        S.clear();
        for(int i = 0; i < n; i++){
            dfs_low[i] = -1;
            dfs_num[i] = -1;
            visited[i] = -1;
            g[i].clear();
        }

        inMap = 0;
        while(m--){
            cin >> s >> t;
            if(ma1.find(s) == ma1.end()){
                si = inMap;
                ma1[s] = inMap;
                ma2[inMap++] = s;
            }else{
                si = ma1[s];
            }
            if(ma1.find(t) == ma1.end()){
                ti = inMap;
                ma1[t] = inMap;
                ma2[inMap++] = t;
            }else{
                ti = ma1[t];
            }
            g[si].push_back(ti);
        }
        dfs_cont = 0;
        cout << "Calling circles for data set " << ca++ << ":" << endl;
        for(int i = 0; i < n; i++){
            if(dfs_num[i] == -1){
                SCC(i);
            }
        }

    }
    return 0;
}
