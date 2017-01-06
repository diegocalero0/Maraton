#include<bits/stdc++.h>
using namespace std;
int v, v0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double lng;
    double longcurr;
    int cont, res;
    while(cin >> v >> v0 && v + v0){
        lng = 0.0;
        res = -1;
        for(int i = 1; i <= v; i++){
            if(v / i >= v0){
                double V = (double) v / i;
                longcurr = 0.3d * sqrt(V - v0) * i;
                if(longcurr >= lng){
                    if(longcurr - lng < 1e-12)
                        cont++;
                    else
                        cont = 1;

                    lng = longcurr;
                    res = i;
                }
            }
        }
        if(res == -1 || cont > 1)
            cout << 0 << "\n";
        else
            cout << res << "\n";
    }

    return 0;
}
