#include<bits/stdc++.h>

using namespace std;

int nodoLlegada;
int vertices;
int aristas;
int a;
int b;
int main(){
    int i;
    int j;
    int casos;
    int cont;
    cin>>casos;

    while(casos--){
        cont=0;
        int matriz[49][49];
        for(i=0;i<49;i++){
            for(j=0;j<49;j++){
                matriz[i][j]=0;
            }
        }

        cin>>nodoLlegada;
        cin>>vertices;
        cin>>aristas;

        while(aristas--){
            cin>>a;
            cin>>b;
            matriz[a][b]=1;
            matriz[b][a]=1;
        }

        for(i=0;i<49;i++){
            for(j=0;j<49;j++){
                if(matriz[i][j]==1)
                    cont++;
            }
        }
        cout<<cont<<endl;

    }

    return 0;
}
