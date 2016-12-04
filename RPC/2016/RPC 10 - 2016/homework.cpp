#include<bits/stdc++.h>
using namespace std;

int main(){
    int c;
    long s;
    double res;
    long res2;
    cin>>c;
    while(c--){
        cin>>s;
        res=(double)(-3+sqrt(9-4*(2-2*(s))))/(double)2;
        res2=(double)(-3+sqrt(9-4*(2-2*(s))))/(double)2;
        if(res2-res==0){
            cout<<res<<endl;
        }else{
            cout<<"No solution"<<endl;
        }

    }

    return 0;
}
