#include<bits/stdc++.h>

using namespace std;

int matriz[8][8];
int movimiento[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
struct nodo{
        int fila;
        int columna;
        int cont;
    };

int bfs(nodo inicial,nodo llegada){
    int i;
    queue<nodo> cola;
    cola.push(inicial);
    matriz[inicial.fila][inicial.columna]=1;
    nodo auxiliar;
    while(!cola.empty()){
        auxiliar=cola.front();
        if(auxiliar.fila==llegada.fila&&auxiliar.columna==llegada.columna){
            return auxiliar.cont;
        }
        cola.pop();
        for(i=0;i<8;i++){
            if(auxiliar.fila+movimiento[i][0]>=0&&auxiliar.fila+movimiento[i][0]<=7
               &&auxiliar.columna+movimiento[i][1]>=0&&auxiliar.columna+movimiento[i][1]<=7){
                if(matriz[auxiliar.fila+movimiento[i][0]][auxiliar.columna+movimiento[i][1]]==0){
                    matriz[auxiliar.fila+movimiento[i][0]][auxiliar.columna+movimiento[i][1]]=1;
                    nodo nuevo={auxiliar.fila+movimiento[i][0],auxiliar.columna+movimiento[i][1],auxiliar.cont+1};
                    cola.push(nuevo);
                }
            }
        }

    }
}

int main(){
    int i;
    int j;

    string aux1;
    string aux2;
    int fila;
    int columna;
    int resultado;
    while(cin>>aux1>>aux2){

        fila=((int)aux1.at(0))-97;
        columna=(int)aux1.at(1)-49;
        nodo inicial={fila,columna,0};

        fila=((int)aux2.at(0))-97;
        columna=(int)aux2.at(1)-49;
        nodo llegada={fila,columna,0};

        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                matriz[i][j]=0;
            }
        }
        resultado=bfs(inicial,llegada);
        cout<<"To get from "<<aux1<<" to "<<aux2<<" takes "<<resultado<<" knight moves."<<endl;
    }
    return 0;
}