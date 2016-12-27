#include<bits/stdc++.h>
using namespace std;

int n, v, adj[100][100], alc[100][100], visited[100];

void dfs(int u){
    visited[u] = 1;
    alc[v][u] = 0;
    for(int i = 0; i < n; i++){
        if(adj[u][i] == 1 && visited[i] == 0 && i != v){
            dfs(i);
        }
    }
}

void dfs2(int u){
    alc[v][u] = 1;
    visited[u] = 1;
    for(int i = 0; i < n; i++){
        if(adj[u][i] == 1 && visited[i] == 0){
            dfs2(i);
        }
    }
}

void desCheck(){
    for(int i = 0; i < n; i++)
        visited[i] = 0;
}

void print(){
    cout << "+";
    for(int i = 0; i < 2 * n - 1; i++)
        cout << "-";
    cout << "+\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ca = 1, t;
    cin >> t;

    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                alc[i][j] = 0;
                cin >> adj[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            desCheck();
            v = i;
            dfs2(i);
        }

        for(int i = 1; i < n; i++){
            desCheck();
            v = i;
            dfs(0);
        }

        cout << "Case " << ca++ <<":\n";
        print();

        for(int i = 0; i < n; i++){
            cout << "|";
            for(int j = 0; j < n; j++){
                if(alc[i][j] == 1 && alc[0][j] == 1)
                    cout << "Y|";
                else
                    cout << "N|";
            }
            cout << "\n";
            print();
        }
    }

    return 0;
}
