#include<bits/stdc++.h>
using namespace std;

int main(){


    int d, n, i, k, indice;
    char numero[100001], res[100001];
    char actual;
    while(cin >> d >> n && (d && n)){
        cin.getline(numero,100001);
        cin.getline(numero,100001);

        indice = -1;

        for(i = 0; i < d; i++){
            actual = numero[i];

            while(n > 0 && indice != -1 && res[indice] < actual){
                --n;
                --indice;
            }

            res[++indice] = actual;

        }
        indice -= n;
        res[indice + 1] = 0;
        cout << res << endl;

    }



    return 0;
}
