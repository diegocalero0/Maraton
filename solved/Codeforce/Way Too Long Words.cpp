#include<bits/stdc++.h>

using namespace std;

int main(){

    long n;
    cin>>n;
    string a;
    long longitud;
    while(n--){
        cin>>a;
        longitud=a.length();
        if(a.length()>10){
            cout<<a.at(0)<<(longitud-2)<<a.at(longitud-1)<<endl;
        }else{
            cout<<a<<endl;
        }
    }

    return 0;
}
