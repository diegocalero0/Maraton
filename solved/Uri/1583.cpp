#include<bits/stdc++.h>

using namespace std;
int m;
int n;
char matriz[10000][10000];

void floodFill(int i,int j){
    if(i<0||j<0||i==m||j==n){
        return;
    }
    if(matriz[i][j]=='X'||matriz[i][j]=='T'){
        return;
    }
    matriz[i][j]='T';
    floodFill(i+1,j);
    floodFill(i-1,j);
    floodFill(i,j+1);
    floodFill(i,j-1);

}

int main(){
    int i;
    int j;
    string aux;
    while(true){
        cin>>m>>n;
        if(m==0&&n==0){
            break;
        }
        cin.getline(matriz[0],n+1);
        for(i=0;i<m;i++){
            cin.getline(matriz[i],n+1);
        }

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matriz[i][j]=='T'){
                    matriz[i][j]='A';
                    floodFill(i,j);
                }
            }
        }

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cout<<matriz[i][j];
            }
            cout<<endl;
        }
        cout<<endl;

    }


    return 0;
}
