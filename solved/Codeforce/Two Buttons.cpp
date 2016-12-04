#include<bits/stdc++.h>

using namespace std;

long proceso(int n,int m,long c){
    if(n==m){
        return c;
    }else{
        if(n<m){
            if(m%2==0){
                proceso(n,m/2,c+1);
            }else{
                proceso(n,(m+1)/2,c+2);
            }
        }else{
            proceso(n-1,m,c+1);
        }
    }
}

int main(){

    long n;
    long m;

    cin>>n;
    cin>>m;

    long res=proceso(n,m,0);
    cout<<res<<endl;
    return 0;
}
