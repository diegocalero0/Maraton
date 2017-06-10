#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int suma;
    int aux;
    int anterior;
    while(n--){
        suma=0;
        aux=-1;
        while(aux!=0){
            if(aux==-1){
                cin>>aux;
                anterior=aux;
            }else{
                cin>>aux;
                if(aux>2*anterior){
                    suma+=(aux-(anterior*2));
                }
                anterior=aux;
            }
        }
    cout<<suma<<endl;
    }

    return 0;
}
