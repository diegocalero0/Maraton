#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, pos, amigos, f, gastado, ganancia[10];
    string nombres[10], nombre;
    map<string, int> mapa;
    int k = 0;
    while(cin >> n){

        if(k != 0){
            cout << endl;
        }else{
            k++;
        }

        for(int i = 0; i < n; i++){
            ganancia[i] = 0;
            cin >> nombres[i];
            mapa[nombres[i]] = i;
        }

        for(int i = 0; i < n; i++){
            cin >> nombre;
            cin >> gastado;
            cin >> amigos;
            pos = mapa[nombre];
            f = amigos;
            if(amigos != 0)
                ganancia[pos] -= ((int)(gastado / amigos)) * amigos;

            while(f--){
                cin >> nombre;
                pos = mapa[nombre];
                ganancia[pos] += (int)(gastado / amigos);
            }
        }

        for(int i = 0; i < n; i++){
            cout << nombres[i] << " " << ganancia[i] << endl;
        }
    }

    return 0;
}
