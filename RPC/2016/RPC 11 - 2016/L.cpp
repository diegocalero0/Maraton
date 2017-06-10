#include<bits/stdc++.h>
using namespace std;

    int contador;

    int f;
    int c;
    int m[200][200];
void bfs(int i,int j,int valor){

    if(i>=0&&i<f&&j>=0&&j<c){
        if(m[i][j]==valor&&m[i][j]!=-1){
            contador++;
            m[i][j]=-1;

            bfs(i-1,j,valor);
            bfs(i+1,j,valor);
            bfs(i,j+1,valor);
            bfs(i,j-1,valor);
        }
    }else{
        return;
    }


}

int main(){

    int i;
    int j;
    int area;
    while(cin>> f >> c){

        area=1000000;
        for(i=0;i<f;i++){
            for(j=0;j<c;j++){
                cin>>m[i][j];
            }
        }

        for(i=0;i<f;i++){
            for(j=0;j<c;j++){
                contador=0;
                bfs(i,j,m[i][j]);
                if(contador<area&&contador!=0){
                    area=contador;
                }
            }
        }

        cout<<area<<"\n";

    }

    return 0;
}
