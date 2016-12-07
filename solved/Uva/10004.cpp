#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > g(200);
int col[200];
int n, l;
bool bipartiteCheck(int u){
    queue<int> c;
    col[u] = 0;
    c.push(u);
    int aux;

    while(!c.empty()){
        aux = c.front(); c.pop();
        for(int i = 0; i < g[aux].size(); i++){
            if(col[g[aux][i]] == -1){
                col[g[aux][i]] = 1 - col[aux];
                c.push(g[aux][i]);
            }else if(col[g[aux][i]] == col[aux]){
                return false;
            }
        }
    }
    return true;
}

int main(){

    int s, t;
    bool pos;
    while(cin >> n && n){
        pos = true;
        cin >> l;

        for(int i = 0; i < n; i++){
            g[i].clear();
            col[i] = -1;
        }


        for(int i = 0; i < l; i++){
            cin >> s >> t;
            g[s].push_back(t);
            g[t].push_back(s);
        }

        if(!bipartiteCheck(0)){
            pos = false;
        }
        if(pos)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }

    return 0;
}
