#include<bits/stdc++.h>

using namespace std;

int tresNMasUno(int n){
    int c=0;

    while(n!=1){
        if(n%2==0){
            n=n/2;
        }else{
            n=(3*n)+1;
        }
        c++;
    }
    return c+1;
}

int main(){

    int a;
    int b;
    int i;
    int aAux;
    int bAux;
    int mejor;
    int aux;
    while(cin>>a>>b){
        aAux=a;
        bAux=b;
        mejor=-1000;

        if(a>b){
            i=b;
            b=a;
            a=i;
        }

        for(i=a;i<=b;i++){
            aux=tresNMasUno(i);
            if(aux>mejor){
                mejor=aux;
            }
        }
        cout<<aAux<<" "<<bAux<<" "<<mejor<<endl;
    }




}
