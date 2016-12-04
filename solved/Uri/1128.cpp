#include<bits/stdc++.h>
using namespace std;

int adyacencias[2000][2000];
int visitados[2000];
int n;
int dfs(int nodo){
    for(int i = 0; i < n; i++){
            visitados[i] = 0;
    }
    int prof = 0;
    queue<int> cola;
    visitados[nodo] = 1;
    cola.push(nodo);
    int curr;
    while(!cola.empty()){
        curr = cola.front();
        cola.pop();
        for(int i = 0; i < n; i++){
            if(adyacencias[curr][i] == 1 && visitados[i] == 0){
                visitados[i] = 1;
                cola.push(i);
                prof++;
            }

        }
    }

    return prof;

}

int main(){


    int m, v, w, p, prof;
    bool conexion;
    while(cin >> n >> m && n && m){

        conexion = true;
        for(int i = 0; i < n; i++){
            visitados[i] = 0;
            for(int j = 0; j < n; j++){
                adyacencias[i][j] = 0;
            }
        }

        while(m--){
            cin >> v;
            cin >> w;
            cin >> p;

            adyacencias[v - 1][w - 1] = 1;
            if(p == 2)
                adyacencias[w - 1][v - 1] = 1;
        }

        for(int i = 0; i < n; i++){
            if(dfs(i) < n - 1){
                conexion = false;
                break;
            }
        }

        if(conexion)
            cout << 1 << endl;
        else
            cout << 0 << endl;

    }

    return 0;
}
