#include<bits/stdc++.h>

using namespace std;

int primos[100000];
int precalculados[100000];
void criba(){
    int i;
    int j;
    for(i=2;i<=100000;i++){
        if(primos[i]==0){
            primos[i]=i-1;
            for(j=i+i;j<=100000;j+=i){
                if(primos[j]==0){
                    primos[j]=j;
                }
                primos[j]*=(double)((double)(i-1)/(double)i);
            }
        }

    }
}

int main(){

    int casos;
    int n;
    int result;

    memset(primos,100000,0);
    cin>>casos;
    int l=1;
    int res;
    int k;
    criba();
    while(casos--){
        cin>>n;
        cout<<primos[n]<<endl;

    }

    return 0;
}
