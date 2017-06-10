#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > g(101);
int seen[101];
int n;

bool isBipartite(int e){
    seen[e] = 1;
    queue<int> c;
    c.push(e);
    int aux;
    while(!c.empty()){
        aux = c.front();
        c.pop();

        for(int i = 0; i < g[aux].size(); i++){
            if(seen[g[aux][i]] == -1){
                seen[g[aux][i]] = 1 - seen[aux];
                c.push(g[aux][i]);
            }else if(seen[g[aux][i]] == seen[aux]){
                return false;
            }
        }

    }

    return true;
}

int main(){

    int id;
    int f;
    string line;
    bool flag;
    while(cin >> n && n){
        flag = true;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            seen[i] = -1;
            cin >> id;
            cin.ignore();
            getline(cin, line);
            stringstream l(line);
            while(l >> f){
                g[id].push_back(f);
                g[f].push_back(id);
            }
        }

        for(int i = 1; i <= n; i++){
            if(seen[i] == - 1 && !isBipartite(i)){
                flag = false;
                break;
            }

        }

        if(flag)
            cout << "SIM" << endl;
        else
            cout << "NAO" << endl;

    }

    return 0;
}
