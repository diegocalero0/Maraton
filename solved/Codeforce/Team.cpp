#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int cont=0;
    int aux;
    int a;
    int i;
    while(n--){
        aux=0;
        for(i=0;i<3;i++){
            cin>>a;
            if(a==1){
                aux++;
            }
        }
        if(aux>=2){
            cont++;
        }
    }

    cout<<cont<<endl;
    return 0;
}
