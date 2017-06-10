#include<bits/stdc++.h>
using namespace std;
struct nodo{int n;int c;};
vector<int> factP;
int i;
int j;
int primos[1001];
int visitados[1001];
int bfs(nodo a,int b){
    queue<nodo> cola;
    nodo aux;
    nodo n;

    cola.push(a);

    while(!cola.empty()){
        aux=cola.front();
        cola.pop();
        if(aux.n==b)
            return aux.c;
        for(i=aux.n-1;i>=2;i--){
            if(primos[i]==0&&aux.n%i==0&&visitados[aux.n+i]==0&&aux.n+i<=b){
                visitados[aux.n+i]=1;
                n={aux.n+i,aux.c+1};
                cola.push(n);
            }
        }

    }
    return -1;
}

void criba(){
    for(i=2;i<1001;i++){
        if(primos[i]==0){
            primos[i]=0;
            for(j=i+i;j<=1001;j+=i){
                primos[j]=1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(i=0;i<1001;i++){
        visitados[i]=0;
        primos[i]=0;
    }
    criba();
    int a;
    int b;
    int res;
    int cont=1;
    while(cin >> a >> b && a!=0 && b!= 0){

        for(i=0;i<1001;i++){
            visitados[i]=0;
        }

        cout<<"Case "<<cont++<<": ";

        if(a>b){
            cout<<-1<<"\n";
            continue;
        }else{

            nodo n={a,0};
            res=bfs(n,b);
            cout<<res<<"\n";

        }


    }

    return 0;
}
