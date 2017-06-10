#include<bits/stdc++.h>
using namespace std;

int main(){
    string pass, aux;
    map<string, int> ma;

    cin >> pass;
    for(int i = 0; i < 10; i++){
        cin >> aux;
        ma[aux] = i;
    }

    int cont = 0;
    aux = "";
    for(int i = 0; i < 80; i++){
        cont++;
        aux += pass[i];
        if(cont == 10){
            cout << ma[aux];
            aux = "";
            cont = 0;
        }
    }
    cout << endl;
    return 0;
}
