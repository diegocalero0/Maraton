#include<bits/stdc++.h>

using namespace std;

int rondas(int i,int j,int c){
    if(i==j)
        return c;
    else{
        if(i%2!=0)
            i++;
        if(j%2!=0)
            j++;
        return rondas(i,j,c+1);
    }
}

int main(){

    int n;
    int i;
    int j;
    int res;
    while(cin >> n >> i >> j){
        res=rondas(i,j,0);
        cout<<res<<"\n";
    }
    return 0;
}
