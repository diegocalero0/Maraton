#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    int m;

    cin>>n;
    cin>>m;
    int a;
    int b;

    int menor=1;
    int indices[n+1];
    while(m--){
        cin>>a;
        cin>>b;

        indices[a]=1000;
        indices[b]=1000;
        int aux=menor;
        while(indices[aux]==1000){
            aux++;
        }
        menor=aux;
    }
    int aux=1;
    cout<<n-1<<endl;
    while(n--){
        if(aux!=menor)
            cout<<menor<<" "<<aux<<endl;
        aux++;
    }
    return 0;
}
