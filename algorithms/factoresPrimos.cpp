#include<bits/stdc++.h>
using namespace std;

vector<int> factPrimos;

void factoresPrimos(int n){
    int i;
    while(n%2==0){
        factPrimos.push_back(2);
        n=n/2;
    }
    for(i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            factPrimos.push_back(i);
            n=n/i;
        }
    }
    if(n>2)
        factPrimos.push_back(n);
}

int main(){
    int i;
    factoresPrimos(10058654);
    for(i=0;i<factPrimos.size();i++)
        cout<<factPrimos[i]<<" ";
    cout<<endl;
    return 0;
}
