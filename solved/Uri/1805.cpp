#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    long long p;
    cin>>n;
    cin>>p;
    long long sum1=((n-1)*(n))/2;
    long long sum2=(p*(p+1))/2;
    cout<<sum2-sum1<<endl;

return 0;
}