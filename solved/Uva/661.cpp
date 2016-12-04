#include<bits/stdc++.h>
using namespace std;

int main(){

    int m, n, c, s = 1;
    bool estado[20];
    int amp[20];
    int ampActual;
    int maximo;
    int operacion;
    bool fallo;
    while(cin >> n >> m >> c && (m && n && c)){
        maximo = 0;
        fallo = false;
        ampActual = 0;
        for(int i = 0; i < n; i++){
            estado[i] = 0;
            cin >> amp[i];
        }

        while(m--){
            cin >> operacion;
            operacion--;

            if(estado[operacion]){
                ampActual -= amp[operacion];
            }else{
                ampActual += amp[operacion];
            }

            if(ampActual > c) fallo = true;
            maximo = max(ampActual, maximo);
            estado[operacion] = !estado[operacion];
        }


        cout << "Sequence " << s++ << endl;
        if(fallo){
            cout << "Fuse was blown." << endl;
        }else{
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << maximo << " amperes." << endl;
        }

        cout << endl;

    }

    return 0;
}
