#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
vvi g(10000);
int n, compAdj[10000], dfs_num[10000], dfs_low[10000], parent[10000], dfs_cont = 0, rootChildren = 0;

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        if(n1.first != n2.first){
            return n1.first < n2.first;
        }else{
            return n1.second > n2.second;
        }
    }
};

void articulationPoints(int u){
    dfs_num[u] = dfs_low[u] = dfs_cont++;
    for(int i = 0; i < g[u].size(); i++){
        if(dfs_num[g[u][i]] == -1){
            parent[g[u][i]] = u;
            if(u == 0) rootChildren++;

            articulationPoints(g[u][i]);

            if(dfs_low[g[u][i]] >= dfs_num[u]){
                compAdj[u]++;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[g[u][i]]);
        }else if(parent[u] != g[u][i]){
            dfs_low[u] = min(dfs_low[u], dfs_num[g[u][i]]);
        }
    }
}

int main(){

    int m, s, t;
    while(cin >> n >> m && (n + m)){
        for(int i = 0; i < n; i++){
            g[i].clear();
            dfs_num[i] = -1;
            parent[i] = -1;
            compAdj[i] = 1;
        }

        while(cin >> s >> t && s != -1 && t != -1){
            g[s].push_back(t);
            g[t].push_back(s);
        }

        rootChildren = 0;
        dfs_cont = 0;
        articulationPoints(0);
        compAdj[0] = rootChildren;
        priority_queue< pair<int, int>, deque< pair<int, int> >, CompareDist > res;
        for(int i = 0; i < n; i++){
            res.push(make_pair(compAdj[i], i));
        }

        while(m--){
            pair<int, int> aux = res.top();
            res.pop();
            cout << aux.second << " " << aux.first << endl;
        }
        cout << endl;
    }
    return 0;
}
