#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;

vvi g(100000);
int visited[100000], seen[100000];
int c = 0;
void dfs(int u){
    c++;
    seen[u] = 1;
    for(int i = 0; i < g[u].size(); i++){
        if(seen[g[u][i]] == -1 && visited[u] != visited[g[u][i]]){
            dfs(g[u][i]);
        }
    }
}

void solve(int u){
    visited[u] = 1;
    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i < g[curr].size(); i++){
            int v = g[curr][i];
            if(visited[v] == -1){
                visited[v] = 1 - visited[curr];
                q.push(v);
            }else if(visited[curr] == 1 && visited[v] == 1){
                visited[v] = 0;
                q.push(v);
            }
        }

    }
}

int main(){

    int n, m, s, t;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        g[i].clear();
        visited[i] = -1;
        seen[i] = -1;
    }

    while(m--){
        cin >> s >> t;
        s--; t--;
        g[s].push_back(t);
        g[t].push_back(s);
    }

    solve(0);
    dfs(0);

    if(c == n)
        for(int i = 0; i < n; i++)
            cout << visited[i] << " ";
    else
        cout << "No";
    cout << endl;
    return 0;
}
