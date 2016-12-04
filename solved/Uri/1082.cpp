#include<bits/stdc++.h>

using namespace std;
int visitados[26];
int v;
int e;
char a;
char b;
int aAux;
int bAux;
int j;
string strRes;
priority_queue<int, deque<int>, greater<int> > cola;

void dfs(int matriz[][26],int nodo){
    int i;
    visitados[nodo]=1;
    cola.push(nodo);
    for(i=0;i<v;i++){
        if(i!=nodo&&visitados[i]==0&&matriz[nodo][i]==1){
            dfs(matriz,i);
        }
    }
}

void imprimirCola(){
    while(!cola.empty()){
        cout<<(char)(cola.top()+97)<<",";
        cola.pop();
    }
    cout<<endl;
}

int main(){

    int casos;
    cin>>casos;
    int caso=1;
    int i;
    int cont;
    while(casos--){
        cin>>v;
        cin>>e;
        int matriz[v][26];
        for(i=0;i<v;i++){
            for(j=0;j<v;j++){
                matriz[i][j]=0;
            }
        }
        for(i=0;i<26;i++){
            visitados[i]=0;
        }



        for(i=0;i<e;i++){
            cin>>a;
            cin>>b;
            aAux=(int)a;
            bAux=(int)b;
            //cout<<a<<" : "<<b<<endl;
            matriz[aAux-97][bAux-97]=1;
            matriz[bAux-97][aAux-97]=1;
        }

        cout<<"Case #"<<caso<<":"<<endl;
        caso++;
        cont=0;
        for(i=0;i<v;i++){
            if(visitados[i]==0){
                cont++;
                priority_queue<int, deque<int>, greater<int> > cola;
                strRes="";
                dfs(matriz,i);
                imprimirCola();
            }
        }

    cout<<cont<<" connected components"<<endl;
    cout<<endl;
    }

    return 0;
}