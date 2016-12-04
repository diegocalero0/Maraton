#include<bits/stdc++.h>

using namespace std;

int main(){


int n;
double res;
int i;
while(cin>>n){
    res=1;
    for(i=1;i<n;i++){
        res*=(double)(365-i)/(double)365;
    }

    printf("%.6f\n",abs(1-res));

}

}
