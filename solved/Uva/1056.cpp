#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int n, r, adjMat[50][50];

void floydWarshall(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                adjMat[j][i] = adjMat[i][j];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int inMap, n1, n2, ca = 1;
    string name1, name2;
    map<string, int> ma;
    while(cin >> n >> r && (n + r)){
        inMap = 0;
        ma.clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adjMat[i][j] = INF;
            }
        }
        while(r--){
            cin >> name1 >> name2;
            if(ma.find(name1) == ma.end()){
                n1 = inMap;
                ma[name1] = inMap++;
            }else{
                n1 = ma[name1];
            }
            if(ma.find(name2) == ma.end()){
                n2 = inMap;
                ma[name2] = inMap++;
            }else{
                n2 = ma[name2];
            }
            adjMat[n1][n2] = 1;
            adjMat[n2][n1] = 1;
        }
        floydWarshall();
        bool connected = true;
        int res = -1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(i != j && adjMat[i][j] == INF){
                    connected = false;
                    break;
                }else if(i != j){
                    res = max(res, adjMat[i][j]);
                }
            }
        }
        cout << "Network " << ca++ << ": ";
        if(connected)
            cout << res << "\n\n";
        else
            cout << "DISCONNECTED\n\n";

    }
    return 0;
}
