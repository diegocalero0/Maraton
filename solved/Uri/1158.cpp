#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    int i;
    cin>>n;
    long x;
    long y;
    long long result;
    while(n--){
        result=0;
        cin>>x;
        cin>>y;
        if(x%2==0){
            x++;
        }
        while(y--){
            result+=x;
            x+=2;
        }
        cout<<result<<endl;


    }

    return 0;
}