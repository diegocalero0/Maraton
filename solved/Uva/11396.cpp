#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;

vvi g(300);
int v;
int seen[300];

bool bipartiteCheck(int e){
    seen[e] = 1;
    queue<int> c;
    c.push(e);
    int curr;

    while(!c.empty()){
        curr = c.front();
        c.pop();

        for(int i = 0; i < g[curr].size(); i++){
            if(seen[g[curr][i]] == -1){
                seen[g[curr][i]] = 1 - seen[curr];
                c.push(g[curr][i]);
            }else if(seen[g[curr][i]] == seen[curr])
                return false;
        }
    }
    return true;
}

int main(){
    bool bipartite;
    int s, t;
    while(cin >> v && v){
        bipartite = true;
        for(int i = 0; i < v; i++){
            seen[i] = -1;
            g[i].clear();
        }
        while(cin >> s >> t && (s + t)){
            s--;
            t--;
            g[s].push_back(t);
            g[t].push_back(s);
        }
        for(int i = 0; i < v; i++){
            if(seen[i] == -1 && !bipartiteCheck(i)){
                bipartite = false;
            }
        }

        if(!bipartite)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
