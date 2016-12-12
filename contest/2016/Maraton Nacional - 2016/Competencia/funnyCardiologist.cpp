#include<bits/stdc++.h>
using namespace std;

int x[256];
int y[256];
double dp[256][256];
int n;
double total = INT_MAX;

double dist(int x1, int y1, int x2, int y2){
    return sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) );
}

double distanciaTotal(){
    double distancia = 0;
    for(int i = 0; i < n - 1; i++){
        distancia += dist(x[i], y[i], x[i + 1], y[i + 1]);
    }
    return distancia;
}

double minimo(int p, int k){
    double minValue = total;
    if(p == n - 1){
        dp[p][k] = 0;
        return 0;
    }

    if(dp[p][k] != -1)
        return dp[p][k];

    for(int i = 1; p + i < n; i++){
        int t = p + i;
        if(k - ( t - (p + 1)) >= 0)
            minValue = min( minimo(t, k - (t - (p + 1))) + dist(x[p], y[p], x[t], y[t]), minValue);
    }
    dp[p][k] = minValue;
    return minValue;
}

int main(){

    int k, xi, yi, i, j;
    double result;
    double total;
    while(cin >> n >> k){
        for(i = 0; i < 256; i++){
            for(j = 0; j < 256; j++){
                dp[i][j] = -1;
            }
        }

        int t = n;
        i = 0;
        while(t--){
            cin >> xi >> yi;
            x[i] = xi;
            y[i++] = yi;
        }


        total = distanciaTotal();
        result = minimo(0, k);
        printf("%.3f\n", result);

    }

    return 0;
}
