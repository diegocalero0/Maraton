#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int primos[MAX];

void criba(){
    int i;
    int j;
    for(i=2;i<MAX;i++){
        if(primos[i]==0){
            for(j=i+i;j<=MAX;j+=i){
                primos[j]=1;
            }
        }
    }
}

int main(){
    memset(primos,0,sizeof(primos));
    criba();
    for(int i=2;i<MAX;i++){
        if(primos[i]==0)
            cout<<i<<"\t";
    }
    cout<<"\n";
    return 0;

}
