#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    int m;
    int area;
    cin>>n;
    cin>>m;
    area=n*m;
    if(area%2==0){
        cout<<area/2<<endl;
    }else{
        cout<<(area-1)/2<<endl;
    }

    return 0;
}
