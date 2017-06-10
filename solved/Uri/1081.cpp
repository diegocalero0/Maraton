#include<bits/stdc++.h>
using namespace std;

int m[20][20];
int visitados[20];
int v,e;
bool bandera;
void dfs(int n,int a,string b){
    int i;
    if(a!=-1){
        if(visitados[n]==0){
            cout << b << a << "-" << n << " pathR(G," << n << ")\n";
        }else{
            cout << b << a << "-" << n << "\n";
        }
    }

    if(visitados[n]==0){
        visitados[n]=1;
        for(i=0;i<v;i++){
            if(m[n][i]==1){
                bandera=false;
                dfs(i,n,b+"  ");
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c,o,d,j,cont;
    cin >> c;
    cont = 1;
    while(c--){
        cout << "Caso " << cont++ << ":\n";
        cin >> v >> e;
        memset(m , 0 , sizeof(m));
        memset(visitados , 0 , sizeof(visitados));
        while(e--){
            cin >> o >> d;
            m[o][d] = 1;
        }

        for(j=0;j<v;j++){
            if(visitados[j]==0){
                bandera=true;
                dfs(j,-1,"");
                if(!bandera){
                    cout<<"\n";
                }
            }
        }
    }

}
