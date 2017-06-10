#include<bits/stdc++.h>
using namespace std;

int g[20][20];
int n, dfs_num[20];
map<string, int> ma1;
map<int, string> ma2;
priority_queue< string, deque<string>, greater<string> > res;

void backtraking(int u, string S){
    S += ma2[u];
    dfs_num[u] = 1;
    for(int i = 0; i < n; i++)
        if(dfs_num[i] != -1 && g[u][i] == 1){
            dfs_num[u] = -1;
            return;
        }
    if(S.length() == n){
        res.push(S);
    }else{
        for(int i = 0; i < n; i++){
            if(dfs_num[i] == -1 && (g[u][i] == 1 || (g[u][i] == 0 && g[i][u] == 0)))
                backtraking(i, S);
        }
    }
    dfs_num[u] = -1;
}

int main(){
    string line, aux, s, t;
    int inMap;
    int ca = 0;
    while(getline(cin, line)){
        if(ca++ != 0)
            cout << endl;
        inMap = 0;
        ma1.clear();
        ma2.clear();

        stringstream ss(line);
        while(ss >> aux){
            ma1[aux] = inMap;
            ma2[inMap++] = aux;
        }
        n = inMap;
        for(int i = 0; i < n; i++){
            dfs_num[i] = -1;
            for(int j = 0; j < n; j++)
                g[i][j] = 0;
        }
        getline(cin, line);
        stringstream ss2(line);
        while(ss2 >> s >> t){
            g[ma1[s]][ma1[t]] = 1;
        }

        for(int i = 0; i < n; i++)
            backtraking(i, "");

        while(!res.empty()){
            cout << res.top() << endl;
            res.pop();
        }
    }
}
