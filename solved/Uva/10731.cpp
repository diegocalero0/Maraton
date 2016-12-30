#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > g(30);
vector<int> S;
int n, act[30], dfs_num[30], dfs_low[30], visited[30], dfs_cont;
priority_queue<string, deque<string>, greater<string> > res;
priority_queue<int, deque<int>, greater<int> > aux;

void addToRes(){
    string a = "";
    a += char(aux.top() + 65);
    aux.pop();

    while(!aux.empty()){
        a += " ";
        a += char(aux.top() + 65);
        aux.pop();
    }
    res.push(a);
}

void SCC(int u){
    dfs_low[u] = dfs_num[u] = dfs_cont++;
    S.push_back(u);
    visited[u] = 1;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(dfs_num[v] == -1)
            SCC(v);
        if(visited[v] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u]){
        int v;
        do{
            v = S.back(); S.pop_back();
            visited[v] = 0;
            aux.push(v);
        }while(v != u);
        addToRes();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char a, b, c, d, e, f;
    int cases = 1;
    while(cin >> n && n){
        for(int i = 0; i < 30; i++){
            g[i].clear();
            dfs_num[i] = -1;
            dfs_low[i] = -1;
            act[i] = 0;
            visited[i] = 0;
        }
        for(int i = 0; i < n; i++){
            cin >> a >> b >> c >> d >> e >> f;
            act[a - 65] = 1;
            act[b - 65] = 1;
            act[c - 65] = 1;
            act[d - 65] = 1;
            act[e - 65] = 1;
            g[f - 65].push_back(a - 65);
            g[f - 65].push_back(b - 65);
            g[f - 65].push_back(c - 65);
            g[f - 65].push_back(d - 65);
            g[f - 65].push_back(e - 65);
        }
        dfs_cont = 0;
        for(int i = 0; i < 30; i++){
            if(act[i] == 1 && dfs_num[i] == -1){
                SCC(i);
            }
        }
        if(cases++ != 1)
            cout << "\n";
        while(!res.empty()){
            cout << res.top() << "\n";
            res.pop();
        }
    }

    return 0;
}
