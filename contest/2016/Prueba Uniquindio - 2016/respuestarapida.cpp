#include<bits/stdc++.h>

using namespace std;

int main(){

    int casos;
    long n;
    long result;
    cin>>casos;
    while(casos--){
        cin>>n;
        result=(int)((((((n*567)/9)+7492)*235)/47)-498);
        result=result/10;
        cout<<abs(result%10)<<endl;

    }

    return 0;
}
