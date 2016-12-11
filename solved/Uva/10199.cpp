#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
vvi g(100);
int n, dfs_num[100], dfs_low[100], parent[100], art_point[100], dfs_cont, rootChildren, dfs_root;

void articulationPoints(int u){
    dfs_num[u] = dfs_low[u] = dfs_cont++;
    for(int i = 0; i < g[u].size(); i++){
        if(dfs_num[g[u][i]] == -1){
            parent[g[u][i]] = u;
            if(u == dfs_root)
                rootChildren++;
            articulationPoints(g[u][i]);
            if(dfs_low[g[u][i]] >= dfs_num[u] && u != dfs_root)
                art_point[u] = 1;
            dfs_low[u] = min(dfs_low[u], dfs_low[g[u][i]]);
        }else if(g[u][i] != parent[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[g[u][i]]);
        }
    }
}

int main(){
    int ca = 1, m;
    string s, t;
    while(cin >> n && n){
        if(ca > 1){
            cout << endl;
        }
        priority_queue< string, deque<string>, greater<string> > res;
        map<int, string> ma1;
        map<string, int> ma2;
        for(int i = 0; i < n; i++){
            g[i].clear();
            art_point[i] = 0;
            parent[i] = 0;
            dfs_num[i] = -1;
            dfs_low[i] = -1;
            cin >> s;
            ma1[i] = s;
            ma2[s] = i;
        }

        cin >> m;

        while(m--){
            cin >> s >> t;
            g[ma2[s]].push_back(ma2[t]);
            g[ma2[t]].push_back(ma2[s]);
        }

        for(int i = 0; i < n; i++){
            dfs_cont = 0;
            if(dfs_num[i] == -1){
                dfs_root = i; rootChildren = 0;
                articulationPoints(i);
                if(rootChildren > 1){
                    art_point[i] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++)
            if(art_point[i] == 1)
                res.push(ma1[i]);

        cout << "City map #" << ca++ << ": " << res.size() << " camera(s) found" << endl;
        while(!res.empty()){
            cout << res.top() << endl;
            res.pop();
        }
    }
    return 0;
}
