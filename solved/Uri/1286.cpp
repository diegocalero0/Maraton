#include<bits/stdc++.h>
using namespace std;

int pizzas[20];
int tiempos[20];
int dp[21][31];
int n;

int maximoTiempo(int o, int p){
    int maximo = 0;
    if(o == n)
        return 0;
    if(dp[o][p] != 0)
        return dp[o][p];
    for(int i = o; i < n; i++){
        if(pizzas[i] <= p)
            maximo = max( maximoTiempo(i + 1, p - pizzas[i]) + tiempos[i], maximo);
    }

    dp[o][p] = maximo;
    return maximo;

}

int main(){

    int maxTime;
    int p;
    while(cin >> n && n != 0){
        cin >> p;

        for(int i = 0; i < 21; i++){
            for(int j = 0; j < 31; j++){
                dp[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            cin >> tiempos[i];
            cin >> pizzas[i];
        }

        maxTime = maximoTiempo(0, p);
        cout << maxTime << " min." << endl;
    }

    return 0;

}
