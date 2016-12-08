#include<bits/stdc++.h>
using namespace std;

int r, c, q;
vector< vector<int> > ady(10000);
int dfs_num[10000], dfs_low[10000],dfs_parent[10000], dfsCounter;
int p[10000];

inline int findset(int v) {
    if (p[v] != -1 && p[v] != v)
        return p[v] = findset(p[v]);
    return v;
}

inline int unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a<b) swap(a,b);
    p[b] = a;
}

void bridge(int u){
    dfs_low[u] = dfs_num[u] = dfsCounter++;
    for(int i = 0; i < ady[u].size(); i++){
        if(dfs_num[ady[u][i]] == -1){
            dfs_parent[ady[u][i]] = u;
            bridge(ady[u][i]);

            if(dfs_low[ady[u][i]] > dfs_num[u])
                unionset(u, ady[u][i]);
            dfs_low[u] = min(dfs_low[u], dfs_low[ady[u][i]]);
        }else if(ady[u][i] != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[ady[u][i]]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, s;

    while(cin >> r >> c >> q && (r && c && q)){

        for(int i = 0; i < r; i++){
            ady[i].clear();
            p[i] = -1;
            dfs_num[i] = -1;
            dfs_low[i] = -1;
        }


        while(c--){
            cin >> t >> s;
            t--;
            s--;
            ady[t].push_back(s);
            ady[s].push_back(t);
        }

        for(int i = 0; i < r; i++){
            if(dfs_num[i] == -1){
                bridge(i);
            }
        }

        while(q--){
            cin >> t >> s;
            t--;
            s--;

            if(findset(t) == findset(s))
                cout << "Y\n";
            else
                cout << "N\n";

        }

        cout << "-\n";

    }

    return 0;
}
