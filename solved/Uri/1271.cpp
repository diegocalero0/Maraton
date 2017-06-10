#include<bits/stdc++.h>
using namespace std;

int posiciones[50001];
int indices[50001];
int main(){

    int n, r, i, j, q, c = 0, aux;

    while(cin >> n && n){

        cout << "Genome " << ++c << endl;

        for(i = 1; i <= n; i++){
            posiciones[i] = i;
            indices[i] = i;
        }

        cin >> r;
        while(r--){
            cin >> i >> j;

            while(i < j){
                aux = posiciones[i];
                posiciones[i] = posiciones[j];
                posiciones[j] = aux;

                indices[ posiciones[j] ] = j;
                indices[ posiciones[i] ] = i;

                i++;
                j--;
            }

        }

        cin >> q;
        while(q--){
            cin >> aux;
            cout << indices[aux] << endl;
        }


    }

    return 0;
}
