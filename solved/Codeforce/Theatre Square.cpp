#include<bits/stdc++.h>

using namespace std;

int main(){

    long n;
    long m;
    long a;
    cin>>n;
    cin>>m;
    cin>>a;
    long long res=ceil((double)n/(double)a)*ceil((double)m/(double)a);
    cout<<res<<endl;

    return 0;
}
